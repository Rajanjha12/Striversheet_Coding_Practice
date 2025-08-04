/*
Given a sorted array of nums and an integer x, write a program to find the lower bound of x.



The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.



If no such index is found, return the size of the array.


Examples:
Input : nums= [1,2,2,3], x = 2

Output:1

Explanation:

Index 1 is the smallest index such that arr[1] >= x.
*/
//Method-1
int lowerBound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2 Binary Search
 int findFloor(vector<int>& arr, int x) {
        // Your code here
          int low=0;int high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(arr[mid]<=x){
                ans=mid;
                low=mid+1;
                
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
// Time Complexity: O(log n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space