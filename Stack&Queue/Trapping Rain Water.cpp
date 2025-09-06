 int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);
        int maxL = 0, maxR = 0;

        for (int i = 0; i < n; ++i) {
            maxL = max(maxL, height[i]);
            left[i] = maxL;
        }

        for (int i = n - 1; i >= 0; --i) {
            maxR = max(maxR, height[i]);
            right[i] = maxR;
        }

        int water = 0;
        for (int i = 0; i < n; ++i) {
            water += min(left[i], right[i]) - height[i];
        }

        return water;
    }
    // Time complexity: O(n), space complexity: O(n)
    //Method-2
     int trap(vector<int>& height) {
            int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                waterTrapped += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                waterTrapped += rightMax - height[right];
            }
            right--;
        }
    }

    return waterTrapped;
}
    // Time complexity: O(n), space complexity: O(1)
