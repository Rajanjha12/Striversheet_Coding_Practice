/*Given a non-negative number n . The problem is to set the rightmost unset bit in the binary representation of n.

Examples :

Input: n = 6
Output: 7
Explanation: The binary representation of 6 is 110. After setting right most bit it becomes 111 which is 7.*/

class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
          n = n | n+1; 
        return n;
    }
};
//Time Complexity: O(log n)
//Space Complexity: O(1)