#include<iostream>

using namespace std;

void printArray(int **arr, int rows, int cols) {
	cout << "------MATRIX------" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void inputArray(int **arr, int rows, int cols) {
	cout << "Enter the elements in row major: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> arr[i][j];
		}
	}
}

void swap(int &a, int &b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void rotateMatrixByK(int **arr, int rows, int cols, int k) {
	int last = cols - 1;
	int r=0, lvl=0;
	while (r < k) {
		for (int i = 0; i < last; i++) {
			swap(arr[lvl][i], arr[i][last]);
			swap(arr[lvl][i], arr[last][last-i]);
			swap(arr[lvl][i], arr[last-i][lvl]);
		}
		r++;
	}
}


int main() {
	int **arr;
	int rows, cols, k;
	cout << "Enter number of rows and columns: ";
	cin >> rows >> cols;
	arr = new int*[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];
	inputArray(arr, rows, cols);
	printArray(arr, rows, cols);
	cout << "How many rotations: ";
	cin >> k;
	rotateMatrixByK(arr, rows, cols, k);
	printArray(arr, rows, cols);
	delete arr;
	return 0;
}