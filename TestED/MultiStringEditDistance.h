//
//  MultiStringEditDistance.h
//  TestED
//
//  Created by Young on 07-26－此月第4周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#ifndef __TestED__MultiStringEditDistance__
#define __TestED__MultiStringEditDistance__

#include <iostream>
#include "MultiDimensionArray.h"
#include "EditDistanceStatus.h"
#include "BehaviorObjVector.h"
#include <string>

class MultiStringEditDistance
{
private:
    vector<BehaviorObjVector> _source;
    vector<long> _lenArray;
    vector<long> _lenProdArray;//save the size of each dimension
    vector< vector<long> > _visitOrder;
    string *_alignedStrings;
    //vector< double > _editDistanceMatrix;
    vector< EditDistanceStatus > _editDistanceMatrix;
    
public:
    MultiStringEditDistance(vector<BehaviorObjVector> source);
    void generateEditDistanceMatrix();
    void backTrace();
    void printAlignedStrings();
    void getCurrentStepChr(vector<long> indexArray, vector<BehaviorObj> &stepChrs);
    void printEditDistanceMatrix();
    
};
#endif /* defined(__TestED__MultiStringEditDistance__) */
