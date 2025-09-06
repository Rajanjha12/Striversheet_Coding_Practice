/*Input: N = 10
Output: 2, 3, 5, 7
Explanation : The output "2, 3, 5, 7" for input N = 10 represents the list of the prime numbers less than or equal to 10. */

//Method-1
bool isPrime(int n)
{
    // since 0 and 1 is not prime return false.
    if (n == 1 || n == 0)
        return false;

    // Run a loop from 2 to n-1
    for (int i = 2; i < n; i++) {
        // if the number is divisible by i, then n is not a
        // prime number.
        if (n % i == 0)
            return false;
    }
    // otherwise, n is prime number.
    return true;
}

// Driver code
int main()
{
    int N = 100;

    // check for every number from 1 to N
    for (int i = 1; i <= N; i++) {
        // check if current number is prime
        if (isPrime(i))
            cout << i << " ";
    }
}
//Time Complexity: O(N^2), 
//Auxiliary Space: O(1)

//Method-2
bool isPrime(int n){
    
    if(n==1||n==0) return false;
 
    for(int i=2; i<=n/2; i++) {
        
          if(n%i==0) return false;
    }
    return true;
}


// Driver code
int main()
{
    int N = 100;
 
      for(int i=1; i<=N; i++){
        
        if(isPrime(i)) {
          cout << i << " ";
        }
    }

}
//Time Complexity: O(N*(N/2)) i.e. O(N^2),
//Auxiliary Space: O(1)
//Method-3
bool isPrime(int n){
 
  if(n==1||n==0)return false;
   
  for(int i=2; i*i<=n; i++){
    
    if(n%i==0)return false;
  }
  
  return true;
}
 
int main()
{
    int N = 100;
 
      for(int i=1; i<=N; i++){
      if(isPrime(i)) {
        cout << i << " ";
      }
    }
}