#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void nhap(int& n) {

	scanf("%d", &n);
}

int proc(int n) {

	int i = 1;
	int s = 0;
	while (n > 0) {
		s += i;
		if (s >= n) return i - 1;
		i++;
	}

	return 0;
}

void xuat(int kq) {

	printf("%d", kq);
}

int main() {
	int n;
	int kq;
	nhap(n);
	kq = proc(n);
	xuat(kq);
	return 0;
}