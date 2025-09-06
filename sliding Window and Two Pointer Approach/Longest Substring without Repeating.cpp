/*Given a string s, find the length of the longest substring without duplicate characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.*/

//Method-1 time  complexity o(n3) and space complexity o(n)
#include <bits/stdc++.h>
using namespace std;

bool allUnique(string s, int start, int end) {
    vector<bool> visited(256, false);
    for (int i = start; i <= end; i++) {
        if (visited[s[i]]) return false;
        visited[s[i]] = true;
    }
    return true;
}

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {            // Start index
        for (int j = i; j < n; j++) {        // End index
            if (allUnique(s, i, j)) {        // Check uniqueness
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}
// Method-2 Time complexity-o(n2)and space complexity o(n)
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {       // Start index
        unordered_set<char> seen;       // Characters in current substring
        for (int j = i; j < n; j++) {   // End index
            if (seen.find(s[j]) != seen.end()) {
                break; // Duplicate found → stop expanding
            }
            seen.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
// method-3 t.c:O(N) and space complexity O(1) Sliding Window Approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>count(256,0);
        int first=0,second=0,len=0;
        while(second<s.size())
        {
            while(count[s[second]])
            {
                count[s[first]]=0;
                first++;
            }
            count[s[second]]=1;
            len=max(len,second-first+1);
            second++;
        }
        return len;
    }
};
