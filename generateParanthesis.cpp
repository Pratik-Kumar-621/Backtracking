// https://leetcode.com/problems/generate-parentheses/dexscription/?envType=problem-list-v2&envId=backtracking

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void createParanthesis(int n, int posCount, int negCount,
                           string &currentPar, int start, vector<string> &ans)
    {
        if (start == 2 * n)
        {
            ans.push_back(currentPar);
            return;
        }

        if (posCount)
        {
            currentPar.push_back('(');
            createParanthesis(n, posCount - 1, negCount + 1, currentPar,
                              start + 1, ans);
            currentPar.pop_back();
        }
        if (negCount)
        {
            currentPar.push_back(')');
            createParanthesis(n, posCount, negCount - 1, currentPar, start + 1,
                              ans);
            currentPar.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {

        int posCount = n, negCount = 0;
        vector<string> ans;
        string currentPar = "";

        createParanthesis(n, posCount, negCount, currentPar, 0, ans);

        return ans;
    }
};