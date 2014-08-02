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

class EditDistanceStatus
{
private:
    double _valueInMatrix;
    list< list<long> > _pairs;
    list<list<long> > _usedIndexesPairs;
    list<long> _unUsedIndexes;
    vector<BehaviorObj> _currentStepChrs;
    long _preStep;
    
    
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
