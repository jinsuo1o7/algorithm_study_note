// 2022.06.10
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int ans = 0, i = 0, j = 0;
    while (i < s.size() && j < s.size()) {
      if (map[s[j]] == 0) {
        map[s[j]]++;
        j++;
        ans = max(ans, j - i);
      } else {
        map[s[i]]--;
        i++;
      }
    }
    return ans;
  }
};

class Solution2 {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int ans = 0, i = 0, j = 0;
    while (i < s.size() && j < s.size()) {
      if (set.find(s[j]) == set.end()) {
        set.insert(s[j]);
        j++;
        ans = max(ans, j - i);
      } else {
        set.erase(s[i]);
        i++;
      }
    }
    return ans;
  }
};