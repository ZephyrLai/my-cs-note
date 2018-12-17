/**
 * 知一组数(其中有重复元素)，求这组数可以组成的所有子集。 结果中无重复的子集。
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 递归回溯
void generate(  int i,
                vector<int> &subVsc,
                vector<int> &numVec,
                set<vector<int>> &numSet,
                vector<vector<int>> &resultVec)
{
    if(i>=numVec.size())    
        return;
    subVsc.push_back(numVec[i]);
    if(numSet.find(subVsc) == numSet.end())
    {
        numSet.insert(subVsc);
        resultVec.push_back(subVsc);
    }
    generate(i+1,subVsc,numVec,numSet,resultVec);
    subVsc.pop_back();
    generate(i+1,subVsc,numVec,numSet,resultVec);
}

int  main(int argc, char const *argv[])
{
    vector<int> numVec;
    numVec.push_back(4);
    numVec.push_back(2);
    numVec.push_back(4);
    numVec.push_back(7);
    numVec.push_back(1);
    numVec.push_back(7);
    cout << "origin array:" << endl;
    for(int i = 0; i < numVec.size(); i++)
    {
       cout << numVec[i] << "," ;
    }
    cout << "" <<endl;

    sort(numVec.begin(),numVec.end());
    cout << "sorted array:" << endl;
    for(int i = 0; i < numVec.size(); i++)
    {
       cout << numVec[i] << "," ;
    }
    cout << "" <<endl;

    vector<int> subVsc;
    set<vector<int>> numSet;
    vector<vector<int>> resultVec;
    generate(0,subVsc,numVec,numSet,resultVec);
    cout << resultVec.size() << endl;

    cout << "final result:" << endl;
    for(int i = 0; i < resultVec.size(); i++)
    {
        for(int j = 0; j < resultVec[i].size(); j++)
        {
           cout <<  resultVec[i][j] ;
        }
        cout << "" <<endl;
    }
    system("pause");
    return 0;
}
