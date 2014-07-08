//
//  BehaviorEditDistance.cpp
//  TestED
//
//  Created by Young on 07-04－此月第1周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "BehaviorEditDistance.h"
using namespace std;

void printD(vector<vector<float>> vec)
{
    for(unsigned int j = 0; j < vec.size(); ++j)
    {
        for(unsigned int n=0; n < vec[j].size(); n++)
        {
            cout << vec[j][n];
            cout << "\t";
        }
        cout << endl;
    }
}

float targetNameEditDistance(string &s1, string &s2)
{
    size_t len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<float> > d(len1 + 1, std::vector<float>(len2 + 1));
    
    d[0][0] = 0;
    for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;
    
    for(unsigned int i = 1; i <= len1; ++i)
        for(unsigned int j = 1; j <= len2; ++j)
            d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),
                               d[i - 1][j - 1] + (s1[i-1] == s2[j-1] ? 0 : 1) );
    return d[len1][len2];
}
/*
DELETE  0
KEEP    1
INSERT  2
SUBSITUDE   3
APPENDSPACE 4
*/
float minChoice(int &opt, float delWeight, float insertWeight, float subWeight)
{
    float min= delWeight;
    opt=DELETE;
    if(insertWeight< min )
    {
        min=insertWeight;
        opt=APPENDSPACE;
    }
    if(subWeight<min)
    {
        min=subWeight;
        opt=SUBSITUDE;
    }
    return min;
}

void applyChoice(BehaviorObj &obj1,BehaviorObj &obj2, int opt)
{
    if(opt==DELETE)
    {
        obj1.setEditOperation(DELETE);
        obj2.setEditOperation(APPENDSPACE);
    
    }
    else if(opt==APPENDSPACE)
    {
        obj1.setEditOperation(APPENDSPACE);
        obj2.setEditOperation(DELETE);
    }
    else
    {
        obj1.setEditOperation(opt);
        obj2.setEditOperation(opt);
    }//keep or sub
}


float behaviourEditDistance(BehaviorObjVector &s1,BehaviorObjVector &s2)
{
    s2.printDetail();
    size_t len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<float> > d(len1 + 1, std::vector<float>(len2 + 1));
    
    d[0][0] = 0;
    for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;
    
    for(unsigned int i = 1; i <= len1; ++i)
    {
        //find the optimal edit solution
        int minObj=d[i][0];
        int optArray[len2];//use to save the optimal edit solution
        int index_i=i-1;
        int index_j=0;
        for(unsigned int j = 1; j <= len2; ++j)
        {
            
            if(s1.getIndex(i-1).getBehaviorName() == s2.getIndex(j-1).getBehaviorName())
            {
                d[i][j]=d[i-1][j-1];
                optArray[j]=KEEP;
            }
            else
            {
                /*string tar1=s1.getIndex(i-1).getTargetFileName();
                string tar2=s2.getIndex(j-1).getTargetFileName();
                float ed= targetNameEditDistance(tar1,tar2);
                float len1=tar1.size();
                float len2=tar2.size();
                float weight=ed/(len1+len2);*/
                d[i][j]=minChoice(optArray[j], d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1);
                //d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),d[i - 1][j - 1] + 1 );
            }
            if(d[i][j]<minObj)
            {
                minObj=d[i][j];
                index_i=i;
                index_j=j;
            }
        }
        applyChoice(s1.getIndex(index_i-1),s2.getIndex(index_j-1),optArray[index_j]);
        //s2.printDetail();
        
    }

    printD(d);
            /*d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),
                               d[i - 1][j - 1] + (s1[i-1] == s2[j-1] ? 0 : 1) );*/
    return d[len1][len2];
}





