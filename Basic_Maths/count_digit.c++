class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int count=0;
        int x=n;
        while(x>0)
        {
            int digit=x%10;
            if(digit>0&&n%digit==0)
            count++;
            x=x/10;
        }
        return count;
    }
};
// Time Complexity: O(log n), where n is the input number. This is because we are iterating through each digit of the number. and n divide by 10 
//Best and Worest Case: O(log n) since we are iterating through each digit of the number.
// Space Complexity: O(1), since we are using a constant amount of space for the count and digit variables.