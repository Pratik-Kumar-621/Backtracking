// https://leetcode.com/problems/permutations?envType=problem-list-v2&envId=backtracking

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void createPermutations(vector<int> &nums, int pos,
                            vector<vector<int>> &ans)
    {
        if (pos == nums.size())
        {
            ans.push_back(nums);
        }
        for (int i = pos; i < nums.size(); i++)
        {
            swap(nums[i], nums[pos]);
            createPermutations(nums, pos + 1, ans);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        createPermutations(nums, 0, ans);
        return ans;
    }
};