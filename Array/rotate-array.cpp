//Method -1 Brute force
class Solution {
public:
   void reverse(vector<int>& nums)
{
    int n = nums.size();
    int temp = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        nums[i + 1] = nums[i];
    }
    nums[0] = temp;
}

void rotate(vector<int>& nums, int k)
{
    int n = nums.size();
    k = k % n;
    while (k > 0)
    {
        reverse(nums);
        k--;
    }
}

};
// Time Complexity: O(n*k) where n is the size of the array and k is the number of rotations
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2 Optimal Answer
class Solution {
public:
 void reverse(vector<int>& nums,int start,int end)
 {
    while(start<end)
    {
        swap(nums[start],nums[end]);
        start++,end--;
    }
 }
    void rotate(vector<int>& nums, int k) {
      int n=nums.size();
        k=k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space