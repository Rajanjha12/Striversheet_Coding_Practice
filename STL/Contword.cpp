/*Input:
N = 3
list = {Geeks, For, Geeks}
Output: 1
Explanation: 'Geeks' is the only word that 
appears twice. */
class Solution {
  public:
    int countWords(string list[], int n) {
        // code here.
        map<string ,int>mp;
           int cnt=0;
           
           for(int i =0;i<n;i++){
               mp[list[i]]++;
           }
           
           for(auto &it : mp){
               if(it.second ==2){
                   cnt++;
               }
           }
           return cnt;
    }
};
//Time complexity:O(nlog(n))
//Space complexity:o(N)
//when uses unordered_map
//Time complexity:O(n),same code only change in map replace with unordered_map
//Space complexity:o(N)
class Solution {
  public:
    int countWords(string list[], int n) {
        // code here.
        unordered_map<string ,int>mp;
           int cnt=0;
           
           for(int i =0;i<n;i++){
               mp[list[i]]++;
           }
           
           for(auto &it : mp){
               if(it.second ==2){
                   cnt++;
               }
           }
           return cnt;
    }
};