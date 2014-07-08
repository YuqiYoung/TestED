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

    BehaviorObj temp=BehaviorObj("R","a");
    BehaviorObj temp0=BehaviorObj("R","b");
    BehaviorObj temp1=BehaviorObj("R","c");
    BehaviorObj temp2=BehaviorObj("W","d");
    BehaviorObj temp3=BehaviorObj("W","e");
    
    BehaviorObjVector myVector;
    myVector.addBehaviorObj(temp);
    myVector.addBehaviorObj(temp0);
    myVector.addBehaviorObj(temp1);
    myVector.printInsertSpaceString();
    
    BehaviorObjVector myVector2;
    myVector2.addBehaviorObj(temp);
    myVector2.addBehaviorObj(temp2);
    myVector2.addBehaviorObj(temp2);
    myVector2.addBehaviorObj(temp);
    myVector2.addBehaviorObj(temp2);
    myVector2.addBehaviorObj(temp);
    myVector2.printInsertSpaceString();
    
    /*vector<string> t=myVector.getBehaviorVector();
    vector<string> t2=myVector2.getBehaviorVector();
    
    cout<<(float)myVector2.size()<<endl;
    cout<<edit_distance(t,t2);*/

    behaviourEditDistance(myVector2,myVector);
    
    myVector2.printInsertSpaceString();
    myVector.printInsertSpaceString();
    
    //myVector2.printInfo();
    /*cout<< myVector2.getIndex(0).getEditOperation();
    myVector2.getIndex(0).setEditOperation(2);
    cout<< myVector2.getIndex(0).getEditOperation();*/
    
    
    
    return 0;
}

