// https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1?page=1&category=Backtracking&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

void printVecInt(vector<int> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

void printVec2Int(vector< vector<int> > &v)
{
    for (auto it : v)
    {
        for (auto it1 : it)
            cout << it1 << " ";
        cout << endl;
    }
    cout << endl;
}

void printVecStr(vector<string> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

void largestNumber(int k, int start, string &s, string &res)
{
    if(k==0 || start==s.size()-1){
        return;
    }
    int maxelem = *max_element(s.begin()+start,s.end());

    for(int i=start+1; i<s.size();i++){
        if(s[i]==maxelem && s[i]>s[start]){
            swap(s[i],s[start]);
            if(s>res){
                res = s;
            }
            largestNumber(k-1,start+1,s,res);
            swap(s[i],s[start]);
        }
    }
    largestNumber(k,start+1,s,res);
}

string findMaximumNum(string str, int k)
{
    int n = str.size();

    string res = str;
    largestNumber(k, 0, str, res);
    cout << res;
    return res;
}

int main()
{
    int k;
    cin >> k;
    string str;
    cin >> str;

    string ans = findMaximumNum(str, k);
}