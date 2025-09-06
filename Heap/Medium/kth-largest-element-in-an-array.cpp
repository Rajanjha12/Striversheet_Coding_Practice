// max heap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(i>=nums.size()-k+1){
                pq.pop();
            }
        }
        return pq.top();
    }
};

// min heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min heap
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i:nums) {
            minh.push(i);
            if(minh.size() > k)
                minh.pop();
        }
        
        return minh.top();
    }
};
// Time Complexity: O(N log K)
// Space Complexity: O(K)

// sort 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>()); // descending order
        return nums[k - 1];
    }
};