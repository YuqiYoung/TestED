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
//    list< list<long> > _usedPairs;
//    list< list<long> > _unUsedPairs;
    vector<BehaviorObj> _currentStepChrs;
    long _preStep;
    
    
public:
    EditDistanceStatus(double valueInMatrix,list< list<long> > pairs,vector<BehaviorObj> currentStepChrs, long preStep);
    EditDistanceStatus(double valueInMatrix,long preStep);
    EditDistanceStatus& operator = (const EditDistanceStatus&);
    long getPreStep();
    double getValueInMatrix();
    list< list<long> > getPairs();
    vector<BehaviorObj> getCurrentStepChrs();
    
};
#endif /* defined(__TestED__Status__) */
