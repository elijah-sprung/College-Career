#include <iostream>

using namespace std;

void tester(int n, int m, int* arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(arr + i * m + j) = 69;
        }
    }
}

int main() {
	int n = 3, m = 4, c = 0;
	// cin >> n >> m;
	// cout << n << m;

	int* arr = new int[n * m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(arr + i * m + j) = ++c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(arr + i * m + j) << " ";
        }
        cout << endl;
    }

    tester(n, m, arr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(arr + i * m + j) << " ";
        }
        cout << endl;
    }

    delete[] arr;

    return 0;
}