/*

	VƯỢT QUÁ THỜI GIAN

*/
#include<iostream>
#include<conio.h>
#include<vector>
#include<time.h>

using namespace std;

int findTheSeatLine(long long m)
{
	int res = 0;
	int x;
	int k;
	long long delta = 1 + 8 * m;
	delta = sqrt(delta);
	x = (delta - 1) / 2;
	k = (x + 1) * x / 2;
	if (k < m) {
		res = x + 1;
	}
	else
		res = x;
	return res;
}

int main() {
	time_t start = clock();
	long long m = 11;
	cout << findTheSeatLine(m);
	time_t finish = clock();
	cout << "\n\nTime: " << finish - start << endl;
	return 0;
}