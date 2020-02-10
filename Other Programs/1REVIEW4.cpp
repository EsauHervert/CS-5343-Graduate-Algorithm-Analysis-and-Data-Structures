#include <iostream>

using namespace std;

void swap(int *A, int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void SelectionSort(int *A, int n) {
	int min;
	int minindex;

	for (int i = 0; i < n; i++) {
		min = A[i];
		minindex = i;

		for (int j = (i + 1); j < n; j++) {
			if (A[j] < min) {
				min = A[j];
				minindex = j;
			}
		}

		if (i != minindex) {
			swap(A, i, minindex);
		}
	}
}

int BinarySearch(int *A, int v, int s, int n) {
	int mid = (n - s) / 2 + s;
	if (A[mid] == v) {
		return mid;
	}
	else if (n == s) {
		cout << "Value Not Found!" << endl;
		return -1;
	}
	if (A[mid] < v) {
		return BinarySearch(A, v, mid + 1, n);
	}
	else {
		return BinarySearch(A, v, s, mid);
	}

}

void print(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

int main() {
	int A[10] = { 1,11,17,14,7,8,6,5,12,22 };
	print(A, 10);
	SelectionSort(A, 10);
	print(A, 10);
	int i = BinarySearch(A, 11, 0, 10);
	if (i != -1) {
		cout << "A[" << i << "] = " << A[i] << endl;
	}

}