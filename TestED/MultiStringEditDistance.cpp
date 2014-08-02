//
//  MultiStringEditDistance.cpp
//  TestED
//
//  Created by Young on 07-26－此月第4周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "MultiStringEditDistance.h"

MultiStringEditDistance::MultiStringEditDistance(vector<BehaviorObjVector> source)
{
    //initiate
    _source=source;
    long length=source.size();
    _alignedStrings= new string[length];
    _lenArray= vector<long>(source.size()+1);
    _lenArray[0]=1;
    for(int i=0; i!=source.size(); i++)
    {
        _lenArray[i+1]=source[i].size()+1;//add 0 at the begining of strings
    }
    
    _lenProdArray=vector<long> (_lenArray.size());
    genLenProdArray(_lenProdArray, _lenArray, _lenArray.size());
    
    _editDistanceMatrix= vector< EditDistanceStatus >(_lenProdArray[_lenProdArray.size()-1],EditDistanceStatus(0,-1));
    _visitOrder= vector< vector<long> > (_lenProdArray[_lenProdArray.size()-1], vector<long>(source.size()));
    long end=_lenProdArray[_lenProdArray.size()-1]-1;
    long dimension=source.size();
    generateVisitOrder(_lenArray, _visitOrder, dimension, 0, end);
    
    for(long i=0; i < _visitOrder.size(); i++)
    {
        cout<<i<<":";
        for(long j=0; j < _visitOrder[i].size(); j++)
        {
            cout<<_visitOrder[i][j]<<" ";
        }
        cout<<endl;
    }

    generateEditDistanceMatrix();
    backTrace();
}

/*
Method: getCurrentStepChr
Aim: Get the current char element for each dimension
vector<long> indexArray: refer to the current location
vector<BehaviorObj> &stepChrs: result
 
*/
void MultiStringEditDistance::getCurrentStepChr(vector<long> indexArray, vector<BehaviorObj> &stepChrs)
{
    for (int i=0; i< indexArray.size(); i++)
    {
        if ((int)indexArray[i] != 0)
        {
            int currentDimensionCharIndex= (int)indexArray[i];
            //shift one element because of extra "0" at the begin of each dimension in our matrix
            stepChrs.push_back(_source[i].getIndex(currentDimensionCharIndex-1));
        }
        else
        {
            BehaviorObj beginElement= BehaviorObj("0","0");
            stepChrs.push_back(beginElement);
        }
    }
}

void MultiStringEditDistance::generateEditDistanceMatrix()
{
    //EditDistanceStatus init= EditDistanceStatus(0,-1);
    //_editDistanceMatrix[0]=init;
   
    for (long i=1; i<_visitOrder.size(); i++)
    {
        vector<long> currentStep= _visitOrder[i];
        double minLoc[2]={0,0};//minloc[0]= minIndex, minloc[1]= minValue
        long currentLoc= getLocation(_lenProdArray, currentStep);
        
        vector<BehaviorObj> currentStepChrs;
        getCurrentStepChr(currentStep,currentStepChrs);
        list< list<long> > pairs;
        findPairs(currentStepChrs,pairs);
        vector<long> preStepLocs;
        getPreStepLocs(preStepLocs,pairs,currentStep,_lenProdArray);
        vector<long> preStepLoc;
        
        list<long> usedIndexesForMin;
        list<long> unUsedIndexesForMin;
        list<list<long> > usedIndexesPairs;
       
        MinPreStep(_editDistanceMatrix, preStepLocs, currentStep, _lenProdArray, currentStepChrs, minLoc,usedIndexesForMin,unUsedIndexesForMin);
        findUsedIndexesPairs(currentStepChrs, usedIndexesPairs, usedIndexesForMin);
        EditDistanceStatus currentStatus=EditDistanceStatus(minLoc[1], pairs,usedIndexesPairs, unUsedIndexesForMin, currentStepChrs, minLoc[0]);
        _editDistanceMatrix[currentLoc]= currentStatus;
    }
}

void MultiStringEditDistance::backTrace()
{
    long currentStep= _editDistanceMatrix.size() - 1;
    long preStep=_editDistanceMatrix[currentStep].getPreStep();
    while(preStep!=-1)
    {
        vector<BehaviorObj> currentStepChrs=_editDistanceMatrix[currentStep].getCurrentStepChrs();
        list< list<long> > currentUsedIndexesPairs=_editDistanceMatrix[currentStep].getUsedIndexesPairs();
        list<long> currentUnUsedIndexes=_editDistanceMatrix[currentStep].getUnUsedIndexes();
        bool containZero=false;
        list< list<long> >::iterator iterA;
        list<long>::iterator iterB;
        
        for(iterA= currentUsedIndexesPairs.begin(); iterA != currentUsedIndexesPairs.end();iterA++)
        {
            for(iterB= (*iterA).begin(); iterB!= (*iterA).end();iterB++)
            {
                if(currentStepChrs[(*iterB)].getBehaviorName()=="0")
                    containZero=true;
            }
        }
        long numInsertChars=currentUsedIndexesPairs.size()-(containZero?1:0);
        long insertLoc=0;
        bool isInsertChar=false;
       
        for(iterB= currentUnUsedIndexes.begin(); iterB!= currentUnUsedIndexes.end();iterB++)
        {
            long indexOfDimension= *(iterB);
            _alignedStrings[indexOfDimension]='_'+_alignedStrings[indexOfDimension];
        }
        
        for(iterA= currentUsedIndexesPairs.begin(); iterA!= currentUsedIndexesPairs.end(); iterA++)
        {
            for(iterB=(*iterA).begin(); iterB != (*iterA).end(); iterB++)
            {
                long indexOfDimension= *(iterB);
                string currentChars = currentStepChrs[indexOfDimension].getBehaviorName();
                if(currentStepChrs[indexOfDimension].getBehaviorName()=="0")
                {
                    for(long i=0; i<numInsertChars; i++)
                    {
                        _alignedStrings[indexOfDimension]='_'+_alignedStrings[indexOfDimension];
                    }
                }
                else
                {
                    for(long i=0; i<numInsertChars; i++)
                    {
                        if(i == insertLoc)
                        {
                            _alignedStrings[indexOfDimension]=currentChars+_alignedStrings[indexOfDimension];
                            isInsertChar=true;
                        }
                        else
                            _alignedStrings[indexOfDimension]='_'+_alignedStrings[indexOfDimension];
                    }
                }
            }
            if(isInsertChar)
                insertLoc++;
        }
        
        currentStep=preStep;
        preStep=_editDistanceMatrix[currentStep].getPreStep();
    }
}

void MultiStringEditDistance::printAlignedStrings()
{
    cout<<"alignedString: "<<endl;
    long size= _source.size();
    for(int i=0; i != size;i++)
    {
        cout<<_alignedStrings[i]<<endl;
    }
}

void MultiStringEditDistance::printEditDistanceMatrix()
{
    for(int i=0; i<_visitOrder.size();i++)
    {
        if(i%3==0)
            cout<<endl;
        vector<long> currentStep= _visitOrder[i];
        long currentLoc= getLocation(_lenProdArray, currentStep);
        cout<<_editDistanceMatrix[currentLoc].getValueInMatrix()<<" ";
        
    }
    
    for(int i=0; i<_visitOrder.size();i++)
    {
        if(i%3==0)
            cout<<endl;
        vector<long> currentStep= _visitOrder[i];
        long currentLoc= getLocation(_lenProdArray, currentStep);
        cout<<_editDistanceMatrix[currentLoc].getPreStep()<<" ";
        
    }
    cout<<endl;
}

