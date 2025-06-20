//example:  "A man, a plan, a canal: Panama"
//Remove all non-alphanumeric characters and convert to lowercase
 class Solution {
public:
    bool isPalindrome(string s) {
                 int n = s.length();
        int start = 0;
        int end = n-1;

        while(start<end) {
            if(!isalnum(s[start])) {// If the character at start is not alphanumeric, move start forward
                start++;
            } 
            else if(!isalnum(s[end])) {
                end--;
            }
            else {
                if(tolower(s[start]) != tolower(s[end])) {// If the characters at start and end are not equal, return false
                    return false;
                }

                start++;
                end--;
            }
        }
        return true;

    }
};
//Twopointer Approach
// Time Complexity: O(n) 
// Space Complexity: O(1) 