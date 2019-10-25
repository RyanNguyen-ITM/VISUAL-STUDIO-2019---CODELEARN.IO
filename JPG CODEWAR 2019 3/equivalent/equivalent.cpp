#include<iostream>
#include<vector>

using namespace std;

long delZero(long n) {
	vector<int> num;
	int k;
	long a = 0;
	while (n > 0)
	{
		k = n % 10;
		if (k != 0) num.push_back(k);
		n /= 10;
	}
	for (int i = num.size() - 1; i >= 0; i--) {
		a = a * 10 + num[i];
	}
	return a;
}

bool equivalent(int a, int b)
{
	long x = long(a);
	long y = long(b);
	long c = a + b;

	x = delZero(x);
	y = delZero(y);
	c = delZero(c);

	if (x + y == c) return true;

	return false;
}

int main() {

	cout << equivalent(999999999, 999999999);
	return 0;
}