//Method-1
int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    for (int i = 0; i < n; i++) {
        //Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i])
                && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2
int findPeakElement(vector<int>& nums) {
          int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;       

    }
// Time Complexity: O(log n) where n is the size of the array
// worest case: O(n) if the array is strictly increasing or decreasing
//best case: O(1) if the peak is at the first or last element
// Space Complexity: O(1) as we are using constant space for variables
// Note: This code is designed to work with C++17 standard and may not be compatible with earlier versions.