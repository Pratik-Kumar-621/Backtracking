// https://www.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1

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

void nDigitNumbers(int n, vector<int> &ans, int num)
{
    if(n==0) {
        ans.push_back(num);
        return;
    }
    for(int i =1; i<=9;i++){
        if(i>num%10){
            num = (num*10)+i;
            nDigitNumbers(n-1,ans,num);
            num/=10;
        }

    }
}

vector<int> increasingNumbers(int n)
{
    vector<int> ans;
    if(n==1) ans.push_back(0);
    nDigitNumbers(n, ans,0);
    printVecInt(ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans = increasingNumbers(n);
}