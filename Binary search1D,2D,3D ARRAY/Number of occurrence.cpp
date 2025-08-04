//Method-1
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        unordered_map<int,int> freq;

for(int num:arr){

freq[num]++;

}

if(freq.find(target) != freq.end()){

return freq[target];

}

else return 0;


    }
};
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) for the hash map used to store frequencies of elements
// Method-2 Linear search
int countFreq(vector<int>& arr, int target) {
        // code here
        int count=0;
        for(int i : arr){
            if(i==target) count++;
        }
        return count;
    }
// Time Complexity: O(n) where n is the size of the array   
// Space Complexity: O(1) as we are using only a constant amount of extra space
// Method-3
// Find First Occurrence
int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}


int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int count(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1);
}
// Time Complexity: O(log n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space