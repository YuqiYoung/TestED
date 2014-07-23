//
//  MyEditDistance.cpp
//  TestED
//
//  Created by Young on 07-10－此月第2周.
//  Copyright (c) 2014年 Young. All rights reserved.
//

#include "MyEditDistance.h"
#include "BehaviorObj.h"

MyEditDistance::MyEditDistance(BehaviorObjVector s1, BehaviorObjVector s2)
{
    if(s1.size()==0 || s2.size()==0)
    {
        cerr<<"there are at least one  BehaviorObjVector instance's size is 0";
        exit(EXIT_FAILURE);
    }
    _s1=s1;
    _s2=s2;
    size_t len1 = _s1.size(), len2 = _s2.size();
    _d = std::vector<std::vector<float> >(len1 + 1, std::vector<float>(len2 + 1));
    _opt = std::vector<std::vector<float> >(len1 + 1, std::vector<float>(len2 + 1));
    _editDistance=BehaviorEditDistance();
    print_dMatrix();
    generateInsertSpaceList();
}

float MyEditDistance::getEditDistance()
{
    return _editDistance;
}

vector<vector <float> > &MyEditDistance::get_dMatrix()
{
    return _d;
}

vector<vector <float> > &MyEditDistance::get_optMatrix()
{
    return _opt;
}

BehaviorObjVector &MyEditDistance::get_s1()
{
    return _s1;
}

BehaviorObjVector &MyEditDistance::get_s2()
{
    return _s2;
}

list<BehaviorObj> & MyEditDistance::get_rS1()
{
    return _rS1;
}

list<BehaviorObj> & MyEditDistance::get_rS2()
{
    return _rS2;
}

float MyEditDistance::currentChoice(float &opt, float delWeight, float insertWeight, float subWeight)
{
    float min= subWeight;
    opt=SUBSITUDE;
    if(insertWeight< min )
    {
        min=insertWeight;
        opt=INSERT;
    }
    if(delWeight<min)
    {
        min=delWeight;
        opt=DELETE;
    }
    return min;
}

 void MyEditDistance::insertSpaceToList(list<BehaviorObj> &s1,list<BehaviorObj> &s2,BehaviorObj &obj1,BehaviorObj &obj2, int opt)
{
    if(opt==DELETE)
    {
        s1.push_front(obj1);
        BehaviorObj temp=BehaviorObj("_", " ");
        s2.push_front(temp);
        if(PRINTOUT) cout<<"s1 delete "+obj1.getBehaviorName()<<endl;
        
    }
    else if(opt==INSERT)
    {
        
        BehaviorObj temp=BehaviorObj("_", " ");
        s1.push_front(temp);
        s2.push_front(obj2);
        if(PRINTOUT) cout<<"s1 insert "+ obj2.getBehaviorName()<<endl;
        
    }
    else if(opt==KEEP)
    {
        s1.push_front(obj1);
        s2.push_front(obj2);
        if(PRINTOUT) cout<<"s1 keep "+ obj1.getBehaviorName()+" s2 keep "+obj2.getBehaviorName()<<endl;
    }
    else if(opt==SUBSITUDE)
    {
        BehaviorObj temp1=BehaviorObj("_", " ");
        s1.push_front(temp1);
        s1.push_front(obj1);
        s2.push_front(obj2);
        s2.push_front(temp1);
        if(PRINTOUT) cout<<"s1 change "+ obj1.getBehaviorName()+" to "+obj2.getBehaviorName()<<endl;
    }//keep or sub

}

float MyEditDistance::BehaviorEditDistance()
{
    BehaviorObjVector s1=get_s1();
    BehaviorObjVector s2=get_s2();
    size_t len1= s1.size();
    size_t len2= s2.size();
    std::vector<std::vector<float> > &d=get_dMatrix();
    std::vector<std::vector<float> > &opt=get_optMatrix();
    
    d[0][0] = 0;
    for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;
    
    for(unsigned int i = 1; i <= len1; ++i)
    {
        for(unsigned int j = 1; j <= len2; ++j)
        {
            
            if(s1.getIndex(i-1).getBehaviorName() == s2.getIndex(j-1).getBehaviorName())
            {
                d[i][j]=d[i-1][j-1];
                opt[i][j]=KEEP;
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
                //d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),d[i - 1][j - 1] + 1 );
                d[i][j]=currentChoice(opt[i][j], d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1);
                if(i==1&&j!=1)
                {
                    opt[i][j]=INSERT;//d[1][x]special case, when the min value d[0][x-1] is equal to d[1][x-1], we should choose d[1][x-1] rather than d[0][x-1]
                }
                else if(j==1&&i!=1)
                {
                    opt[i][j]=DELETE;//d[x][1]special case, when the min value d[x-1][0] is equal to d[x-1][1], we should choose d[x-1][1] rather than d[x-1][0]
                }            }
        }
    }
    return d[len1][len2];
}

void MyEditDistance::generateInsertSpaceList()
{
    list<BehaviorObj> &src1=get_rS1();
    list<BehaviorObj> &src2=get_rS2();
    BehaviorObjVector &s1=get_s1();
    BehaviorObjVector &s2=get_s2();
    size_t len1= get_s1().size();
    size_t len2= get_s2().size();
    std::vector<std::vector<float> > &d=get_dMatrix();
    std::vector<std::vector<float> > &opt=get_optMatrix();
    
    src1.clear();
    src2.clear();
    unsigned int index_i=(unsigned int)len1;
    unsigned int index_j=(unsigned int)len2;
    while (index_i!=1 && index_j!=1)
    {
        if(PRINTOUT) cout<<"row:"<<index_i<<" col:"<<index_j<<endl;

        unsigned int min=d[index_i-1][index_j-1];
        unsigned int min_i=index_i-1;
        unsigned int min_j=index_j-1;//choice= sub or keep
       
        if(d[index_i-1][index_j]<min)
        {
            min_i=index_i-1;
            min_j=index_j;
            //choice=DELETE;
        }
        if(d[index_i][index_j-1]<min)
        {
            min_i=index_i;
            min_j=index_j-1;
            //choice=INSERT;
        }
        //insertSpaceToList(src1, src2, s1.getIndex(index_i-1), s2.getIndex(index_j-1), choice);
        insertSpaceToList(src1, src2, s1.getIndex(index_i-1), s2.getIndex(index_j-1), opt[index_i][index_j]);

        index_i=min_i;
        index_j=min_j;
    }
    if(index_i==1&&index_j==1)
    {
        if(PRINTOUT) cout<<"row:"<<index_i<<" col:"<<index_j<<endl;
        insertSpaceToList(src1, src2, s1.getIndex(index_i-1), s2.getIndex(index_j-1), opt[index_i][index_j]);
    }
    else
    {
        while(index_i!=0&&index_j==1)
        {
            if(PRINTOUT) cout<<"row:"<<index_i<<" col:"<<index_j<<endl;
        
            insertSpaceToList(src1, src2, s1.getIndex(index_i-1), s2.getIndex(index_j-1), opt[index_i][index_j]);
            index_i--;
        }
        while(index_j!=0&&index_i==1)
        {
            if(PRINTOUT) cout<<"row:"<<index_i<<" col:"<<index_j<<endl;
        
            insertSpaceToList(src1, src2, s1.getIndex(index_i-1), s2.getIndex(index_j-1), opt[index_i][index_j]);
            index_j--;
        }
    }

}

void MyEditDistance::print2DMAtrix(vector<vector <float> > myVector)
{
    for(unsigned int j = 0; j < myVector.size(); ++j)
    {
        for(unsigned int n=0; n < myVector[j].size(); n++)
        {
            cout << myVector[j][n];
            cout << "\t";
        }
        cout << endl;
    }

}

void MyEditDistance::printList(list<BehaviorObj> myList)
{
    list<BehaviorObj>::iterator i;
    for(i= myList.begin(); i!=myList.end(); i++)
    {
        cout<<(*i).getBehaviorName();
    }
    cout<<endl;
}

void MyEditDistance::print_dMatrix()
{
    cout<<"The editDistance matrix is as follows:"<<endl;
    print2DMAtrix(get_dMatrix());
}

void MyEditDistance::print_optMatix()
{
    cout<<"The state transition matrix is as follows:"<<endl;
    print2DMAtrix(get_optMatrix());
}

void MyEditDistance::print_rS1()
{
    cout<<"s1:";
    printList(get_rS1());
}

void MyEditDistance::print_rS2()
{
    cout<<"s2:";
    printList(get_rS2());
}

void MyEditDistance::print_insertSpaceString()
{
    print_rS1();
    print_rS2();
}

