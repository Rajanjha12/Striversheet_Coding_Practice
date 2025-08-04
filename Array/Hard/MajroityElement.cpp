//Method-1 Brute Force Approach
    vector<int> majorityElement(vector<int>& nums) {
         int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> result;

    // Count frequency of each number
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }

    // Check for majority elements (appearing more than n/3 times)
    for (auto it : mp) {
        if (it.second > n / 3) {
            result.push_back(it.first);
        }
    }

    return result;
    }
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) as we are using a hash map to store the frequency of
//Method-2 Optimal Approach using Boyer-Moore Voting Algorithm
    int majorityElement(vector<int> v) {
    int candidate = -1;
    int count = 0;

    // Phase 1: Find a candidate
    for (int num : v) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : v) {
        if (num == candidate) {
            count++;
        }
    }

    return (count > v.size() / 3) ? candidate : -1;
}