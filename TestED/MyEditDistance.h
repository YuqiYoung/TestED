//
//  MyEditDistance.h
//  TestED
//
//  Created by Young on 07-10－此月第2周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#ifndef __TestED__MyEditDistance__
#define __TestED__MyEditDistance__
#define PRINTOUT 1 //1: printout Details; 0: printout nothing
#define DELETE  0
#define KEEP    1
#define INSERT  2
#define SUBSITUDE   3
#include <iostream>
#include <vector>
#include <list>
#include "BehaviorObj.h"
#include "BehaviorObjVector.h"

class MyEditDistance
{
private:
    BehaviorObjVector _s1;
    BehaviorObjVector _s2;
    list<BehaviorObj> _rS1;//inserSpace version of S1
    list<BehaviorObj> _rS2;////inserSpace version of S2
    
    vector<vector <float> > _d; //edit distance matrix
    vector<vector <float> > _opt; //edit distance state transition matrix
    
    float _editDistance;
    
    float BehaviorEditDistance();
    void generateInsertSpaceList();
    void insertSpaceToList(list<BehaviorObj> &s1,list<BehaviorObj> &s2,BehaviorObj &obj1,BehaviorObj &obj2, int opt);
    float currentChoice(float &opt, float delWeight, float insertWeight, float subWeight);

public:
    MyEditDistance(BehaviorObjVector s1, BehaviorObjVector s2);
    BehaviorObjVector &get_s1();
    BehaviorObjVector &get_s2();
    vector<vector <float> > &get_dMatrix();
    vector<vector <float> > &get_optMatrix();
    list<BehaviorObj> &get_rS1();
    list<BehaviorObj> &get_rS2();
    float getEditDistance();
    
    void print2DMAtrix(vector<vector <float> > myVector);
    void printList(list<BehaviorObj> myList);
    void print_dMatrix();
    void print_optMatix();
    void print_rS1();
    void print_rS2();
    void print_insertSpaceString();
    
};
#endif /* defined(__TestED__MyEditDistance__) */
