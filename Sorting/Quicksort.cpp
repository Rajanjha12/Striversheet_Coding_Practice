class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
        int index=partition(arr,low,high);
        quickSort(arr,low,index-1);
        quickSort(arr,index+1,high);
        }
      
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pivot=arr[low];
        int i=low;
        int j=high;
        while(i<j)
        {
            while(arr[i]<=pivot&&i<=high-1)
            {
                i++;            }
        
        while(arr[j]>pivot&&j>low)
        {
            j--;
        }
        if(i<j)swap(arr[i],arr[j]);
        }
         swap(arr[low],arr[j]);
    return j;
    }
};
// Time Complexity: O(n log n) on average, O(n^2) in the worst case
//sc=o(1) for in-place partitioning
// Space Complexity: O(log n) for the recursive stack space