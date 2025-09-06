/*Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.
Examples:

Input: arr[] = [2, 1, 2]
Output: 3
Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5.*/

// Method-1
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
             int res=0;
        unordered_map<int,int>mp;
        int i=0;
        for(int j=0; j<arr.size(); j++){
            int x=arr[j];
            mp[x]++;
            while(mp.size()>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                mp.erase(arr[i]);
                i++;
            }
            res=max(res,j-i+1);
            
        }
        return res;
    }
};
// T.C : O(n) and S.C : O(1) - ignoring the space taken by mp unordered_map
// Method-2 Sliding Window Approach
 int totalElements(vector<int> &arr) {
        // code here
        int ans = 0;
        unordered_map<int, int>mp;
        int i=0;
        int j=0;
        int n = arr.size();
        while(j<n){
            if(mp.size()>2){
                while(i<j && mp.size() > 2){
                    mp[arr[i]]--;
                    if(mp[arr[i]] == 0){
                        mp.erase(arr[i]);
                    }
                    i++;
                }
                j++;
            }
            else{
                mp[arr[j]]++;
                if(mp.size() <=2){
                  ans = max(ans, j-i+1);
                 j++;
                }
            }
        }
        return ans;
    }
    
// T.C : O(n) and S.C : O(1)