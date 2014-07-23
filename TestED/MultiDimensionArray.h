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
unsigned long calLenProdArray(vector<unsigned long> &lenProdArray, vector<unsigned long> &lenArray, unsigned long n);
unsigned long getLocation(vector<unsigned long> &lenProdArray, vector<unsigned long>  &indexArray);
void getIndexArray(const vector<unsigned long> lenProdArray,vector<unsigned long> &indexArray,const unsigned long loc);
void getPreviousStep(vector< vector<unsigned long> > &preStepVec, const vector<unsigned long> indexArray);
int getCostValue(const vector<unsigned long> original, const vector<unsigned long> preStep);
int MinPreStep(const vector<unsigned long> dMatrix, vector< vector<unsigned long> > &preStepVec);//the last array in the vector preStepVec is the current step

#endif /* defined(__TestED__MultiDimensionArray__) */
