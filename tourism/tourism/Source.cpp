#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<time.h>
#include<string.h>

using namespace std;

FILE* openFile(char nameFile[]) {
	FILE* file = fopen(nameFile, "r");
	if (!file) {
		cout << "file not found !" << endl;
		exit(0);
	}
	else cout << "open file success !" << endl;
	return file;
}

void closeFile(FILE* file) {
	fclose(file);
}



int main() {

	char nameFile[20] = "tourism.inp";
	FILE* finp;
	FILE* fout;
	finp = openFile(nameFile);

	closeFile(finp);
	return 0;
}