//Method-1
// Find the minimum element in a rotated sorted array
// This method assumes that the array is rotated and contains unique elements.
#include <vector>
#include <limits.h>
using namespace std;
int findMin(vector<int>& arr) {
    int n = arr.size(); // size of the array.
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        // Always keep the minimum.
        mini = min(mini, arr[i]);
    }
    return mini;
}
// Time Complexity: O(n) where n is the size of the array   
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0,end=nums.size()-1,mid;
        while(start<end)
        {
            mid=start+(end-start)/2;
             if(nums[mid]> nums[end])
             {start=mid+1;
             }
             else
             {end=mid;
             }
        }
        return nums[end];
    }
};
// Time Complexity: O(log n) where n is the size of the array
// Space Complexity: O(1) as we are using constant space for variables
// Note: This code is designed to work with C++17 standard and may not be compatible with earlier versions.