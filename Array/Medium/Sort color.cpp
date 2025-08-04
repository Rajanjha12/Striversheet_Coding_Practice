//Method-1
sort(arr/begin(), arr.end());
// Time Complexity: O(n log n) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space except for the input array

//Method-2 
class Solution {
public:
    void sortColors(vector<int>& nums) {
       vector<int> ans;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0)
        ans.push_back(nums[i]);
}
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 1)
        ans.push_back(nums[i]);
}
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 2)
        ans.push_back(nums[i]);
}
for (int i = 0; i < nums.size(); i++) {
    nums[i] = ans[i];
}
         
    }
};
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) as we are using an extra array to store the sorted elements
//Method-3 Better Approach
void sortArray(vector<int>& arr, int n){
int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }
 
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2;
}
// Time Complexity: O(n)+O(n) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space except for a
//Method-4 Optimal Approach
void sortColors(vector<int>& nums) {
      int l = 0;
        int m = 0;
        int h = nums.size()-1;

        while(m<=h){
            if(nums[m]==0){
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else if(nums[m]==2){
                swap(nums[m], nums[h]);
                h--;
            }
        }
    };
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space except for the