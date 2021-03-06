//
//  BehaviorEditDistance.cpp
//  TestED
//
//  Created by Young on 07-04－此月第1周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "BehaviorEditDistance.h"
using namespace std;

void printS1S2(list<BehaviorObj> s1, list<BehaviorObj> s2)
{
    list<BehaviorObj>::iterator i;
    for(i= s1.begin();i!=s1.end();i++)
    {
        cout<<(*i).getBehaviorName();
    }
    cout<<endl;
    for(i= s2.begin();i!=s2.end();i++)
    {
        cout<<(*i).getBehaviorName();
    }
    cout<<endl;
}

void  printD(vector<vector<float>> vec)
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

float  targetNameEditDistance(string &s1, string &s2)
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
        opt=INSERT;
    }
    if(subWeight<min)
    {
        min=subWeight;
        opt=SUBSITUDE;
    }
    return min;
}

 void generateInsertSpaceList(list<BehaviorObj> &s1,list<BehaviorObj> &s2,BehaviorObj &obj1,BehaviorObj &obj2, int opt)
{
    if(opt==DELETE)
    {
        s1.push_front(obj1);
        BehaviorObj temp=BehaviorObj("_", " ");
        s2.push_front(temp);
        cout<<"s1 delete "+obj1.getBehaviorName()<<endl;
        
    }
    else if(opt==INSERT)
    {
        
        BehaviorObj temp=BehaviorObj("_                                             ‘                     ", " ");
        s1.push_front(temp);
        s2.push_front(obj2);
        //cout<<"s1 insert\"_\" s2 delete"+obj2.getBehaviorName()<<endl;
        cout<<"s1 insert "+ obj2.getBehaviorName()<<endl;

    }
    else if(opt==KEEP)
    {
        s1.push_front(obj1);
        s2.push_front(obj2);
        cout<<"s1 keep "+ obj1.getBehaviorName()+" s2 keep "+obj2.getBehaviorName()<<endl;
    }
    else if(opt==SUBSITUDE)
    {
        BehaviorObj temp1=BehaviorObj("_", " ");
        s1.push_front(temp1);
        s1.push_front(obj1);
        s2.push_front(obj2);
        s2.push_front(temp1);
        cout<<"s1 change "+ obj1.getBehaviorName()+" to "+obj2.getBehaviorName()<<endl;
    }//keep or sub
}

float behaviourEditDistance(list<BehaviorObj> &src1,list<BehaviorObj> &src2, BehaviorObjVector &s1,BehaviorObjVector &s2)
{
    src1.clear();
    src2.clear();
    size_t len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<float> > d(len1 + 1, std::vector<float>(len2 + 1));
    
    d[0][0] = 0;
    for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

    for(unsigned int i = 1; i <= len1; ++i)
    {
        //find the optimal edit solution
        for(unsigned int j = 1; j <= len2; ++j)
        {
            
            if(s1.getIndex(i-1).getBehaviorName() == s2.getIndex(j-1).getBehaviorName())
            {
                d[i][j]=d[i-1][j-1];
            }
            else
            {
                /*string tar1=s1.getIndex(i-1).getTargetFileName();
                string tar2=s2.getIndex(j-1).getTargetFileName();
                float ed= targetNameEditDistance(tar1,tar2);
                float len1=tar1.size();
                float len2=tar2.size();
                float weight=ed/(len1+len2);
                d[i][j]=minChoice(optArray[j], d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + weight);*/
                //d[i][j]=minChoice(optArray[j], d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1);
                d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),d[i - 1][j - 1] + 1 );
            }
        }
    }
    
    unsigned int index_i=(unsigned int)len1;
    unsigned int index_j=(unsigned int)len2;
    while (!(index_i ==0&&index_j ==0))
    {
        cout<<index_i;
        cout<<" ";
        cout<<index_j<<endl;
        unsigned int min=d[index_i-1][index_j-1];
        unsigned int min_i=index_i-1;
        unsigned int min_j=index_j-1;
        int choice;
        if(d[index_i-1][index_j-1]==d[index_i][index_j])
            choice=KEEP;
        else
            choice=SUBSITUDE;
        if(d[index_i-1][index_j]<min)
        {
            min_i=index_i-1;
            min_j=index_j;
            choice=DELETE;
        }
        if(d[index_i][index_j-1]<min)
        {
            min_i=index_i;
            min_j=index_j-1;
            choice=INSERT;
        }
        generateInsertSpaceList(src1, src2, s1.getIndex(index_i-1), s2.getIndex(index_j-1), choice);
        index_i=min_i;
        index_j=min_j;
    }
        printD(d);
            /*d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),
                               d[i - 1][j - 1] + (s1[i-1] == s2[j-1] ? 0 : 1) );*/
    return d[len1][len2];
}





