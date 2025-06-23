class Solution {
public:
    int print2largest(int arr[], int n) {
        int largest = -1;
        int second_largest = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != largest) {
                second_largest = max(second_largest, arr[i]);
            }
        }

        return second_largest;
    }
};
// };
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space