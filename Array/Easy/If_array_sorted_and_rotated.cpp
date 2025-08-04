/*Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int i,count=0;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1]) count++;
            
         }if(nums[nums.size()-1]>nums[0]) count++;
         if(count<=1)return true;
         return false;
    }
};
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space