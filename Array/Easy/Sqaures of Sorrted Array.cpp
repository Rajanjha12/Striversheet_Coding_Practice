class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> res(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;   
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)
// Method-2 Space optimised
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        // We'll overwrite nums from the back
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                nums[i] = nums[left] * nums[left];
                left++;
            } else {
                nums[i] = nums[right] * nums[right];
                right--;
            }
        }
        return nums;  // in-place result
    }
};
