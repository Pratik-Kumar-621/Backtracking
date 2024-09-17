// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

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

void printAllPaths(int n, int m, vector< vector<int> > &mat, vector<string> &ans) {}

vector<string> findPath(vector< vector<int> > &mat)
{
    vector<string> ans;
    int n = mat.size(), m = mat[0].size();
    printAllPaths(n, m, mat, ans);
    printVecStr(ans);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > mat;

    for (int i = 0; i < n; i++)
    {
        vector<int> tempV;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            tempV.push_back(temp);
        }
        mat.push_back(tempV);
        tempV.empty();
    }
    findPath(mat);
}