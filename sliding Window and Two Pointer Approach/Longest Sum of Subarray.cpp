/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]*/
// Method-1 Sliding Window Approach very very Important Concept

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
    int atMost(vector<int>& nums, int goal){
        int head, tail = 0, sum = 0, result = 0;
        for (head = 0; head < nums.size(); head++) {
            sum += nums[head];
            while (sum > goal && tail <= head) {
                sum -= nums[tail];
                tail++;
            }
            result += head - tail + 1;
        }
        return result; 
    }
};
// T.C : O(n) and S.C : O(1) - ignoring the space taken by nums vector
//Method-2 stl
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};
// T.C : O(n) and S.C : O(n) - ignoring the space taken by count unordered_map