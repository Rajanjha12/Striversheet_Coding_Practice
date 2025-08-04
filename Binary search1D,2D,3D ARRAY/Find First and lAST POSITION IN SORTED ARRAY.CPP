/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]*/
//Method-1
int solve(int n, int key, vector < int > & v) {
  int res = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] == key) {
      res = i;
      break;
    }
  }
  return res;
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2 Binary Search
vector<int> searchRange(vector<int>& nums, int target) {
        return {binary(nums, target, true), binary(nums, target, false)};
    }

    int binary(vector<int>& nums, int target, bool findFirst) {
        int s = 0, e = nums.size() - 1, ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (target > nums[mid]) {
                s = mid + 1;
            } else if (target < nums[mid]) {
                e = mid - 1;
            } else {
                ans = mid;
                if (findFirst)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
        }
        return ans;
    }
    // Time Complexity: O(log n) where n is the size of the array
    // Space Complexity: O(1) as we are using only a constant amount of extra