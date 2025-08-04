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
// Method-3 Optimal Approach using Hashing
class Solution {
  public:
    int longestSubarray(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<long long, int> prefixSumIndex;
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];

            if (sum == k) {
                maxLen = i + 1;
            }

            if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
                int len = i - prefixSumIndex[sum - k];
                maxLen = max(maxLen, len);
            }

            if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) for the hash map used to store prefix sums and their indices
  int longestSubarray(vector<int>& a, int k) {
        // code here
  int n = a.size();  

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
     
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
 
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
 
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
    }
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space 
// only it is used for  positive integers