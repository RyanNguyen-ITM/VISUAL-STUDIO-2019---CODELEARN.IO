#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

int moneyChange(std::vector<int> a, int n)
{
	int count;
	int min = n;
	int luu = n;
	sort(a.begin(), a.end());
	while (true)
	{
		count = 0;
		int i;
		for (i = a.size() - 1; i >= 0; i--) {
			if (n >= a[i]) {
				count++;
				n -= a[i];
				i++;
			}
		}
		if (count <= min && a.size() > 0) {
			a.erase(a.end() - 1);
			min = count;
			n = luu;
		}
		else {
			break;
		}
	}
	return min;
}

int main() {
	time_t start = clock();
	int n = 6;
	vector<int> a = { 1 };
	time_t finish = clock();
	cout << moneyChange(a, n);
	cout << "\n\nTime: " << finish - start << endl;
	return 0;
}