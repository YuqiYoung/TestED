//
//  MultiDimensionArray.cpp
//  TestED
//
//  Created by Young on 07-22－此月第4周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "MultiDimensionArray.h"
unsigned long calLenProdArray(vector<unsigned long> &lenProdArray, vector<unsigned long> &lenArray, unsigned long n)
{
    if(n==0)
    {
        lenProdArray[0]=lenArray[0];
        return lenArray[0];
    }
    lenProdArray[n]=lenArray[n]*calLenProdArray(lenProdArray,lenArray, n-1);
    return lenProdArray[n];
}

unsigned long getLocation(vector<unsigned long> &lenProdArray, vector<unsigned long>  &indexArray)
{
    unsigned long loc=0;
    for(unsigned int i=0;i<indexArray.size();i++)
    {
        loc=loc+indexArray[i]*lenProdArray[i];
    }
    return loc;
}


void getIndexArray(const vector<unsigned long> lenProdArray,vector<unsigned long> &indexArray,const unsigned long loc)//lenProdArray['s length: n+1,
{
    unsigned long max_n= indexArray.size();
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

void combination(unsigned long n, unsigned long start, unsigned long end, vector< vector<unsigned long> > &preStepVec, const vector<unsigned long> indexArray)
{
    if(n==0)
        return;
    unsigned long mid=(start+end)/2;
    for(unsigned long i=start; i <= mid; i++)
    {
            preStepVec[i][n-1]= indexArray[n-1] - 1; //[i-1]
    }
    for(unsigned long i=mid+1; i <= end; i++)
    {
        preStepVec[i][n-1]= indexArray[n-1]; //[i]
    }
    combination(n-1, 0, mid, preStepVec, indexArray);
    combination(n-1, mid+1, end, preStepVec, indexArray);
}

void getPreviousStep(vector< vector<unsigned long> > &preStepVec, const vector<unsigned long> indexArray)
{
    unsigned long length= (unsigned long)pow(2,indexArray.size());
    combination(indexArray.size(), 0, length-1, preStepVec, indexArray);
    //vector< vector<unsigned long> > preStepVec(indexArray.size(), vector<unsigned long>(length));
    //return preStepVec;
}

int getCostValue(const vector<unsigned long> original, const vector<unsigned long> preStep)
{
    int cost=0;
    for(int i=0;i<original.size();i++)
    {
        if(original[i] - preStep[i]==0)
            cost++;
    }
    return cost;
}