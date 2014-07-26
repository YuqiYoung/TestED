//
//  main.cpp
//  TestED
//
//  Created by Young on 07-04－此月第1周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include <iostream>
#include "BehaviorObj.h"
#include "BehaviorObjVector.h"
#include "BehaviorEditDistance.h"
#include "MyEditDistance.h"
#include "MultiDimensionArray.h"
using namespace std;

int main(int argc, const char * argv[])
{
/*
//show how to creat insertSpaceString for 2-D
    BehaviorObj r=BehaviorObj("R","a");
    BehaviorObj r0=BehaviorObj("R","b");
    BehaviorObj r1=BehaviorObj("R","c");
    BehaviorObj w=BehaviorObj("W","s");
    BehaviorObj w0=BehaviorObj("W","d");
    BehaviorObj w1=BehaviorObj("W","e");

    BehaviorObjVector myVector;
    myVector.addBehaviorObj(w);
    myVector.printBasicInfo();
    
    BehaviorObjVector myVector2;
    myVector2.addBehaviorObj(r);
    myVector2.addBehaviorObj(r);
    myVector2.addBehaviorObj(r);
    myVector2.printBasicInfo();
    
    vector<string> t=myVector.getBehaviorVector();
    vector<string> t2=myVector2.getBehaviorVector();
    
    cout<<(float)myVector2.size()<<endl;
    cout<<edit_distance(t,t2);

    MyEditDistance test=MyEditDistance(myVector, myVector2);
    test.print_insertSpaceString();
    cout<<"EditDistance is "<<test.getEditDistance()<<endl;
    test.print_optMatix();
    test.print_dMatrix();
*/
    
    
/* //show how to transfer the index in 1-D array to N-D array.

    vector<long> lenArray={1,2,3,4,6,6};
    long length=lenArray.size();
    vector<long> lenProdArray=vector<long> (length);
    vector<long> indexArray=vector<long>(length-1);
    calLenProdArray(lenProdArray, lenArray, length);
    for(int i=0;i<length;i++)
    {
        cout<<lenProdArray[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<lenProdArray[length-1];i++)
    {
        cout<<i<<":";
        getIndexArray(lenProdArray, indexArray,i);
        for(int i=0;i<indexArray.size();i++)
        {
            cout<<indexArray[i]<<" ";
        }
        cout<<".."<<endl;
        cout<<i-getLocation(lenProdArray, indexArray)<<endl;
    }

    getIndexArray(lenProdArray, indexArray,100);
    for(int i=0;i<indexArray.size();i++)
    {
        cout<<indexArray[i]<<" ";
    }
    cout<<endl;
    long length_pow= (long)pow(2,indexArray.size());
    vector< vector<long> > preStepVec(length_pow, vector<long>(indexArray.size()));
    
    getPreviousStep(preStepVec, indexArray);
    
    for(long i=0; i < preStepVec.size(); i++)
    {
        cout<<i<<":";
        for(long j=0; j < preStepVec[i].size(); j++)
        {
            cout<<preStepVec[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    vector<long> lenArray={1,2,3,4,5};
    long length=lenArray.size();
    vector<long> lenProdArray=vector<long> (length);
    vector<long> indexArray=vector<long>(length-1);
    calLenProdArray(lenProdArray, lenArray, length);
    vector< vector<long> > visitOrder(lenProdArray[lenProdArray.size()-1], vector<long>(indexArray.size()));
    long start=0;
    long end=lenProdArray[lenProdArray.size()-1]-1;
    long dimension= length-1;
    generateVisitOrder(lenArray, visitOrder, dimension, start, end);
    for(long i=0; i < visitOrder.size(); i++)
    {
        cout<<i<<":";
        for(long j=0; j < visitOrder[i].size(); j++)
        {
            cout<<visitOrder[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

