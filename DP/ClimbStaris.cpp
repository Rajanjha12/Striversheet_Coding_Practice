Method-1 Recursion
class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {

        // your code here
        if(n==0)
        return 1;
        if(n<0)
        return 0;
        return countWays(n-1)+countWays(n-2)+countWays(n-3);
    }
};
//Time Complexity: O(3^n) (exponential) Space Complexity: O(n) (due to recursion stack)

//Method-2 Top Down Approach
class Solution {
  public:
  
    // Function to count the number of ways in which frog can reach the top.
    int ways(int i,int n,vector<int>&dp)
    {
        if(i==n)
        return 1;
        if(i>n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        return dp[i]=(ways(i+1,n,dp))+(ways(i+2,n,dp))+(ways(i+3,n,dp));
    }
    int countWays(int n) {

        // your code here
       vector<int>dp(n+1,-1);
       return ways(0,n,dp);
    }
    
};
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) (recursion stack space + dp array