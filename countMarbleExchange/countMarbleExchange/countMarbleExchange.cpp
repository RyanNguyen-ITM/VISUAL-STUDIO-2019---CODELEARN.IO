/*

	BÀI NÀY CÒN SAI TRƯỜNG HỢP NÀO ĐÓ

*/

#include<iostream>
#include<vector>
#include<conio.h>
#include<algorithm>

using namespace std;

int countMarbleExchange(std::vector<int> marbles)
{
	long long tong = 0;
	int can = 0;
	int phan = 0;
	int count = 0;

	for (int i = 0; i < marbles.size(); i++) {
		tong += marbles[i];
	}

	if (tong % 3 != 0) {
		return -1;
	}
	if (tong == 3) {
		for (int i = 0; i < marbles.size(); i++) {
			if (marbles[i] == tong) return -1;
		}
		if (marbles[0] <= 2 && marbles[1] <= 2 && marbles[2] <= 2)
			return -1;
	}
	else {
		phan = tong / 3;
		for (int i = 0; i < marbles.size(); i++) {
			if (phan > marbles[i]) {
				can = phan - marbles[i];

				if (can != 0 && can % 2 != 0) {
					count++;
					can -= 1;
				}
				if (can != 0 && can % 2 == 0) {
					count += can / 2;
				}
			}
		}
	}
	return count;
}

int main() {
	vector<int> marbles = { 1, 4, 4 }; // trường hợp dễ sai
	cout << countMarbleExchange(marbles);
	return 0;
}