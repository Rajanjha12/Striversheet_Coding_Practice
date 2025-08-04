/*Example 1: it question is duplicate elemen
 contain 
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false */
//Method-1
bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) return true;
    }
    return false;
}
// Time Complexity: O(n) where n is the size of the array   
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2
class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return true;

            if (nums[low] == nums[mid]) {
                low++; // If the leftmost element is equal to mid, we cannot determine the sorted half
                high--;// Reduce the search space when duplicates are found
                
                continue; // Skip duplicates at the start
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) high = mid    - 1;
                else low = mid + 1;
            } else {
                if (nums[mid] <= target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }
};
// Time Complexity: O(log n) where n is the size of the array
// Space Complexity: O(1) as we are using constant space for variables
// Note: This code is designed to work with C++17 standard and may not be compatible with earlier versions.