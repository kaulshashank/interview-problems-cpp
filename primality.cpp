#include<iostream>

using namespace std;

int power(int a, unsigned int n, int p) { //(a^n)%p calculation
	int res = 1;
	a = a % p;
	while (n > 0) {
		// If n is odd, multiply 'a' with result
		if (n & 1)
			res = (res*a) % p;

		n = n >> 1;
		a = (a*a) % p;
	}
	return res;
}

bool isPrime(unsigned int n, int k) {
	// Corner cases
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	// Try k times
	while (k>0)
	{
		// Pick a random number in [2..n-2]        
		// Above corner cases make sure that n > 4
		int a = 2 + rand() % (n - 4);

		// Fermat's little theorem
		if (power(a, n - 1, n) != 1)
			return false;

		k--;
	}

	return true;
}

int main()
{
	int k = 3;
	isPrime(11, k) ? cout << " true\n" : cout << " false\n";
	isPrime(15, k) ? cout << " true\n" : cout << " false\n";
	return 0;
}