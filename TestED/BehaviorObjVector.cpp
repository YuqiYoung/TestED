//
//  BehaviorObjVector.cpp
//  TestED
//
//  Created by Young on 07-04－此月第1周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "BehaviorObjVector.h"
#include "BehaviorEditDistance.h"
#include <vector>
#include "BehaviorObj.h"
using namespace std;
BehaviorObjVector::BehaviorObjVector()
{

}

BehaviorObj& BehaviorObjVector::getIndex(int index)
{
    if(0<=index&& _behaviorVector.size()>index)
        return _behaviorVector[index];
    else
    {
        cerr<<"BehaviorObjVector::getIndex out of bound"<<index<<_behaviorVector.size()<<endl;
        exit(EXIT_FAILURE);
    }
}

size_t BehaviorObjVector::size()
{
    return _behaviorVector.size();
}

vector<string> BehaviorObjVector::getBehaviorVector()
{
    vector<string> myVector;
    for(vector<BehaviorObj>::iterator i=_behaviorVector.begin(); i!=_behaviorVector.end();i++)
    {
        myVector.push_back(i->getBehaviorName());
    }
    return myVector;

}

vector<string> BehaviorObjVector::getTargetFileNameVector()
{
    vector<string> myVector;
    for(vector<BehaviorObj>::iterator i=_behaviorVector.begin(); i!=_behaviorVector.end();i++)
    {
        myVector.push_back(i->getTargetFileName());
    }
    return myVector;
}

void BehaviorObjVector::addBehaviorObj(BehaviorObj bo)
{
    _behaviorVector.push_back(bo);
}

void BehaviorObjVector::printBasicInfo()
{
    for(vector<BehaviorObj>::iterator i=_behaviorVector.begin(); i!=_behaviorVector.end();i++)
    {
        cout<<i->getBehaviorName();
    }
    cout<<endl;
}

void BehaviorObjVector::printDetail()
{
    for(vector<BehaviorObj>::iterator i=_behaviorVector.begin(); i!=_behaviorVector.end();i++)
    {
        cout<<i->getBehaviorName();
        cout<<i->getTargetFileName();
    }
    cout<<endl;
}

