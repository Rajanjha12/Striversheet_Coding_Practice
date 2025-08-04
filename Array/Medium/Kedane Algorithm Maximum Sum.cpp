//Method-1 Brute Force Approach
// Time Complexity: O(n^3) Space Complexity: O(1)

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}
//Method-2
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}
//Time Complexity: O(n^2)  
// Space Complexity: O(1) 
//Method-3 Optimal Approach using Kadane's Algorithm
 int maxSubArray(vector<int>& nums) {
         long long maxi=INT_MIN,prefix=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            maxi=max(maxi,prefix);
        if(prefix<0)
        prefix=0;
        }
         
        return maxi;
    }