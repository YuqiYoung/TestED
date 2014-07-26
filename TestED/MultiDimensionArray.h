//
//  MultiDimensionArray.h
//  TestED
//
//  Created by Young on 07-22－此月第4周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#ifndef __TestED__MultiDimensionArray__
#define __TestED__MultiDimensionArray__

#include <iostream>
#include <vector>
#include "math.h"
using namespace std;
long calLenProdArray(vector<long> &lenProdArray, const vector<long> &lenArray, long n);
long getLocation(const vector<long> lenProdArray, const vector<long> indexArray);
void getIndexArray(const vector<long> lenProdArray,vector<long> &indexArray,const long loc);
void getPreviousStep(vector< vector<long> > &preStepVec, const vector<long> indexArray);
int getCostValue(const vector<long> original, const vector<long> preStep);
long MinPreStep(const vector<long> dMatrix, const vector< vector<long> > &preStepVec,const vector<long> lenProdArray);//the last array in the vector preStepVec is the current step
void generateVisitOrder(const vector<long> lenArray, vector< vector<long> > &visitOrder, long dimension, long start, long end);
#endif /* defined(__TestED__MultiDimensionArray__) */
