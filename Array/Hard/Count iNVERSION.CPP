/*Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/
// //Method-1
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int count=0;
        for(int i=0;i<=arr.size()-2;i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[i]>arr[j])
                count++;
            }
        }
        return count;
    }
};
// // Time Complexity: O(n^2) where n is the size of the array
// // Space Complexity: O(1) as we are not using any extra space
// //Method-2 Optimal Approach using Merge Sort
int merge(vector<int>& arr, int l,int m, int r) {
         vector<int>temp;
         int count = 0;
         int left = l;
         int right = m+1;
          while(left<=m && right <= r){
              if(arr[left] <= arr[right]){
                  temp.push_back(arr[left]);
                  left++;
              }
              else{
                  temp.push_back( arr[right]);
                  right++;
                  count+= m-left+1;
              }
          }
          while(left<=m){
            temp.push_back(arr[left]);
            left++;  
          }
          while(right<=r){
            temp.push_back( arr[right]);
            right++;  
          }
          for(int i =l ; i<=r; i++){
              arr[i] = temp[i-l];
          }
          return count;
     }
int mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r) return 0;
        int m = (l+r)/2;
        int first= mergeSort(arr, l , m);
        int second = mergeSort(arr , m+1, r);
        int final =  merge(arr, l , m , r);
        return first+second+final;
    }
     
class Solution {
  public:
    // Function to count inversions in the array.
    
    int inversionCount(vector<int> &arr) {
    return mergeSort(arr,0,arr.size()-1);
    }
};
// // Time Complexity: O(nlogn) where n is the size of the array
// // Space Complexity: O(n) for the temporary array used in merge function