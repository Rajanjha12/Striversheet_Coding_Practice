/*Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false*/
//Method-1
class Solution {
public:
    bool isAnagram(string s, string t) {
         
         int n=s.size();
          vector<int>count(26,0);
             if(s.size()>t.size()||s.size()<t.size())
             return false;
          for(int i=0;i<n;i++)
          {
                    count[s[i]-'a']++;
                    count[t[i]-'a']--;
          }
          for(int i=0;i<26;i++)
          {
            if(count[i]!=0)
            return false;
          }
          return true;

    }
};
// o(n) time and o(1) space;
//Method-2
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for (auto x : s) {
            count[x]++;
        }
        
        // Decrement the frequency of characters in string t
        for (auto x : t) {
            count[x]--;
        }
        
        // Check if any character has non-zero frequency
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};
//time ans space O(n) and O(1)