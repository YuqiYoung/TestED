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

int main(int argc, const char * argv[])
{


    // test multiStringEditDistance Algorithm
    BehaviorObj w=BehaviorObj("W","a");
    BehaviorObj r=BehaviorObj("R","b");
    BehaviorObjVector s1;
    s1.addBehaviorObj(w);
    s1.addBehaviorObj(w);
    
    BehaviorObjVector s2;
    s2.addBehaviorObj(w);
    s2.addBehaviorObj(w);
    s2.addBehaviorObj(r);
//    s1.addBehaviorObj(w);
//    s1.addBehaviorObj(r);
//    s1.addBehaviorObj(r);
    
    BehaviorObjVector s3;
    s3.addBehaviorObj(r);
    s3.addBehaviorObj(w);
    s3.addBehaviorObj(w);
//    s2.addBehaviorObj(r);
//    s2.addBehaviorObj(r);

    BehaviorObjVector s4;
    s4.addBehaviorObj(r);
    s4.addBehaviorObj(w);
    s4.addBehaviorObj(r);
    s4.addBehaviorObj(w);
    vector<BehaviorObjVector> source;
    //source.clear();
    //source.push_back(s1);
    source.push_back(s2);
    source.push_back(s3);
    source.push_back(s4);
    
    MultiStringEditDistance myED=MultiStringEditDistance(source);
   // myED.printEditDistanceMatrix();
    myED.printAlignedStrings();




/*
    //test the algorithm that finding the pairs in a array
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
        //myVector.push_back(y);
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
    getOptiPreviousStep(preStepVec, pairs, indexArray);
    for(long i=0; i < preStepVec.size(); i++)
    {
        cout<<i<<":";
        for(long j=0; j < preStepVec[i].size(); j++)
        {
            cout<<preStepVec[i][j]<<" ";
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
*/

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
    vector<long> lenArray={1,2,3,4};
    long length=lenArray.size();
    vector<long> lenProdArray=vector<long> (length);
    vector<long> indexArray=vector<long>(length-1);
    genLenProdArray(lenProdArray, lenArray, length);
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

    getIndexArray(lenProdArray, indexArray,0);
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


/*    //generate the visit order
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
    for(long i=0; i < visitOrder.size(); i++)
    {
        cout<<i<<":";
        for(long j=0; j < visitOrder[i].size(); j++)
        {
            cout<<visitOrder[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return 0;
}

