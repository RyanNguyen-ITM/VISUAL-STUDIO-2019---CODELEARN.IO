#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;

int exchangeMoney(std::vector<int> arr, int n)
{
	int prev = -1, next = -1;
	int max = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr.at(i) < arr.at(j)) {
				if (max < (arr.at(j) - arr.at(i))) {
					max = arr.at(j) - arr.at(i);
					prev = i;
					next = j;
				}
			}
		}
	}
	if (prev == -1 && prev == -1) {
		return n;
	}
	return n + n / arr.at(prev) * (arr.at(next) - arr.at(prev));
}

int main() {

	int n = 755;
	vector<int> arr = { 51,160 };
	cout << exchangeMoney(arr, n);
	return 0;
}