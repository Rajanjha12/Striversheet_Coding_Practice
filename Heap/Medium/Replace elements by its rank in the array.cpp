/*
Input:
N = 6
arr = [20, 15, 26, 2, 98, 6]
Output:
4, 3, 5, 1, 6, 2
Explanation:
After sorting, array becomes {2,6,15,20,26,98}
Rank(2) = 1 (at index 0) 
Rank(6) = 2 (at index 1) 
Rank(15) = 3 (at index 2) 
Rank(20) = 4 (at index 3) and so on..*/


// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
         vector<int> ans;
        map<int,int> mp;
        vector<int> temp =arr;
        sort(temp.begin(),temp.end());
        int rank =1;
        
        for (int i =0;i < N;i++) {
            if (mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = rank;
                /*Suppose you have:
temp = [2, 2, 6, 15]
Without this if, you would assign:
2 -> 1
2 -> 2 (wrong, duplicate got new rank)
With this check:
2 -> 1 (first time only)
2 -> skipped (since already in map)
6 -> 2
15 -> 3
 */
                rank++;
            }
        }
        for (auto i:arr) {
            ans.push_back(mp[i]);
        }
        return ans;     
    }
};
// Time Complexity: O(N log N)
// Space Complexity: O(N)