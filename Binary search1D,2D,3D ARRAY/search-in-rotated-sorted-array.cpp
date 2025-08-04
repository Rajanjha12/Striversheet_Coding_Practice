//Method-1 it contain unique elements
class Solution {
public:
    int search( std::vector<int>& nums, int target) {
      
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
        
    }
};
// Time Complexity: O(log n) where n is the size of the array
// Space Complexity: O(1) as we are using constant space for variables
// Note: This code is designed to work with C++17 standard and may not be compatible with earlier versions.
//method-2
int search(vector<int>& arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            return i;
    }
    return -1;
}
// Time Complexity: O(n) where n is the size of the array   
// Space Complexity: O(1) as we are using only a constant amount of extra space