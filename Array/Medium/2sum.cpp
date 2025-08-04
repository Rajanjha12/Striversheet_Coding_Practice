//Method-1 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        { for(int j=i+1;j<n;j++)
          {  if(nums[i]+nums[j]==target)
            {
                return {i,j};
        
        break;
            }
          }
        
    
        }
    
     return{-1,-1};
    }   
};
// Time Complexity: O(n^2) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2 It is valid only for sorted array Two pointer approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {  
        int start=0,end=nums.size()-1;
        while(start<end)
        {
            if(nums[start]+nums[end]==target)
            return {start,end};
            else
            {
                if(nums[start]+nums[end]>target)
                end--;
                else
                start++;
            }
        }
        return{-1,-1};
    }
    
};
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-3 Hashing Approach
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; // indices of the two numbers
        }
        mp[nums[i]] = i; // store current number with its index
    }

    return {-1, -1}; // no pair found
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) for the hash map to store the elements and their indices