/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.*/
//Method-1
class Solution {
public:
    string largestOddNumber(string num) {
        int n= num.size(),i;
       for(i=n-1;i>=0;i--)
       {
        if((num[i]-'0')%2!=0)
        return num.substr(0,i+1);
       }
       return "";

    }
};// O(n) and time complexity and O(1) space complexity
//Method-2
string largestOddNumber(string num) {
    string result = "";

    // Check every prefix from longest to shortest
    for (int len = num.size(); len >= 1; len--) {
        string prefix = num.substr(0, len);
        char lastDigit = prefix.back();
        if ((lastDigit - '0') % 2 != 0) {
            result = prefix;
            break;
        }
    }

    return result;
}
//Time complexity O(n2) and space n(1) space complexity tempory sub string