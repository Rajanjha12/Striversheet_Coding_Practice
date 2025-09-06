/* You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/
// method-1 Sliding Window 
int characterReplacement(string s, int k){
int ans = 0, n = s.size();
        for(char c = 'A'; c <= 'Z'; c++)
        {
            int i = 0, j = 0, replaced = 0;
            while(j < n)
            {
                if(s[j] == c)
                    j++;
                else if(replaced < k)
                    j++, replaced++;
                else if(s[i] == c)
                    i++;
                else
                    i++, replaced--;
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
        // T.C : O(26 * n) and S.C : O(1) - ignoring the space taken by s string
        //Method-2 STl
        class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int res = 0, i = 0, maxFreq = 0;

        for (int j = 0; j < s.size(); j++) {
            freqs[s[j]]++;
            maxFreq = max(maxFreq, freqs[s[j]]);

            while ((j - i + 1) - maxFreq > k) {
                freqs[s[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};
// T.C : O(n) and S.C : O(1) - ignoring the space taken by freqs unordered_map