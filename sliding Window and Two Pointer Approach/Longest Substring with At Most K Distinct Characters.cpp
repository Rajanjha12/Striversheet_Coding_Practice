

//method-1
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
         int n=s.length();
        
        vector<int>fq(26,0);
        int mx=-1, d=0, l=0;
        
        for(int r=0; r<n; r++){
            if(fq[s[r]-'a']==0) d++;
            fq[s[r]-'a']++;
            
            while(d>k){
                fq[s[l]-'a']--;
                if(fq[s[l]-'a']==0) d--;
                l++;
            }
            
            if(k==d){
                mx= max(mx, r-l+1);
            }
            
        }
        return mx;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
//method-2
int n=s.length();
        
       unordered_map<char,int>fq;
       int l=0, mx=-1;
       
       for(int r=0;r<n; r++){
           fq[s[r]]++;
           
           while(fq.size()>k){
               fq[s[l]]--;
               if(fq[s[l]]==0) fq.erase(s[l]);
               l++;
           }
           
           if(fq.size()==k){
               mx= max(mx, r-l+1);
           }
           
       }
       return mx;
       // Time Complexity: O(n)
        // Space Complexity: O(k)
