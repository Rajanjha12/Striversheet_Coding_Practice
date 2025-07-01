//Method-1 Brute Force Approach Time Complexity: O(n^3) Space Complexity: O(1)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += arr[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
    }
};
//Method-2 
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
// Time Complexity: O(n^2) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space