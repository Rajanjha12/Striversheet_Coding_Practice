class Solution {
  public:
    bool isEven(int n) {
        // code here
          int a = n&1;
        return a==0 ? true: false;
    }
};