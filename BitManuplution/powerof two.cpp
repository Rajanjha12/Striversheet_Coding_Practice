/*Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.
Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
           if(n<1)
        return 0;
        if(n==1)
        return 1;
        while(n!=1)
        {
            if(n%2==1)
            return 0;
            n=n/2;
        }
        return 1;
    }
};
//Time Complexity: O(log n)
//Space Complexity: O(1)
//Method-2
class Solution {
public:
    bool isPowerOfTwo(int n) {
            if(n==0) return false;

        int bit=0;
        while(n!=0){
            if(bit==1) return false;
            bit = n&1;
            n=n>>1; 
        }
        return true;
    }
};
//Time Complexity: O(log n)
//Space Complexity: O(1)