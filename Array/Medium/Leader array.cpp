//Method-1 optimal

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int>ans;
        // Code here
      int maxI=INT_MIN;
      int i;
      for(i=n-1;i>=0;i--)
      {
          if(arr[i]>=maxI)
          {
              ans.push_back(arr[i]);}
              maxI=max(maxI,arr[i]);
          
      }sort(ans.begin(),ans.end(), greater<int>());
        return ans;
    }
};
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) as we are using an extra vector to store the leaders
//Method-2 Brute Force Approach


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
         vector<int> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}
};
// Time Complexity: O(n^2) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space except the output
 