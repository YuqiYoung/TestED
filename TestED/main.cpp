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
#include "MultiStringEditDistance.h"
using namespace std;
//test function: findPairs,getOptiPreviousStep,getPreviousStep
//test the algorithm that finding the pairs in a array
void test1()
{
    BehaviorObj x=BehaviorObj("X","a");
    BehaviorObj y=BehaviorObj("Y","b");
    BehaviorObj z=BehaviorObj("Z","c");
    vector<long> indexArray=vector<long>(3,2);
    vector<BehaviorObj> myVector;
    list< list<long> > pairs;
    list<long> longestPair;
    for(int i=0;i<1;i++)
    {
        myVector.push_back(x);
        myVector.push_back(y);
        myVector.push_back(y);
    }
    for(int i=0; i<indexArray.size();i++)
    {
        cout<<indexArray[i]<<"\t";
    }
    cout<<"<--Coordinate-->"<<endl;
    for(int i=0; i<myVector.size();i++)
    {
        cout<<i<<"\t";
    }
    cout<<"<--index-->"<<endl;
    for(int i=0; i<myVector.size();i++)
    {
        cout<<myVector[i].getBehaviorName()<<"\t";
    }
    cout<<"<--origin chain-->"<<endl;
    
    findPairs(myVector,pairs);
    int index=0;
    for(list< list<long> >::iterator i= pairs.begin();i!=pairs.end();i++)
    {
        cout<<"Pair_"<<index<<": ";
        for(list<long>::iterator iter=(*i).begin(); iter!= (*i).end(); iter++)
        {
            cout<<*iter<<" ";
        }
        cout<<endl;
        index++;
    }
    long length= pow(2, pairs.size());
    vector< vector<long> > preStepVec=  vector< vector<long> >(length,vector<long>(indexArray.size()));
    cout<<"previous step(optimal set):"<<endl;
    cout<<"1d\t:\tnd"<<endl;
    getOptiPreviousStep(preStepVec, pairs, indexArray);
    for(long i=0; i < preStepVec.size(); i++)
    {
        cout<<i<<"\t:\t";
        for(long j=0; j < preStepVec[i].size(); j++)
        {
            cout<<preStepVec[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    long length_pow= (long)pow(2,indexArray.size());
    vector< vector<long> > preFullStepVec(length_pow, vector<long>(indexArray.size()));
    getPreviousStep(preFullStepVec, indexArray);
    cout<<"previous step(full set):"<<endl;
    cout<<"1d\t:\tnd"<<endl;
    for(long i=0; i < preFullStepVec.size(); i++)
    {
        cout<<i<<"\t:\t";
        for(long j=0; j < preFullStepVec[i].size(); j++)
        {
            cout<<preFullStepVec[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //    longestPair=findLongestPair(pairs);
    //    cout<<longestPair.size()<<endl;
    //    cout<<"longest pair:";
    //    for(list<long>::iterator iter=longestPair.begin(); iter!= longestPair.end(); iter++)
    //    {
    //        cout<<*iter<<" ";
    //    }
    //    cout<<endl;

}

//test function:getIndexArray, getLocation
//show how to transfer the index in 1-D array to N-D array.
void test2()
{
    vector<long> lenArray={1,2,3,4};
    long length=lenArray.size();
    vector<long> lenProdArray=vector<long> (length);
    vector<long> indexArray=vector<long>(length-1);
    genLenProdArray(lenProdArray, lenArray, length);
    cout<<"[lenProdArray]"<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<lenProdArray[i]<<" ";
    }
    cout<<endl;
    cout<<"1d:nd"<<endl;
    for(int i=0;i<lenProdArray[length-1];i++)
    {
        cout<<i<<" :";
        getIndexArray(lenProdArray, indexArray,i);
        for(int i=0;i<indexArray.size();i++)
        {
            cout<<indexArray[i]<<" ";
        }
        cout<<endl;
        //if deduction is 0, it means that the result of function"getLocation" is correct
        cout<<"[deduction] "<<i-getLocation(lenProdArray, indexArray)<<endl;
    }
    
    getIndexArray(lenProdArray, indexArray,0);
    cout<<"current step:"<<endl;
    for(int i=0;i<indexArray.size();i++)
    {
        cout<<indexArray[i]<<" ";
    }
    cout<<endl;

}

//test function "generateVisitOrder"
void test3()
{
    vector<long> lenArray={1,6,6};
    long length=lenArray.size();
    vector<long> lenProdArray=vector<long> (length);
    vector<long> indexArray=vector<long>(length-1);
    genLenProdArray(lenProdArray, lenArray, length);
    vector< vector<long> > visitOrder(lenProdArray[lenProdArray.size()-1], vector<long>(indexArray.size()));
    long start=0;
    long end=lenProdArray[lenProdArray.size()-1]-1;
    long dimension= length-1;
    generateVisitOrder(lenArray, visitOrder, dimension, start, end);
    cout<<"1d\t:\tnd"<<endl;
    for(long i=0; i < visitOrder.size(); i++)
    {
        cout<<i<<"\t:\t";
        for(long j=0; j < visitOrder[i].size(); j++)
        {
            cout<<visitOrder[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(int argc, const char * argv[])
{
    // test multiStringEditDistance Algorithm
    BehaviorObj w=BehaviorObj("W","a");
    BehaviorObj r=BehaviorObj("R","b");
    BehaviorObjVector s1;//generate s1
    s1.addBehaviorObj(w);
    s1.addBehaviorObj(w);
    
    BehaviorObjVector s2;//generate s2
    s2.addBehaviorObj(w);
    s2.addBehaviorObj(w);
    s2.addBehaviorObj(r);
    s2.addBehaviorObj(w);
    s2.addBehaviorObj(r);
    s2.addBehaviorObj(r);
    
    BehaviorObjVector s3;//generate s3
    s3.addBehaviorObj(r);
    s3.addBehaviorObj(w);
    s3.addBehaviorObj(w);
    s3.addBehaviorObj(r);
    s3.addBehaviorObj(r);

    BehaviorObjVector s4;//generate s4
    s4.addBehaviorObj(r);
    s4.addBehaviorObj(w);
    s4.addBehaviorObj(r);
    s4.addBehaviorObj(w);
    
    vector<BehaviorObjVector> source;
    source.push_back(s1);
    source.push_back(s2);
    source.push_back(s3);
    source.push_back(s4);
    
    MultiStringEditDistance myED=MultiStringEditDistance(source);
    myED.printAlignedStrings();

    return 0;
}

