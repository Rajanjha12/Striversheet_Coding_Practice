/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int result = 0;
        vector<int> mp(3, 0); //0 - a, 1 - b, 2 - c
        int i = 0;
        int j = 0;
        while(j < n) {
            char ch = s[j];
            mp[ch-'a']++;
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                result += (n - j);
                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return result;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)