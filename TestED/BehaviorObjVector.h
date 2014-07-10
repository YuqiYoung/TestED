//
//  BehaviorObjVector.h
//  TestED
//
//  Created by Young on 07-04－此月第1周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#ifndef __TestED__BehaviorObjVector__
#define __TestED__BehaviorObjVector__

#include <iostream>
#include <vector>
#include "BehaviorObj.h"
class BehaviorObjVector
{
private:
    vector <BehaviorObj> _behaviorVector;
public:
    BehaviorObjVector();
    size_t size();
    BehaviorObj& getIndex(int index);
    void addBehaviorObj(BehaviorObj bo);
    vector<string> getBehaviorVector();
    vector<string> getTargetFileNameVector();
    void printInsertSpaceString();
    void printDetail();//behavior+targetname
    void printInfo();//behavior+targetname
};

#endif /* defined(__TestED__BehaviorObjVector__) */
