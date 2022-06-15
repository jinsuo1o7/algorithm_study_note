// 2022.06.15
// https://leetcode.com/problems/longest-string-chain/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  static bool compare(const string &s1, const string &s2) {
    return s1.length() < s2.length();
  }

  int longestStrChain(vector<string> &words) {
    sort(words.begin(), words.end(), compare);
    unordered_map<string, int> dp;
    int res = 0;
    for (string w : words) {
      for (int i = 0; i < w.length(); i++) {
        string pre = w.substr(0, i) + w.substr(i + 1);
        dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
      }
      res = max(res, dp[w]);
    }
    return res;
  }
};