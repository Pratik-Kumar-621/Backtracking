// https://leetcode.com/problems/letter-combinations-of-a-phone-number
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void createCombinations(string &digits, vector<string> &ans, string &currentString, vector<string> &letterMapping, int start)
    {
        if (currentString.size() == digits.size())
        {
            ans.push_back(currentString);
            return;
        }
        for (int i = start; i < digits.size(); i++)
        {
            int currentDigit = digits[i] - '0';
            string targetMap = letterMapping[currentDigit - 2];
            for (int j = 0; j < targetMap.size(); j++)
            {
                currentString.push_back(targetMap[j]);
                createCombinations(digits, ans, currentString, letterMapping, i + 1);
                currentString.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        vector<string> letterMapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string currentString = "";
        if (digits.size() == 0)
            return ans;

        createCombinations(digits, ans, currentString, letterMapping, 0);

        return ans;
    }
};