/*Given two positive integer n and  k, check if the kth index bit of n is set or not.
 Note: A bit is called set if it is 1. 

Examples : 

Input: n = 4, k = 0
Output: false
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
Input: n = 4, k = 2
Output: true
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.*/
//Using Bit Masking
//Time Complexity: O(log n)
//Space Complexity: O(1)
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        int mask=1,i=0;
        while(i<k)
        {
            mask<<=1;
            i+=1;
        }
        //after the loop,mask will be 100 or 1000 or 10000 etc. depending on the value of k
        if((n&mask)!=0)
        return 1;
        return 0;
    }
};