//Method-1 Brute Force
// Time Complexity: O(n^2) where n is the size of the array
int missingNumber(vector<int>&a, int N) {

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}
//Method-2 Optimal Approach using 
int missingNumber(vector<int>& nums) {
      int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int num=(n*(n+1))/2;
        return num-sum;
    }
    // Time Complexity: O(n) where n is the size of the array