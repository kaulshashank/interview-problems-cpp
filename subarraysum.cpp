#include<iostream>

using namespace std;

void subArraySum(int arr[], int n) {
	int subsum = 0;
	for (int i = 0; i < n-1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			subsum += arr[j];
		}
		cout << "Sum of sub array " << i+1 << " is " << subsum<<endl;
		subsum = 0;
	}
}


int main() {
	int *arr;
	int n = 5;
	arr = new int[n];
	cout << "Input array elements: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	subArraySum(arr, n);
	return 0;
}