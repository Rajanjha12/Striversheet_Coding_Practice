class Solution {
 
   void merge(vector<int>&nums,int start,int mid,int end)
{
    vector<int>temp(end-start+1);
    int left=start,right=mid+1,index=0;
    while(left<=mid&&right<=end)
    {
        if(nums[left]<=nums[right])
        {
            temp[index]=nums[left];
            index++,left++;
        }
        else
        {
            temp[index]=nums[right];
            index++,right++;
        }
    }
    //Left array bechha hua toh
    while(left<=mid)
    {
        temp[index]=nums[left];
        index++,left++;
    }
//right array bechha hu toh
    while(right<=end)
    {
        temp[index]=nums[right];
        index++,right++;
    }
    //Put the value in array
 index=0;
    while(start<=end)
    {
        nums[start]=temp[index];
        index++,start++;
    }
}
 public:
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;  // Base case

    int m = l + (r - l) / 2;

    // Recursively sort the two halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
}

};
// Time Complexity: O(n log n) for the merge sort algorithm
// Space Complexity: O(n) for the temporary array used in merging