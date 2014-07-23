//
//  BehaviorObj.h
//  TestED
//
//  Created by Young on 07-04－此月第1周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#ifndef __TestED__BehaviorObj__
#define __TestED__BehaviorObj__

#include <iostream>
using namespace std;
class BehaviorObj
{
private:
    string _behaviorName;//some operation names such as write, read and so on
    string _targetFileName;//the target file name of this operation
    
public:
    BehaviorObj(const string bn, const string tFN);
    string getBehaviorName();
    string getTargetFileName();
    void printInfo();//_behaviorName+_targetFileName
};
#endif /* defined(__TestED__BehaviorObj__) */

