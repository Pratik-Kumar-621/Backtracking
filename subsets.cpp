// https://leetcode.com/problems/subsets/description/?envType=problem-list-v2&envId=backtracking

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void createSubsets(vector<int> &nums, int pos, vector<vector<int>> &ans, vector<int> &currentComb)
    {

        if (pos == nums.size())
        {
            ans.push_back(currentComb);
            return;
        }

        currentComb.push_back(nums[pos]);
        createSubsets(nums, pos + 1, ans, currentComb);
        currentComb.pop_back();

        createSubsets(nums, pos + 1, ans, currentComb);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> currentComb;
        createSubsets(nums, 0, ans, currentComb);

        return ans;
    }
};