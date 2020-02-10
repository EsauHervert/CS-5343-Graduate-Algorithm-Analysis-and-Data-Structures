#include <iostream>

using namespace std;

void print(double*, int);
double *prefixAverage1(double*, int);
double *prefixAverage2(double*, int);

int main() {
	double A[10] = { 2,5,7,8,3,6,9,4,5,2 };
	print(prefixAverage1(A, 10),10);
	print(prefixAverage2(A, 10),10);

}

double* prefixAverage1(double *X, int n) {
	double* A = new double[10];
	int i, j;
	double s;
	for (i = 0; i <= n - 1; i++) {
		s = X[0];
		for (j = 1; j <= i; j++) {
			s = s + X[j];
		}
		A[i] = s / (i + 1);
	}
	return A;
}

double* prefixAverage2(double *X, int n) {
	int i;
	double s = 0;
	for (i = 0; i < n; i++) {
		s = s + X[i];
		X[i] = s / (i + 1);
	}
	return X;
}
 
void print(double *X, int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << X[i] << " ";
	}
	cout << endl;
}