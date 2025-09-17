// https://leetcode.com/problems/combination-sum/description/?envType=problem-list-v2&envId=backtracking

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void createCombinations(vector<int> &candidates, int target, vector<int> &currentComb, int sum, int pos, vector<vector<int>> &ans)
    {
        if (pos == candidates.size())
            return;
        if (sum == target)
        {
            ans.push_back(currentComb);
            return;
        }

        if (candidates[pos] <= target - sum)
        {
            currentComb.push_back(candidates[pos]);
            sum += candidates[pos];
            createCombinations(candidates, target, currentComb, sum, pos, ans);
            sum -= candidates[pos];
            currentComb.pop_back();
        }
        createCombinations(candidates, target, currentComb, sum, pos + 1, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> currentComb;
        createCombinations(candidates, target, currentComb, 0, 0, ans);
        return ans;
    }
};