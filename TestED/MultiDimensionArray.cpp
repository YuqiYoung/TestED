//
//  MultiDimensionArray.cpp
//  TestED
//
//  Created by Young on 07-22－此月第4周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "MultiDimensionArray.h"

long calLenProdArray(vector<long> &lenProdArray, const vector<long> &lenArray, long n)
{
    if(n==0)
    {
        lenProdArray[0]=lenArray[0];
        return lenArray[0];
    }
    lenProdArray[n]=lenArray[n]*calLenProdArray(lenProdArray,lenArray, n-1);
    return lenProdArray[n];
}

long getLocation(const vector<long> lenProdArray, const vector<long> indexArray)
{
    long loc=0;
    for(unsigned int i=0;i<indexArray.size();i++)
    {
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

void combination(long n, long start, long end, vector< vector<long> > &preStepVec, const vector<long> indexArray)
{
    if(n==0)
        return;
    long mid=(start+end)/2;
    for(long i=start; i <= mid; i++)
    {
            preStepVec[i][n-1]= indexArray[n-1] - 1; //[i-1]
    }
    for(long i=mid+1; i <= end; i++)
    {
        preStepVec[i][n-1]= indexArray[n-1]; //[i]
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

int getCostValue(const vector<long> original, const vector<long> preStep)
{
    int cost=0;
    for(int i=0;i<original.size();i++)
    {
        if(original[i] - preStep[i]==0)
            cost++;
    }
    return cost;
}

long MinPreStep(const vector<long> dMatrix, const vector< vector<long> > &preStepVec,const vector<long> lenProdArray)
{
    //vector<long> current= preStepVec[preStepVec.size()-1];
    long minLoc= getLocation(lenProdArray, preStepVec[0]);
    for(long i=1; i< preStepVec.size()-1; i++)
    {
        long loc= getLocation(lenProdArray, preStepVec[i]);
        if(dMatrix[loc] < dMatrix[minLoc])
        {
            minLoc=loc;
        }
    }
    return minLoc;
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
            visitOrder[j][lenArray.size()-1-dimension]=i;
        generateVisitOrder(lenArray, visitOrder, dimension-1, newStart, newEnd);
    }
}