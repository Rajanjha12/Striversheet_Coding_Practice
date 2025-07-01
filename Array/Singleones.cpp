//Method-1
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) as we are using only a constant amount of extra space
int singleNumber(vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    for (auto& entry : freq) {
        if (entry.second == 1)
            return entry.first;
    }

    return -1; // Should not reach here if input is valid
}
//Method-2 using XOR
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            ans = ans ^ nums[i];
        }

        return ans;
        
    }
}
//Method-3 Brute force
int getSingleElement(vector<int> &arr) {
    // Size of the array:
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}
// Time Complexity: O(n^2) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space