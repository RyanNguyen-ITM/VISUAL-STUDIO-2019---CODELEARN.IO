//string _intToString(int n) {
//	string res;
//	ostringstream covert;
//	covert << n;
//	res = covert.str();
//	return res;
//}
//
//std::string findBiggestNumber(std::string s, int k)
//{
//	vector<int> num;
//	vector<int> numres;
//	int max = 0, maxnext;
//
//	int n = s.size() - k;
//	for (int i = 0; i < s.size(); i++) {
//		num.push_back(s[i] - 48);
//	}
//
//	for (int i = 0; i < n; i++) {
//		numres.push_back(i);
//		max = max * 10 + num[numres[i]];
//	}
//	for (int i = n - 1; i >= 0; i--) {
//		if (numres[i] < num.size() - n + i) {
//
//			numres[i]++;
//			int j;
//			for (j = i + 1; j < n; j++) {
//				numres[j] = numres[j - 1] + 1;
//			}
//
//			maxnext = 0;
//			for (j = 0; j < n; j++) {
//				maxnext = maxnext * 10 + num[numres[j]];
//			}
//			if (max < maxnext) {
//				max = maxnext;
//			}
//			i = n;
//		}
//	}
//	return _intToString(max);
//}

/*
	CACH 2
*/
//std::string findBiggestNumber(std::string s, int k)
//{
//	vector<int> num;
//	vector<int> numres;
//	int max = 0;
//	int maxprev = 0;
//	int res;
//	int idx;
//
//	int n = s.size() - k;
//	for (int i = 0; i < s.size(); i++) {
//		num.push_back(s[i] - 48);
//	}
//	while (k > 0) {
//		for (int i = 0; i < num.size(); i++) {
//			max = 0;
//			for (int j = 0; j < num.size(); j++) {
//				if (i != j) {
//					max = max * 10 + num[j];
//				}
//			}
//			if (max > maxprev) {
//				maxprev = max;
//				idx = i;
//			}
//		}
//		res = maxprev;
//		maxprev = 0;
//		num.erase(num.begin() + idx);
//		k--;
//	}
//
//	return _intToString(res);
//}

/*
	CÁCH 3
*/

//string _intToString(int n) {
//	string res;
//	ostringstream covert;
//	covert << n;
//	res = covert.str();
//	return res;
//}
//
//int compare2Arr(vector<int> arr1, vector<int> arr2) {
//	if (arr1.size() > arr2.size()) return 1;
//	else if (arr1.size() < arr2.size()) return -1;
//	else {
//		for (int i = 0; i < arr1.size(); i++) {
//			if (arr1.at(i) < arr2.at(i)) return -1;
//			else if (arr1.at(i) > arr2.at(i)) return 1;
//		}
//	}
//	return 0;
//}
//
//std::string findBiggestNumber(std::string s, int k)
//{
//	vector<int> num;
//	vector<int> arrPrev;
//	vector<int> arrCurr;
//	vector<int> max;
//	int res;
//	int idx;
//
//	int n = s.size() - k;
//	for (int i = 0; i < s.size(); i++) {
//		num.push_back(s[i] - 48);
//	}
//
//	while (k > 0) {
//
//		for (int i = 0; i < num.size(); i++) {
//			for (int j = 0; j < num.size(); j++) {
//				if (i != j) {
//					arrCurr.push_back(num[j]);
//				}
//			}
//			if (compare2Arr(arrPrev, arrCurr) == -1) {
//				arrPrev.clear();
//				arrPrev = arrCurr;
//				idx = i;
//			}
//			arrCurr.clear();
//		}
//		for (int i = 0; i < arrPrev.size(); i++) {
//			cout << arrPrev[i] << " ";
//		}
//		cout << endl;
//		num.erase(num.begin() + idx);
//		if (k > 1)
//			arrPrev.clear();
//		k--;
//	}
//	s.clear();
//	for (int i = 0; i < arrPrev.size(); i++) {
//		s.push_back(char('0' + arrPrev[i]));
//	}
//
//	return s;
//}