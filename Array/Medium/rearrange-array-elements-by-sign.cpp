//Method-1 Brute force Approach
vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  
  
  return A;
    
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) as we are using two extra vectors to store positive and negative
//Method-2 Optimized Approach
  vector<int> rearrangeArray(vector<int>& nums) {
        int start=0,end=1;
        int n=nums.size();
        vector<int>ans(n);
    
    
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans[start] = nums[i];
            start += 2; 
        } else {
            ans[end] = nums[i];
            end += 2; 
        }
    }
    return ans;

    };