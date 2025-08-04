//Method: Brute Force

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}
// Time Complexity: O(n^2) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space



//Method:2
int majorityElement(vector<int> v) {
    sort(nums.begin(),nums.end());
        int size = nums.size();
    int medianIndex = size / 2;
         if (size % 2 == 0) {
        // For even-sized vector, return the average of the two middle elements
        return (nums[medianIndex - 1] + nums[medianIndex]) / 2;
    } else {
        // For odd-sized vector, return the middle element
        return nums[medianIndex];
    }
    }
// Time Complexity: O(n log n) where n is the size of the array due to sorting
// Space Complexity: O(1) as we are not using any extra space except 


// Method: Better Approach using Hashing

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) for the map to store the elements and their frequencies


// Method: Optimal Approach using Boyer-Moore Voting Algorithm
//It is like that voting system where we have to find the candidate who has more than half of the votes ...Rohit negi vedio
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

    return (count > v.size() / 2) ? candidate : -1;
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space