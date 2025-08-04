/*Input: arr[] = [4, 3, 5, 1]
Output: 8
Explanation: All subarrays with at least 2 elements and find the two smallest numbers in each:
[4, 3] → 3 + 4 = 7
[4, 3, 5] → 3 + 4 = 7
[4, 3, 5, 1] → 1 + 3 = 4
[3, 5] → 3 + 5 = 8
[3, 5, 1] → 1 + 3 = 4
[5, 1] → 1 + 5 = 6
Maximum Score is 8.*/
//Method-1 Brute Force Approach
// Time Complexity: O(n^3) Space Complexity: O(1)
int maxScore(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // subarray [i...j]
            vector<int> temp;

            for (int k = i; k <= j; k++) {
                temp.push_back(arr[k]);
            }

            sort(temp.begin(), temp.end());  // sort the subarray

            int sum = temp[0] + temp[1];  // two smallest elements
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}
//Method-2 Optimized Approach 
int maxSum(vector<int> &arr) {
        // code here
   int sum = INT_MIN;
        
        for(int i=0; i<(arr.size()-1); i++){
            sum = max(arr[i] + arr[i+1], sum);
        }
        return sum;
    }
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space except 