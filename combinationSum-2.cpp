// https://leetcode.com/problems/combination-sum-ii/description/?envType=problem-list-v2&envId=backtracking

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void createCombinations(vector<int> &candidates, int target, vector<int> &currentComb, vector<vector<int>> &ans, int pos)
    {
        if (target == 0)
        {
            sort(currentComb.begin(), currentComb.end());
            ans.push_back(currentComb);
            return;
        }
        if (pos == candidates.size() || 0 > target)
            return;

        for (int i = pos; i < candidates.size(); i++)
        {
            if (i > pos && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
            {
                break;
            }
            currentComb.push_back(candidates[i]);
            createCombinations(candidates, target - candidates[i], currentComb, ans, i + 1);
            currentComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> currentComb;

        createCombinations(candidates, target, currentComb, ans, 0);

        return ans;
    }
};