//
//  MultiDimensionArray.cpp
//  TestED
//
//  Created by Young on 07-22－此月第4周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "MultiDimensionArray.h"

long genLenProdArray(vector<long> &lenProdArray, const vector<long> &lenArray, long n)
{
    if(n==0)
    {
        lenProdArray[0]=lenArray[0];
        return lenArray[0];
    }
    lenProdArray[n]=lenArray[n]*genLenProdArray(lenProdArray,lenArray, n-1);
    return lenProdArray[n];
}


long getLocation(const vector<long> lenProdArray, const vector<long> indexArray)
{
    long loc=0;
    for(unsigned int i=0;i<indexArray.size();i++)
    {
        if(indexArray[i] == -1)
            return -1;//if the loc is -1 that means it meets a boundary
        loc=loc+indexArray[i]*lenProdArray[i];
    }
    return loc;
}


void getIndexArray(const vector<long> lenProdArray,vector<long> &indexArray,const long loc)//lenProdArray['s length: n+1,
{
    long max_n= indexArray.size();
    indexArray[0]=loc%lenProdArray[1]/lenProdArray[0];
    for(unsigned int i=1; i<max_n; i++)
    {
        indexArray[i]=loc;
        for(unsigned int j=0;j<i;j++)
        {
            indexArray[i]=indexArray[i]-indexArray[j]*lenProdArray[j];
        }
        indexArray[i]=indexArray[i]%lenProdArray[i+1]/lenProdArray[i];
        //cout<<indexArray[i];
    }
}

//it is possible that the previous step is out of the boundary
void combination(long n, long start, long end, vector< vector<long> > &preStepVec, const vector<long> indexArray)
{
    if(n==0)
        return;
    long mid=(start+end)/2;
    for(long i=start; i <= mid; i++)
    {
        long temp= indexArray[n-1];
        preStepVec[i][n-1]= temp; //[i]

    }
    for(long i=mid+1; i <= end; i++)
    {
        preStepVec[i][n-1]= indexArray[n-1] - 1; //[i-1] goto the previous step
    }
    combination(n-1, 0, mid, preStepVec, indexArray);
    combination(n-1, mid+1, end, preStepVec, indexArray);
}

void getPreviousStep(vector< vector<long> > &preStepVec, const vector<long> indexArray)
{
    long length= (long)pow(2,indexArray.size());
    combination(indexArray.size(), 0, length-1, preStepVec, indexArray);
    //vector< vector<long> > preStepVec(indexArray.size(), vector<long>(length));
    //return preStepVec;
}


void getOptiPreviousStep(vector< vector<long> > &preStepVec, list< list<long> > &pairs, const vector<long> indexArray)
{
    long level= 1;
    long numLeaf= 2;
    long size= preStepVec.size();
    long partion= size/numLeaf;
    list< list<long> >::iterator iter;
    for(iter= pairs.begin(); iter!= pairs.end(); iter++)
    {
        long i=0;
        while(i!=numLeaf)
        {
            long start=0+i*partion;
            long end=(i+1)*partion;
            for(long j=start; j< end; j++)
            {
                if((i%2)==0)
                {
                    for(list<long>::iterator iter2=(*iter).begin();iter2!=(*iter).end(); iter2++)
                    {
                        long index=*iter2;
                        long currentCoor=indexArray[index];
                        preStepVec[j][index]= currentCoor;
                    }
                }
                else
                {
                    for(list<long>::iterator iter2=(*iter).begin();iter2!=(*iter).end(); iter2++)
                    {
                        long index=*iter2;
                        preStepVec[j][index]= indexArray[index]-1;
                    }
                }
            }
            i++;
        }
        level++;
        numLeaf=pow(2, level);
        partion= size/numLeaf;
    }
    
    if(pairs.size()!=1)
    {
        preStepVec.pop_back();
    }
}

void getPreStepLocs(vector<long> &preStepLocs, list< list<long> > &pairs, const vector<long> indexArray,vector<long> lenProdArray)
{
    long length_pow= (long)pow(2,pairs.size());
    vector< vector<long> > preStepVec(length_pow, vector<long>(indexArray.size()));
    getOptiPreviousStep(preStepVec,pairs,indexArray);
//    long length_pow= (long)pow(2,indexArray.size());
//    vector< vector<long> > preStepVec(length_pow, vector<long>(indexArray.size()));
//    getPreviousStep(preStepVec,indexArray);
    for(long i=0;i<preStepVec.size();i++)
    {
        long loc= getLocation(lenProdArray,preStepVec[i]);
        if(loc!=-1)
        {
            preStepLocs.push_back(loc);
        }
    }

}
long getCostValue(const vector<long> original, const vector<long> preStep,vector<BehaviorObj> &currentStepChr)
{
    int cost=0;
    for(int i=0;i<original.size();i++)
    {
        //eg. original: (x+1 , y+1, z+1), preStep: (x, y+1, z) then the cost = 1
        if((original[i] - preStep[i])==0)
            cost++;
    }
    
    // original: (x+1 , y+1, z+1), preStep: (x, y, z) diagonal situation
//    if(cost==0)
//    {
//        cost=(int)findPairs(currentStepChr).size()-1;
//    }
    return cost;
}

//minloc[0]= minIndex, minloc[1]= minValue
void MinPreStep(vector<EditDistanceStatus> dMatrix, const vector<long> &preStepLocs , const vector<long> &currentStep,const vector<long> &lenProdArray, vector<BehaviorObj> &currentStepChr, double *minLoc)
{
    vector<long> preStep(currentStep.size());
    minLoc[0]=preStepLocs[1];//preStepLocs[0] is the current step location
    getIndexArray(lenProdArray, preStep, minLoc[0]);
    double base= dMatrix[minLoc[0]].getValueInMatrix();
    long cost= getCostValue(currentStep, preStep, currentStepChr);
    minLoc[1]= base+ cost;
    
    for(int i=2;i<preStepLocs.size();i++)
    {
        getIndexArray(lenProdArray, preStep, preStepLocs[i]);
        double temp= dMatrix[preStepLocs[i]].getValueInMatrix() + getCostValue(currentStep, preStep, currentStepChr);
        if(temp < minLoc[1])
        {
            minLoc[0]=preStepLocs[i];
            minLoc[1]=temp;
        }
    }






//
//    //vector<long> current= preStepVec[preStepVec.size()-1];
//    long index=0;
//    long count=0;
//    minLoc[0]= getLocation(lenProdArray, preStepVec[index]);
//    
//    while(minLoc[0] == -1 )
//    {
//        count++;
//        index++;
//        minLoc[0]= getLocation(lenProdArray, preStepVec[index]);
//       
//    }
//    minLoc[1] = dMatrix[minLoc[0]]+ getCostValue(preStepVec[preStepVec.size()-1], preStepVec[index], currentStepChr);
//    
//    for(long i=index+1; i < preStepVec.size()-1; i++)//except the original one
//    {
//        long loc= getLocation(lenProdArray, preStepVec[i]);
//        if(loc != -1)
//        {
//            long currentValue= dMatrix[loc] + getCostValue(preStepVec[preStepVec.size()-1], preStepVec[i], currentStepChr);
//
//            if(currentValue <  minLoc[1])
//            {
//                minLoc[0]=loc;
//                minLoc[1]=currentValue;
//            }
//        }
//        else
//        {
//            count++;
//        }
//    }
//    
//    if(count == preStepVec.size()-1)// meet the origin（0,0....0,0）
//    {
//        minLoc[0]=0;
//        minLoc[1]=0;
//    }
}

void generateVisitOrder(const vector<long> lenArray, vector< vector<long> > &visitOrder, long dimension, long start, long end)
{
    long lenPartion=(end-start+1)/lenArray[dimension];
    if(dimension==0)
    {
        return;
    }
    for(long i=0; i<lenArray[dimension]; i++)
    {
        long newStart=start+i*lenPartion;
        long newEnd=newStart+lenPartion-1;
        for(long j=newStart; j<=newEnd; j++)
            visitOrder[j][dimension-1]=i;
        generateVisitOrder(lenArray, visitOrder, dimension-1, newStart, newEnd);
    }
}

void findPairs(vector<BehaviorObj> currentStepChr,list< list<long> > &pairs)
{
    vector<int> isVisited = vector<int>(currentStepChr.size());
    vector<int> temp= vector<int>(currentStepChr.size());
    temp[0]=0;
    
    for(int i=1; i< currentStepChr.size();i++)
    {
        string opt= currentStepChr[i].getBehaviorName();
        temp[i]=i;
        for(int j=i-1; j >=0; j--)
        {
            if(opt==currentStepChr[j].getBehaviorName())
            {
                temp[i]=j;
                break;
            }
        }
    }
    
//    for(int i=0; i<temp.size();i++)
//    {
//        cout<<temp[i]<<" ";
//    }
//    cout<<endl;
    for(int i=int(currentStepChr.size())-1;i >= 0;i--)
    {
        if(isVisited[i]==0)
        {
            list<long> onePair;
            int currentVisit=i;
            int nextVisit= temp[i];
            onePair.push_front(i);
            isVisited[currentVisit]=1;
            while(nextVisit!=currentVisit)
            {
                currentVisit=nextVisit;
                isVisited[currentVisit]=1;
                onePair.push_front(currentVisit);
                nextVisit=temp[currentVisit];
            }
            pairs.push_front(onePair);
        }
    }
}

list<long> findLongestPair(list< list<long> > pairs)
{
    list<long> longestPair=*pairs.begin();
    list<list<long> >::iterator iter=pairs.begin();
    while(iter!= pairs.end())
    {
        if(longestPair.size()< (*iter).size())
        {
            longestPair=(*iter);
        }
        iter++;
    }
    return longestPair;
}
