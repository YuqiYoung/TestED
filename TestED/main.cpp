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

//    BehaviorObj r=BehaviorObj("R","a");
//    BehaviorObj r0=BehaviorObj("R","b");
//    BehaviorObj r1=BehaviorObj("R","c");
//    BehaviorObj w=BehaviorObj("W","s");
//    BehaviorObj w0=BehaviorObj("W","d");
//    BehaviorObj w1=BehaviorObj("W","e");
//
//    BehaviorObjVector myVector;
//    myVector.addBehaviorObj(w);
//    myVector.printBasicInfo();
//    
//    BehaviorObjVector myVector2;
//    myVector2.addBehaviorObj(r);
//    myVector2.addBehaviorObj(r);
//    myVector2.addBehaviorObj(r);
//    myVector2.printBasicInfo();
    
    /*vector<string> t=myVector.getBehaviorVector();
    vector<string> t2=myVector2.getBehaviorVector();
    
    cout<<(float)myVector2.size()<<endl;
    cout<<edit_distance(t,t2);*/

//    MyEditDistance test=MyEditDistance(myVector, myVector2);
//    test.print_insertSpaceString();
//    cout<<"EditDistance is "<<test.getEditDistance()<<endl;
    //test.print_optMatix();
    //test.print_dMatrix();
    //myED.printS1S2();
    //myVector2.printInfo();
    /*cout<< myVector2.getIndex(0).getEditOperation();
    myVector2.getIndex(0).setEditOperation(2);
    cout<< myVector2.getIndex(0).getEditOperation();*/
    
    
    
    
    vector<unsigned long> lenArray={1,2,3};
    unsigned long length=lenArray.size();
    vector<unsigned long> lenProdArray=vector<unsigned long> (length);
    vector<unsigned long> indexArray=vector<unsigned long>(length-1);
    calLenProdArray(lenProdArray, lenArray, length);
    for(int i=0;i<length;i++)
    {
        cout<<lenProdArray[i]<<" ";
    }
    cout<<endl;

//    for(int i=0;i<lenProdArray[length-1];i++)
//    {
//        cout<<i<<":";
//        getIndexArray(lenProdArray, indexArray,i);
//        for(int i=0;i<indexArray.size();i++)
//        {
//            cout<<indexArray[i]<<" ";
//        }
//        cout<<".."<<endl;
//        cout<<i-getLocation(lenProdArray, indexArray)<<endl;
//    }

    getIndexArray(lenProdArray, indexArray,4);
    for(int i=0;i<indexArray.size();i++)
    {
        cout<<indexArray[i]<<" ";
    }
    unsigned long length_pow= (unsigned long)pow(2,indexArray.size());
    vector< vector<unsigned long> > preStepVec(length_pow, vector<unsigned long>(indexArray.size()));
    
    getPreviousStep(preStepVec, indexArray);
    
    for(unsigned long i=0; i < preStepVec.size(); i++)
    {
        cout<<i<<":";
        for(unsigned long j=0; j < preStepVec[i].size(); j++)
        {
            cout<<preStepVec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

