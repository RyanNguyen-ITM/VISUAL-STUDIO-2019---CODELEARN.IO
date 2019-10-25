#include<iostream>
#include<vector>
#include<time.h>
#include<string>
#include<Windows.h>

using namespace std;


void xuat(vector<vector<int>> landMap) {

	for (int i = 0; i < landMap[0].size(); i++) {
		cout << "\t" << i;
	}
	cout << "\n ";
	for (int i = 0; i < landMap[0].size() * 8; i++) {
		cout << "_";
	}
	for (int i = 0; i < landMap.size(); i++) {
		cout << "\n" << " |\t";
		cout << "\n" << " |\t";
		cout << "\n" << i << "|\t";
		for (int j = 0; j < landMap[0].size(); j++) {
			if (landMap[i][j] == 2) {
				cout << "[ " << landMap[i][j] << " ]\t";
			}
			else
				cout << landMap[i][j] << "\t";
		}
	}
}
/*

								"4 1 1 1 1 1 1 1 1 1",
								"3 1 1 1 1 3 1 1 1 1",
								"1 1 1 1 1 0 1 1 1 1",
								"4 1 1 3 1 3 1 1 1 1",
								"1 1 1 4 1 4 1 1 1 1"

*/

void proc(vector<string> islandMap) {

}


int treasurePath(std::vector<std::string> islandMap)
{
	int count = 0;
	vector<vector<int>> landMap;
	vector<vector<int>> gates;
	vector<vector<int>> keys;
	vector<int> pointer(2);
	vector<int> start(2);
	landMap.assign(islandMap.size(), vector<int>(islandMap[0].size()));

	for (int i = 0; i < islandMap.size(); i++) {
		for (int j = 0; j < islandMap[i].size(); j++) {
			landMap[i][j] = islandMap[i][j] - 48;
			if (landMap[i][j] == 3) {
				pointer[0] = i;
				pointer[1] = j;
				keys.push_back(pointer);
			}
			else if (landMap[i][j] == 4) {
				pointer[0] = i;
				pointer[1] = j;
				gates.push_back(pointer);
			}
			else if (landMap[i][j] == 0) {
				start[0] = i;
				start[1] = j;
			}
		}
	}


	xuat(landMap);

	return count;
}

int main() {

	vector<string> islandMap = { 
								"4111111111",
								"3111131111",
								"1111101111",
								"4113131111",
								"1114141111" };

	treasurePath(islandMap);
	system("color a");
	cout << endl << endl;
	return 0;
}