// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?page=1&category=Backtracking&sortBy=submissions

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

void generatePermutation_Recursive( string s, string output, vector<string> &ans)
{
    if(s.size()==0){
        ans.push_back(output);
        return;
    }
    for(int i=0; i<s.size();i++){
        string outp=output+s[i];
        string new_inp = s.substr(0,i)+s.substr(i+1);
        generatePermutation_Recursive( new_inp, outp, ans );
    }
}

void generatePermutation(int n, int start, string &s, vector<string> &ans)
{
    if(start==n-1){
        ans.push_back(s);
    }
    for(int i=start; i<n; i++){
        swap(s[i],s[start]);
        generatePermutation(n,start+1,s,ans);
        swap(s[i],s[start]);
    }
}



vector<string> find_permutation(string S)
{
    int n = S.size();
    vector<string> ans;
    // generatePermutation_Recursive( S, "", ans);
    generatePermutation(n,0 ,S, ans);
    printVecStr(ans);
    return ans;
}

int main()
{
    string S;
    cin >> S;
    vector<string> ans = find_permutation(S);
}