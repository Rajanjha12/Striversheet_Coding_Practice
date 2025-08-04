//Method: Brute Force

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
         unordered_map<int, int> mp;
        vector<int> ans(3);
        for(int i=0;i<arr.size();i++){
           mp[arr[i]]=i;
        }
         for(int i=0;i<arr.size()-2;i++){
           for (int j=i+1;j<arr.size()-1;j++){
            int sum= arr[i]+arr[j];
            int t=target-sum;
            if(mp.find(t)!=mp.end() && mp[t]!=j && mp[t]!=i){
               return true;
            }
          }
        }

       return false;
    
    }
};
//Time Complexity: O(n^2) where n is the size of the array
//Space Complexity: O(n) for storing the elements in the unordered_map
