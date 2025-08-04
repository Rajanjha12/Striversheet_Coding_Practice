/*
Input: s = "GEekS"
Output: EGekS
Explanation: Sorted form of given string with the same case of character will result in output as EGekS.
Input: s = "XWMSPQ"
Output: MPQSWX
*/
//Method-1: Using sort with custom comparator
class Solution {
  public:
    string caseSort(string& s) {
        // code here
         string upper="";
        string lower="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z') upper+=s[i];
            else lower+=s[i];
        }
        
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        
        
        int u=0,l=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
               s[i]=upper[u];
               u++;
            }
            else{
                s[i]=lower[l];
                l++;
            }
        }
        return s;
    }
};
// Time Complexity: O(nlogn) for sorting the characters
// Space Complexity: O(n) for storing the characters in separate strings
