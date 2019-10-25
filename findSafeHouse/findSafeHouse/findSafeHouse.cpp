#include <iostream>
#include <vector>

using namespace std;

void enter(int& n, int& x, int& y) {
	cin >> n >> x >> y;
}

void xuat(vector<std::vector<int>> house) {
	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < 2; j++) {
			cout << house[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n\n=============================\n\n";
}

int findSafeHouse(int n, int x, int y, std::vector<std::vector<int>> house)
{
	int xmin;
	int ymax;
	int index = 0;
	vector<vector<int>>remm = house;
	// loại bỏ nếu xa hơn hoặc ít coin hơn
	for (int i = 0; i < house.size(); i++) {
		if (house[i][0] > x || house[i][1] < y) {
			house.erase(house.begin() + i);
			i--;
		}
	}
	xuat(remm);
	xuat(house);
	if(!house.empty())
		xmin = house[index][0]; // đường ngắn nhất là 0
	if (house.size() > 1) {
		for (int i = 1; i < house.size(); i++) {
			if (xmin > house[i][0]) { // xoá tại xmin
				xmin = house[i][0]; // xmin là house hiện tại
				house.erase(house.begin() + index); // xoá
				index = i - 1; //index của min
				i = 0; // duyệt lại từ đầu -> i = 1
			}
			else if (xmin < house[i][0]) {
				house.erase(house.begin() + i); // xoá house i
				i--;
			}
		}
	}
	index = 0;
	xuat(house);
	if (!house.empty())
		ymax = house[index][1];
	if (house.size() > 1) {
		for (int i = 1; i < house.size(); i++) {
			if (ymax < house[i][1]) {
				ymax = house[i][1];
				house.erase(house.begin() + index);
				index = i - 1;
				i = 0;
			}
			else if (ymax > house[i][1]) {
				house.erase(house.begin() + i);
				i--;
			}
		}
	}

	xuat(house);
	if (house.size() > 0) {
		for (int i = 0; i < remm.size(); i++) {
			if (remm[i] == house[0]) {
				return i + 1;
			}
		}
	}
	return -1;
}

int main() {
	int n, x, y;
	vector < vector<int> > house = { {10,48}, {39,26}, {13,38}, {35,9}, {6,42}, {41,7}, {30,16}, {16,5}, {10,41}, {38,29}, {20,49}, {6,44}, {10,38}, {8,3}, {17,38}, {10,6}, {40,35}, {48,31}, {13,3}, {35,45} };
	enter(n, x, y);
	cout << findSafeHouse(n, x, y, house);
	return 0;
}
