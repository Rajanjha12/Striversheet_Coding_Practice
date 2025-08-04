/*
Given an integer n, find its factorial. Return a list of integers denoting the digits that make up the factorial of n.

Examples:

Input: n = 5
Output: [1, 2, 0]
Explanation: 5! = 1*2*3*4*5 = 120
Input: n = 10
Output: [3, 6, 2, 8, 8, 0, 0]
Explanation: 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
*/
//Method-1: Using vector to store digits
// User function template for C++

class Solution {
      
  public:
  void multiply(vector<int>& nums, int &size, int &multiplier) {
        int carry = 0;
    
        for(int i = 0; i<size; i++) {
            int result = (multiplier*nums[i])+carry;
    
            nums[i]   = result%10;
    
            carry     = result/10;
        }
    
        while(carry) {
            nums[size] = carry%10;
            size++;
            carry /= 10;
        }
    }
    vector<int> factorial(int n) {
        // code here
        vector<int> nums(10000, 0);
        nums[0] = 1;
        int size = 1;
        int fact = n;
    
    
        for(int multiplier = 2; multiplier<=fact; multiplier++)
            multiply(nums, size, multiplier);
        
        vector<int> result;
        for(int i = size-1; i>=0 ; i--)
            result.push_back(nums[i]);
        return result;
    }
};
// Time Complexity: O(n^2) in the worst case, where n is the number of digits in the factorial
// Space Complexity: O(n) for storing the digits of the factorial in a vector
 