//Method-1 optimal Anawer t.c= O(n) and s.c=O(1) contain unique elements
/*
Input: nums = [1,1,2]
Output: 2,nums = [1,2,_]
*/
 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        for( int j=1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};
//Method-2 Brute Force 
 set<int> set;
    for (int i = 0; i < nums.size(); i++) {
        set.insert(nums[i]);
    }
    return set.size();
    // Time.com= O(nlogn) where n is the size of the array
    // Space.com= O(n) as we are using a set to store unique elements