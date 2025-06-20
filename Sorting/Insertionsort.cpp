class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        for(int i=i;i<arr.size();i++)
        {
            for(int j=i;j>0;j--)
            {
                if(arr[j]<arr[j-1])
                swap(arr[j-1],arr[j]);
                else
                break;
            }
        }
    }
};
// Time Complexity: O(n^2) in the worst case
// Space Complexity: O(1) for in-place sorting