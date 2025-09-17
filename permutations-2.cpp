// https://leetcode.com/problems/permutations-ii/description/?envType=problem-list-v2&envId=backtracking
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void createPermutations(vector<int> &nums, int pos, set<vector<int>> &sol)
    {
        if (pos == nums.size())
        {
            sol.insert(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            swap(nums[i], nums[pos]);
            createPermutations(nums, pos + 1, sol);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> sol;
        vector<vector<int>> ans;
        createPermutations(nums, 0, sol);
        for (auto it : sol)
            ans.push_back(it);
        return ans;
    }
};