/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.*/
// Method-Brute Force 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        for(int i=0;i<nums.size();i++)
        {
       int zero=0;
            for(int j=i;j<nums.size();j++)
               {
                if(nums[j]==0)
                zero++;
                if(zero<=k)
                {
                   int len=j-i+1;
                    maxlen=max(maxlen,len);
                }
                else 
                break;

               }
 
                 }
                    return maxlen;
        
    }
};
// T.C : O(n^2) and S.C : O(1) - ignoring the space taken by nums vector
// Method-2 Sliding Window Approach
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int maxlen=0,l=0,r=0,Zeros=0;
         while(r<nums.size())
         {
            if(nums[r]==0) Zeros++;
            while(Zeros>k)
            {
               if(nums[l]==0) Zeros--;
               l++;
            }
            if(Zeros<=k){
                int len=r-l+1;
                maxlen=max(len,maxlen);
            }
            r++;
         }
        return maxlen;
    }
};
// T.C : O(n) and S.C : O(1) - ignoring the space taken by nums vector