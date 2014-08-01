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
#include <list>
#include "math.h"
#include "EditDistanceStatus.h"
#include "BehaviorObj.h"
using namespace std;
long genLenProdArray(vector<long> &lenProdArray, const vector<long> &lenArray, long n);
long getLocation(const vector<long> lenProdArray, const vector<long> indexArray);

void getIndexArray(const vector<long> lenProdArray,vector<long> &indexArray,const long loc);
void combination(long n, long start, long end, vector< vector<long> > &preStepVec, const vector<long> indexArray);
void getPreviousStep(vector< vector<long> > &preStepVec, const vector<long> indexArray);

void getOptiPreviousStep(vector< vector<long> > &preStepVec, list< list<long> > &pairs, const vector<long> indexArray);

void getPreStepLocs(vector<long> &preStepLocs, list< list<long> > &pairs, const vector<long> indexArray,vector<long> lenProdArray);

long getCostValue(const vector<long> original, const vector<long> preStep,vector<BehaviorObj> &currentStepChr);
void MinPreStep(vector<EditDistanceStatus> dMatrix, const vector<long> &preStepLocs , const vector<long> &currentStep,const vector<long> &lenProdArray, vector<BehaviorObj> &currentStepChr, double *minLoc);//the last array in the vector preStepVec is the current step
void generateVisitOrder(const vector<long> lenArray, vector< vector<long> > &visitOrder, long dimension, long start, long end);

void findPairs(vector<BehaviorObj> currentStepChr,list< list<long> > &pairs);

list<long> findLongestPair(list< list<long> > pairs);

#endif /* defined(__TestED__MultiDimensionArray__) */
