#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int rLinearSum(int*, int);
void ReverseArray(int*, int, int);
void print(int*, int);

double Power1(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return x * Power1(x, n - 1);
	}
}

double Power2(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		double p = Power2(x, n / 2);
		return p*p;
	}
	else {
		double p = Power2(x, (n - 1) / 2);
		return x * p*p;
	}
}

int rFib(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return (rFib(n - 1) + rFib(n - 2));
	}
}
int DPFib(int n) {
	vector<int> F;
	F.push_back(0);
	F.push_back(1);
	for (int i = 2; i <= n; i++) {
		int Fi = F[i - 1] + F[i - 2];
		F.push_back(Fi);
	}
	return F[n];
}

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x%y);
	}
}
int main() {
	/*
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//cout << rLinearSum(A, 10);
	print(A, 10);
	ReverseArray(A, 0, 9);
	print(A, 10);
	*/

	//cout << Power1(3.5, 7) << endl;
	//cout << Power2(3.5, 7) << endl;

	//cout << rFib(50) << endl;
	//cout << DPFib(50) << endl;

	cout << gcd(120*11, 7*27*5) << endl;
}

int rLinearSum(int* A, int x) {
	if (x == 1) {
		return A[0];
	}
	else {
		return A[x - 1] + rLinearSum(A, x - 1);
	}
}

void swap(int *A, int i, int  j) {
	int c = A[i];
	A[i] = A[j];
	A[j] = c;
}
void ReverseArray(int* A, int i, int j) {
	if (i < j) {
		swap(A, i, j);
		ReverseArray(A, i + 1, j - 1);
	}
}
void print(int *A, int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}