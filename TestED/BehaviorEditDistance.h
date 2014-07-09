//
//  BehaviorEditDistance.h
//  TestED
//
//  Created by Young on 07-04－此月第1周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#ifndef __TestED__BehaviorEditDistance__
#define __TestED__BehaviorEditDistance__
#define DELETE  0
#define KEEP    1
#define INSERT  2
#define SUBSITUDE   3
#define APPENDSPACE 4
#include <iostream>
#include "BehaviorObjVector.h"
#include "BehaviorObj.h"
#include <vector>
#include <list>

void printS1S2(list<BehaviorObj> src1,list<BehaviorObj> src2);
float targetNameEditDistance(string &s1, string &s2);
float behaviourEditDistance(list<BehaviorObj> &src1,list<BehaviorObj> &src2, BehaviorObjVector &s1,BehaviorObjVector &s2);
float minChoice(int &opt, float delWeight, float insertWeight, float subWeight);
void generateInsertSpaceList(list<BehaviorObj> &s1,list<BehaviorObj> &s2,BehaviorObj &obj1,BehaviorObj &obj2, int opt);
void printD(vector<vector<float>> vec);//print a 2d matrix

#endif /* defined(__TestED__BehaviorEditDistance__) */
