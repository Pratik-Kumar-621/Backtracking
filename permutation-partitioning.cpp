#include <bits/stdc++.h>

using namespace std;

void printVecStr(vector< vector<string> > &v)
{
    for (auto it : v)
    {
        for (auto it1 : it)
            cout << it1 << " ";
        cout << endl;
    }
        cout << endl;
}

void generatePermutations(string &S, int n, int start, vector< vector<string> > &ans){}

vector< vector<string> > allPalindromicPerms(string S) {
    vector< vector<string> > ans;
    int n = S.size();
    generatePermutations(S,n,0,ans);
    printVecStr(ans);
}


int main(){
    string s;
    cin >> s;
    vector< vector<string> > ans = allPalindromicPerms(s);    
}