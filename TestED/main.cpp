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
using namespace std;

int main(int argc, const char * argv[])
{

    BehaviorObj r=BehaviorObj("R","a");
    BehaviorObj r0=BehaviorObj("R","b");
    BehaviorObj r1=BehaviorObj("R","c");
    BehaviorObj w0=BehaviorObj("W","d");
    BehaviorObj w1=BehaviorObj("W","e");

    BehaviorObjVector myVector;
    //myVector.addBehaviorObj(r);
    myVector.addBehaviorObj(w0);
    myVector.addBehaviorObj(w1);
    myVector.addBehaviorObj(r1);
    //myVector.addBehaviorObj(w0);
    //myVector.addBehaviorObj(r0);
    //myVector.addBehaviorObj(r0);
    myVector.printInsertSpaceString();
    
    BehaviorObjVector myVector2;
    myVector2.addBehaviorObj(r);
//    myVector2.addBehaviorObj(r1);
//    myVector2.addBehaviorObj(r1);
//    myVector.addBehaviorObj(w0);
//    myVector.addBehaviorObj(w0);
//    myVector2.addBehaviorObj(r1);
    myVector2.printInsertSpaceString();
    
    /*vector<string> t=myVector.getBehaviorVector();
    vector<string> t2=myVector2.getBehaviorVector();
    
    cout<<(float)myVector2.size()<<endl;
    cout<<edit_distance(t,t2);*/
    list<BehaviorObj> s1;
    list<BehaviorObj> s2;
    behaviourEditDistance(s1,s2,myVector,myVector2);
    
    printS1S2(s1,s2);
    //myED.printS1S2();
    //myVector2.printInfo();
    /*cout<< myVector2.getIndex(0).getEditOperation();
    myVector2.getIndex(0).setEditOperation(2);
    cout<< myVector2.getIndex(0).getEditOperation();*/
    
    
    
    return 0;
}

