#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<math.h>
#include<time.h>

using namespace std;

void init(vector<int>& arr, int n) {
	for (int i = 0; i < n; i++) {
		arr.push_back(i);
	}
}

void print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool soNT(int n) {
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b; b = temp;
}



void proc(vector<int> arr) {
	int k;
	int count = 1;
	for (int i = arr.size() - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) { // diem tang dau tien
			int k = arr.size() - 1; // bat dau tu cuoi mang
			while (k >= i) { // den phan tu thu i
				if (arr[k] > arr[i]) {
					swap(arr[i], arr[k]);
					break;
				}
				else k--;
			}
			partial_sort(arr.begin() + k + 1, arr.begin() + arr.size() - k + 1, arr.end());
			print(arr);
			i = arr.size();
			count++;
		}
	}
	cout << "So luong hoan vi: " << count;
}

int main() {

	time_t start = clock();
	int n = 5;
	vector<int> arr;
	init(arr, n);
	print(arr);
	proc(arr);
	time_t finish = clock();
	cout << "\n\n----------------------------\n\n";
	cout << " Time: " << finish - start << endl;
	return 0;
}