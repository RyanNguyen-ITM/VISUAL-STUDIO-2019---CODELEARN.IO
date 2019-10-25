#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<time.h>
#include<algorithm>

using namespace std;

int examRush(int t, std::vector<int> tm)
{
	int count = 0;
	sort(tm.begin(), tm.end());
	for (int i = 0; i < tm.size(); i++) {
		if (t >= tm.at(i) && t > 0) {
			count++;
			t -= tm.at(i);
		}
		else break;
	}
	return count;
}

int main() {

	int t = 10;
	vector<int> tm = { 1, 5, 6, 7, 1, 16, 19, 4, 4, 20 };
	examRush(t, tm);
	return 0;
}