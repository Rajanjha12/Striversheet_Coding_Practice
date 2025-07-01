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
// Better Approach
// Time Complexity: O(2n) where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2 is Brute force oF SORT THE ARRAY AND ACCESS THE NUMBER FROM AND USE CONDITION AND WHILE OR FOR LOOP
