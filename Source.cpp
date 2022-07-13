#include <iostream>
using namespace std;
void Bubblesort(int a[], int& n);
int RetrievePos(int a[], int& n, int& k);
int main() {

	int n;
	cout << " Enter Nomber of array: " << endl;
	cin >> n;
	int* a = new int[n];
	cout << "Enter Elements: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Bubblesort(a, n);
	for (int i = 0; i < n; i++) {
		cout << " | " << a[i] << " | ";
	}
	cout << endl << "Enter Key: ";
	int key;
	cin >> key;
	int pos = RetrievePos(a, n, key);
	if (pos == -1) { cout << " no valid key "; }
	else {
		cout << " the key is at: " << pos;
	}

	return 0;
}

void Bubblesort(int a[], int& n) {

	for (int count = 1; count < n - 1; count++) {
		int flag = 0;
		for (int j = 0; j <= n - 2; j++) {
			if (a[j] > a[j + 1]) { 
				swap(a[j], a[j + 1]);
			flag = 1;
			}
			if (flag == 0) { break; }
		}
	}

}

int RetrievePos(int a[], int& n, int& k) {

	int s = 0, e = n - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (a[mid] == k) { return mid; }
		else if (a[mid] > k) { e = mid - 1; }
		else { s = mid + 1; }
	}
	return -1;

}