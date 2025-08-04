class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
          int get = (num & 1<<i-1) ? 1 : 0;
        
        int set = (num | 1<<i-1);
        
        int clear = (num & ~(1<<i-1));
        
        cout<<" "<<get<<" "<<set<<" "<<clear;
    }
};