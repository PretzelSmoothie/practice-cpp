/*

Input: an integer n > 1

Let A be an array of Boolean values, indexed by integers 2 to n,
initially all set to true.

for i = 2, 3, 4, ..., not exceeding √n:
  if A[i] is true:
    for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n :
      A[j] := false

Output: all i such that A[i] is true.

Source: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

Computational complexity: O(nlog(log(n)))

*/

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void sieveOfEratosthenes(long long n);

int main(){
  long long n;

  cout << endl << endl
       << "*******************************"
       << endl << endl
       << "This program implements the Sieve of Eratosthenes"
       << " to find all values 2 ... n that are prime"
       << endl
       << "Please input n: ";
  cin >> n;

  sieveOfEratosthenes(n);

  cout << endl << "*****************************" << endl;

  return 0;
}

void sieveOfEratosthenes(long long n){
  bool A[n+1];
  std::memset(A, true, sizeof(A));
  int nSqrt = (int)sqrt((double)n);

  for(int i = 2; i < sqrt(n); i++){
    if(A[i] == true){
      for( int j = i*2; j <= n; j += i )
        A[j] = false;
    }
  }
  for (int k = 2; k <= n; k++){
    if(A[k])
      cout << endl << k;
  }
}


// ~Pretzel
