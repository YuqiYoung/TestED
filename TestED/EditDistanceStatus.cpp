//
//  EditDistanceStatus.cpp
//  TestED
//
//  Created by Young on 07-31－此月第5周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "EditDistanceStatus.h"
EditDistanceStatus::EditDistanceStatus(double valueInMatrix,list< list<long> > pairs,list< list<long> > usedIndexesPairs, list<long> unUsedIndexes, vector<BehaviorObj> currentStepChrs, long preStep)
{
    _valueInMatrix=valueInMatrix;
    _pairs=pairs;
    _unUsedIndexes=unUsedIndexes;
    _usedIndexesPairs=usedIndexesPairs;
    _currentStepChrs=currentStepChrs;
    _preStep=preStep;
    
}
EditDistanceStatus::EditDistanceStatus(double valueInMatrix,long preStep)
{
    _valueInMatrix=valueInMatrix;
    _preStep=preStep;
}

EditDistanceStatus & EditDistanceStatus::operator = (const EditDistanceStatus& RightSides)
{
    _valueInMatrix=RightSides._valueInMatrix;
    _preStep=RightSides._preStep;
    _pairs=RightSides._pairs;
    _usedIndexesPairs=RightSides._usedIndexesPairs;
    _unUsedIndexes=RightSides._unUsedIndexes;
    _currentStepChrs=RightSides._currentStepChrs;

    return *this;
}

long EditDistanceStatus::getPreStep()
{
    return _preStep;
}
double EditDistanceStatus::getValueInMatrix()
{
    return _valueInMatrix;
}
list< list<long> > EditDistanceStatus::getPairs()
{
    return _pairs;
}

list<list<long> > EditDistanceStatus::getUsedIndexesPairs()
{
    return _usedIndexesPairs;
}

list<long> EditDistanceStatus::getUnUsedIndexes()
{
    return _unUsedIndexes;
}
vector<BehaviorObj> EditDistanceStatus::getCurrentStepChrs()
{
    return _currentStepChrs;
}