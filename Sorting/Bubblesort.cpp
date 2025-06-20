//Method-1
class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
            }
        }
    }
};

//Method-2
class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            bool swaped=0;
            for(int j=0;j<i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                swap(arr[j],arr[j+1]);
                swaped=1;
                }
            }
            if(swaped==0)
            break;
        }
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//Best case:o(n),worst case:o(n^2)
// Average case: O(n^2)
//Method-3 Recursive Bubble Sort
void bubbleSortRecursive(vector<int>& arr, int n) {
    // Base case
    if (n == 1) return;

    // One full pass to push the largest to the end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call for remaining part
    bubbleSortRecursive(arr, n - 1);
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    int n = arr.size();

    bubbleSortRecursive(arr, n);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}