class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i=0;i<n;i++)
        {
            int Left=2*i+1;
            int Right =2*i+2;
            if(arr[i]<arr[Left] || arr[i]<arr[Right])
            return 0;
        }
        return 1;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)