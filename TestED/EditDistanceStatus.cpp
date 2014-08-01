//
//  EditDistanceStatus.cpp
//  TestED
//
//  Created by Young on 07-31－此月第5周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "EditDistanceStatus.h"
EditDistanceStatus::EditDistanceStatus(double valueInMatrix,list< list<long> > pairs,vector<BehaviorObj> currentStepChrs, long preStep)
{
    _valueInMatrix=valueInMatrix;
    _pairs=pairs;
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
vector<BehaviorObj> EditDistanceStatus::getCurrentStepChrs()
{
    return _currentStepChrs;
}