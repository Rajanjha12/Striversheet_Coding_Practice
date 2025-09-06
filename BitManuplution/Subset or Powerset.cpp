/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]*/
//Method-1
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         int n = nums.size();
        vector<vector<int>> subsets;
        
        for(int i=0; i<pow(2, n); i++) {
            int j=0;
            vector<int> subset;
            while(j<n) {
                if(i & (1<<j)) {
                    subset.push_back(nums[j]);
                }
                j++;
            }
            subsets.push_back(subset);
        }
        
        return subsets;
    }
};
// Time Complexity: O(n * 2^n), where n is the number of elements in the input array nums.
// Space Complexity: O(n * 2^n), where n is the number of elements
//Mwthod-2
