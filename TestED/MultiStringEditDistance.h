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
    vector<BehaviorObjVector> _source;//original strings
    vector<long> _lenArray;//{1,the length of each original string}
    vector<long> _lenProdArray;//the size of each dimension
    vector< EditDistanceStatus > _editDistanceMatrix;
    vector< vector<long> > _visitOrder;//the order of the element will be visited in editDistanceMatrix
    string *_alignedStrings;
    //vector< double > _editDistanceMatrix;
    
public:
    MultiStringEditDistance(vector<BehaviorObjVector> source);
    void generateEditDistanceMatrix();
    void backTrace();
    void printAlignedStrings();
    void getCurrentStepChr(vector<long> indexArray, vector<BehaviorObj> &stepChrs);
    void printEditDistanceMatrix();
    
};
#endif /* defined(__TestED__MultiStringEditDistance__) */
