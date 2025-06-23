//Method-1
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here 
        int n=arr.size();
     int MAX=arr[0];
     for(int i=0;i<n-1;i++)
     {
         for(int j=i+1;j<n;j++)
         {
             MAX=max(MAX,arr[j]);
         }
     }
     return MAX;
    }
};
//Time Complexity: O(n^2) where n is the size of the array
//Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2 Two Pointer used in when sorted array it is not correcr solution as it will not work for unsorted array but ansswer aajeyga you know 
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here 
        int n=arr.size();
     int MAX=arr[0];
     int start=0,end=n-1;
     while(start<end)
     {
         if(arr[start]<arr[end])
         {
             MAX=max(MAX,arr[end]);
             start++;
         }
         else
         {
             MAX=max(MAX,arr[start]);
             end--;
         }
     }
     return MAX;
    }
};
//Time Complexity: O(n) where n is the size of the array
//Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-3
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here 
        
     sort(arr.begin(),arr.end());
     return arr[arr.size()-1];
    }
};
//Time Complexity: O(nlogn) where n is the size of the array
//Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-4
class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxVal = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxVal = max(maxVal, arr[i]);
        }
        return maxVal;
    }
};
//Best Method
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space