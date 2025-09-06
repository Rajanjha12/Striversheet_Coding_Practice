//Method-1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    for (auto& entry : freq) {
        if (entry.second == 1)
            return entry.first;
    }

    return -1;
    }
};
// Time Complexity:O(n),space Complexity:O(n)
//Method-2 Bit Manipulation
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num; // XOR operation
        }
        return ans;
    }
// Time Complexity: O(n), Space Complexity: O(1)
/*
nums = [4, 1, 2, 1, 2];
Initialization:
res = 0
Iteration 1: n = 4
res = 0 ^ 4
    = 4
Iteration 2: n = 1
res = 4 ^ 1
    = 5   (binary: 100 ^ 001 = 101)
Iteration 3: n = 2
res = 5 ^ 2
    = 7   (binary: 101 ^ 010 = 111)
Iteration 4: n = 1
res = 7 ^ 1
    = 6   (binary: 111 ^ 001 = 110)
Iteration 5: n = 2
res = 6 ^ 2
    = 4   (binary: 110 ^ 010 = 100)
Final Result:
res = 4*/