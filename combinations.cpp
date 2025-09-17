// https://leetcode.com/problems/combinations/?envType=problem-list-v2&envId=backtracking
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void createCombinations(int n, int k, vector<int> &currentComb,
                            vector<vector<int>> &ans, int pos)
    {
        if (currentComb.size() == k)
        {
            ans.push_back(currentComb);
            return;
        }
        if (pos > n)
            return;

        currentComb.push_back(pos);
        createCombinations(n, k, currentComb, ans, pos + 1);
        currentComb.pop_back();

        createCombinations(n, k, currentComb, ans, pos + 1);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> currentComb;

        createCombinations(n, k, currentComb, ans, 1);

        return ans;
    }
};