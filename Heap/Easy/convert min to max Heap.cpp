
/* N = 4
arr = [1, 2, 3, 4]
Output:
[4, 2, 3, 1]
*/  
class Solution {
public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        // Start from the last non-leaf node and heapify each node
        for (int i = (N / 2) - 1; i >= 0; i--) {
            maxHeapify(arr, N, i);
        }
    }

private:
    void maxHeapify(vector<int> &arr, int N, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check if left child is larger
        if (left < N && arr[left] > arr[largest])
            largest = left;

        // Check if right child is larger
        if (right < N && arr[right] > arr[largest])
            largest = right;

        // If largest is not the root
        if (largest != i) {
            swap(arr[i], arr[largest]);
            // Recursively heapify the affected subtree
            maxHeapify(arr, N, largest);
        }
    }
}