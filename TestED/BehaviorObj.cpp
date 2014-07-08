//
//  BehaviorObj.cpp
//  TestED
//
//  Created by Young on 07-04－此月第1周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "BehaviorObj.h"
BehaviorObj::BehaviorObj(const string bn, const string tFN)
{
        _behaviorName=bn;
        _targetFileName=tFN;
}
    
//BehaviorObj::~BehaviorObj();
    
string BehaviorObj::getBehaviorName()
{
        return _behaviorName;
}
    
string BehaviorObj::getTargetFileName()
{
        return _targetFileName;
}

int BehaviorObj::getEditOperation()
{
    return _editOperation;
}

void BehaviorObj::setEditOperation(int opn)
{
    _editOperation=opn;
}

void BehaviorObj::printInfo()
{
        cout<<getBehaviorName()+"("+getTargetFileName()+") ";
}