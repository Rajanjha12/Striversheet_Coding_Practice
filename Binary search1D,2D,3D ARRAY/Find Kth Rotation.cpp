//Method-1
// Find the index of the minimum element in a rotated sorted array
// This method assumes that the array is rotated and may contain duplicate elements.
#include <vector>
#include <limits.h>
using namespace std;
int findKRotation(vector<int> &arr) {
    int n = arr.size(); //size of array.
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < ans) {
            ans = arr[i];
            index = i;
        }
    }
    return index;
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space
// Note: This code is designed to work with C++17 standard and may not be compatible with earlier versions.
// Method-2
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
       int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;

    }
};
// Time Complexity: O(log n) where n is the size of the array
// Space Complexity: O(1) as we are using constant space for variables
// Note: This code is designed to work with C++17 standard and may not be compatible with earlier versions.