//
//  EditDistanceStatus.h
//  TestED
//
//  Created by Young on 07-31－此月第5周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#ifndef __TestED__Status__
#define __TestED__Status__

#include <iostream>
#include <list>
#include <vector>
#include "BehaviorObj.h"
using namespace std;

//the infomation of the status(step) which we will use
class EditDistanceStatus
{
private:
    double _valueInMatrix; //current weight value in this step
    list< list<long> > _pairs;
    vector<BehaviorObj> _currentStepChrs;//the chars of each string in current step
    long _preStep;//the location of previous step
    
    /*
     e.g.
     For 3D case:
        1.{x+1,y,z} -> {x+1.y+1,z+1}
            usedIndexes: y,z
            unUsedIndexes: x
        2.{x,y,z} -> {x+1.y+1,z+1}
            usedIndexes: x,y,z
            unUsedIndexes: null
    */
    list<list<long> > _usedIndexesPairs;//combine the same content of indexes which we used in the same pair.
    list<long> _unUsedIndexes;
    
    
public:
    EditDistanceStatus(double valueInMatrix,list< list<long> > pairs,list<list<long> > usedIndexesPairs,list<long> unUsedIndexes,vector<BehaviorObj> currentStepChrs, long preStep);
    EditDistanceStatus(double valueInMatrix,long preStep);
    EditDistanceStatus& operator = (const EditDistanceStatus&);
    long getPreStep();
    double getValueInMatrix();
    list< list<long> > getPairs();
    list<list<long> > getUsedIndexesPairs();
    list<long> getUnUsedIndexes();
    vector<BehaviorObj> getCurrentStepChrs();
    
};
#endif /* defined(__TestED__Status__) */
