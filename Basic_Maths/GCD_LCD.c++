//Brute force
#include <iostream>
using namespace std;
int a,b,gcd;
for(int i=min(a,b);i>=2;i--)
{
    if(a%i==0 && b%i==0)
    {
        gcd=i;
        break;
    }
}
int l=(a*b)/gcd;
return {l,gcd};
//Time Complexity: O(min(a,b))
//Space Complexity: O(1)
//Best and Worst Case: O(min(a,b))

// Optimized approach using Euclidean algorithm
int gcd(int a, int b) {
    //recursive approach Euclidean algorithm
    
    if (b == 0)
        return a;
    return gcd(b, a % b);
//oR iterative approach
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

vector<int> lcmAndGcd(int a, int b) {
    int g = gcd(a, b);
    int l = (a * b) / g;
    return {l, g};  // Return vector with LCM first, GCD second
}
// Time Complexity: O(log(min(a, b)))  
// Space Complexity: O(1)  
// Best and Worst Case: O(log(min(a, b)))  