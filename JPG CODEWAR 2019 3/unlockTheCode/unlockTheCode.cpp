#include<iostream>
#include<string>
#include<time.h>
#include<vector>

using namespace std;

void proc(string start, string target, int n, vector<vector<string>> arr, vector<string>& res) {
	int idx = -1; 
	int size = 0;
	string rem;
	for (int i = 0; i < start.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			rem = start;
			idx = (int)start.find(arr[j][0], i);
			if (idx >= 0) {
				size = arr[j][0].size();
				rem.replace(idx, size, arr[j][1]);

				if (n == 1) {
					if (rem.size() == target.size())
						res.push_back(rem);
				}
				else
					proc(rem, target, n - 1, arr, res);
			}
		}
	}
}

bool unlockTheCode(std::string start, std::string target, int n, std::vector<std::vector<std::string>> arr)
{
	vector<string> res;
	
	proc(start, target, n, arr, res);
	for (int i = 0; i < res.size(); i++) {
		if (res[i].compare(target) == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	time_t st = clock();
	vector<vector<string>> arr{ {"X", "O"}, {"O", "XX"}, {"O", "X"} };
	string start = "XXXOXXOOXX";
	string target = "OOOOOOOO";
	int n = 7;

	cout << unlockTheCode(start, target, n, arr);
	time_t fi = clock();
	cout << "\n\nTime: " << fi - st << endl;
	return 0;
}
