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
/*
Method: genLenProdArray
parameter:
    lenArray: save the length of each original strings.
    lenProdArray: the size of each dimension.
Example:
    input: lenArray->{1,2,3,4}
    output: lenProdArray->{1,1*2,1*2*3,1*2*3*4}
*/
long genLenProdArray(vector<long> &lenProdArray, const vector<long> &lenArray, long n);

/*
 Method: getLocation
 Detail: switch the coordinate of multi-dimension to the coordinate of one-dimension
 parameter:
    lenProdArray: the size of each dimension.
    indexArray: one coordinate of this multi-dimension-matrix
    Example:
    input: 
        lenProdArray->{1,1*2,1*2*3,1*2*3*4}
        indexArray->{1,2,3}
    output:1*1+2*(1*2)+3*(1*2*3)
 */
long getLocation(const vector<long> lenProdArray, const vector<long> indexArray);

/*
 Method: getIndexArray
 Detail: switch the coordinate of one-dimension to the coordinate of multi-dimension
 parameter:
    lenProdArray: the size of each dimension.
    indexArray: one coordinate of this multi-dimension-matrix
    loc: the relative 1D coordinate
 Example:
    input:
        lenProdArray->{1,1*2,1*2*3,1*2*3*4}
        loc: 1*1+2*(1*2)+3*(1*2*3)
    output:
        indexArray->{1,2,3}
 */
void getIndexArray(const vector<long> lenProdArray,vector<long> &indexArray,const long loc);

/*
 Method: getPreviousStep
 Detail: get full previous steps set of the given indexArray
 parameter:
    indexArray: one coordinate of this multi-dimension-matrix
    loc: the relative 1D coordinate
 Example:
    input:
        indexArray->{1,1}
    output:
        preStepVec->{1,1},{0,1},{1,0},{0,0}
 */
void getPreviousStep(vector< vector<long> > &preStepVec, const vector<long> indexArray);

/*
 Method: combination
 Detail: used in method "getPreviousStep"
*/
void combination(long n, long start, long end, vector< vector<long> > &preStepVec, const vector<long> indexArray);

/*
 Method: getOptiPreviousStep
 Detail: get the optimal previous steps instead of the full set
 parameter:
    pairs: According to current chars of each strings, assgining the same chars in the same group
    indexArray: one coordinate of this multi-dimension-matrix
 output:
    preStepVec
 */
void getOptiPreviousStep(vector< vector<long> > &preStepVec, list< list<long> > &pairs, const vector<long> indexArray);

/*
 Method: getPreStepLocs
 Detail: switch the N-D version previous-steps vectors to 1-D version
 parameter:
    pairs: According to current chars of each strings, assgining the same chars in the same group
    indexArray: one coordinate of this multi-dimension-matrix
    lenProdArray: the size of each dimension.
 output:
    preStepLocs
 */
void getPreStepLocs(vector<long> &preStepLocs, list< list<long> > &pairs, const vector<long> indexArray,vector<long> lenProdArray);

long getCostValue(const vector<long> original, const vector<long> preStep,vector<BehaviorObj> &currentStepChr,list<long> &usedIndexes,list<long> &unUsedIndexes);

/*
 Method: MinPreStep
 Detail: find the min weight value step
 Parameter:
    dMatrix: edit distance matrix
    preStepLocs: the locations of previous steps
    indexArray: one coordinate of this multi-dimension-matrix
    lenProdArray: the size of each dimension
    currentStepChr: the chars of each string in current step
 output:
    minLoc: minloc[0] denote minIndex, minloc[1]denote minValue
    usedIndexesForMin:the usedIndexes of the min weigth value
    unUsedIndexesForMin: the unUsedIndexes of the min weigth value
 */
void MinPreStep(vector<EditDistanceStatus> dMatrix, const vector<long> &preStepLocs , const vector<long> &currentStep,const vector<long> &lenProdArray, vector<BehaviorObj> &currentStepChr, double *minLoc, list<long>  &usedIndexesForMin,  list<long> &unUsedIndexesForMin);//the last array in the vector preStepVec is the current step

/*
 Method: generateVisitOrder
 Detail: get the computation for the numbers in lenArray
 output:
    visitOrder
 e.g.
    input: 
        lenArray: {1,1,1}
        dimension: 2
        start:0
        end:3
    output: 
        visitOrder: {1,1},{0,1},{1,0},{0,0}
 */
void generateVisitOrder(const vector<long> lenArray, vector< vector<long> > &visitOrder, long dimension, long start, long end);

/*
 Method: findUsedIndexesPairs
 Example:
    input:
        Array    index:{0,1,2,3}
        currentStepChr:{W,W,R,W}
           usedIndexes:  {1,2,3}
    output:
        usedIndexesPairs:{1,3},{2}
        usedIndexesChars:{W,W},{R}
*/
void findUsedIndexesPairs(vector<BehaviorObj> currentStepChr,list< list<long> > &usedIndexesPairs,list<long> &unUsedIndexes);

/*
 Method: findPairs
 Example:
 input:
    Array    index:{0,1,2,3}
    currentStepChr:{W,W,R,W}
 output:
             pairs:{0,1,3},{2}
       pairs_chars:{W,W,W},{R}
 */
void findPairs(vector<BehaviorObj> currentStepChr,list< list<long> > &pairs);

list<long> findLongestPair(list< list<long> > pairs);

#endif /* defined(__TestED__MultiDimensionArray__) */
