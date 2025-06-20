  //Brute Force Approach
// Time Complexity: O(2^n)  Best case:o(1),worst case: O(2^n)
// Space Complexity: O(n) for recursion stack
  
  int fib(int n) {
     if(n<=1)
     return n;
     return fib(n-1)+fib(n-2);
    }
// Optimized Approach
//DP