/*

Vượt quá thời gian

*/

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<time.h>

using namespace std;

int compare2Arr(vector<int> arr1, vector<int> arr2) {
	if (arr1.size() > arr2.size()) return 1;
	else if (arr1.size() < arr2.size()) return -1;
	else {
		for (int i = 0; i < arr1.size(); i++) {
			if (arr1.at(i) < arr2.at(i)) return -1;
			else if (arr1.at(i) > arr2.at(i)) return 1;
		}
	}
	return 0;
}

std::string findBiggestNumber(std::string s, int k)
{
	vector<int> num;
	vector<int> arrPrev;
	vector<int> arrCurr;
	vector<int> max;
	int res;
	int idx;

	int n = s.size() - k;
	for (int i = 0; i < s.size(); i++) {
		num.push_back(s[i] - 48);
	}

	for(int i = 0; i < num.size() - 1; i++){
		if (num[i] < num[i + 1]) {
			num.erase(num.begin() + i);
			i = -1;
			k--;
		}
		if (k <= 0) break;
	}
	if (k > 0) {
		for (int i = num.size() - 1; i > 0; i--) {
			if (num[i] < num[i - 1]) {
				num.erase(num.begin() + i);
				i = num.size() - 1;
				k--;
			}
			if (k <= 0) break;
		}
	}
	if (k > 0) {
		for (int i = num.size() - 1; i > 0; i--) {
			num.erase(num.begin() + i);
			i = num.size() - 1;
			k--;
			if (k <= 0) break;
		}
	}
	s.clear();
	for(int i = 0; i < num.size(); i++)
		s.push_back(char('0' + num[i]));
	return s;
}

int main() {

	time_t start = clock();
	string s = "148771";
	cout << findBiggestNumber(s, 5);
	time_t finish = clock();
	cout << "\n\nTime: " << finish - start << endl;
	return 0;
}