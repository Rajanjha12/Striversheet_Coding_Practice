//Method-1
   int maxProduct(vector<int>& nums) {
         int maxproduct = INT_MIN;
    
    for (int i = 0; i < nums.size(); i++) {
        long long product = 1;
        for (int j = i; j < nums.size(); j++) {
            product *= nums[j];
            maxproduct = max(maxproduct, (int)product);
        }
    }

    return maxproduct;
}
// Time Complexity: O(n^2) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space
//Method-2
int maxProduct(vector<int>& nums) {
          int maxProd = nums[0];
    int currMax = nums[0], currMin = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < 0) swap(currMax, currMin);
        
        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);

        maxProd = max(maxProd, currMax);
    }

    return maxProd;
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space