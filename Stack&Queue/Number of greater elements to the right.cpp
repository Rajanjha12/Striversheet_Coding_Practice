/*Given an array of arr[] and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).

Examples :

Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output:  [6, 1]
Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.*/

class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
          vector<int> res;
        for(int i=0; i<indices.size(); i++){
            int ind = indices[i];
            int cnt = 0;
            for(int j=ind+1; j<arr.size(); j++){
                if(arr[j] > arr[ind]) cnt++;
            }
            res.push_back(cnt);
        }
        return res;
   
    }
};// Time complexity: O(n^2), space complexity: O(1)
