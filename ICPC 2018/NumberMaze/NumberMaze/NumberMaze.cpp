#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int points[108][2] = { 0 };
int n;
int A[108] = { 0 };
float maxArea = 0;

void DienTich()
{
	float area = (float)abs((points[A[1]][0] - points[A[0]][0]) * (points[A[2]][1] - points[A[0]][1]) - (points[A[2]][0] - points[A[0]][0]) * (points[A[1]][1] - points[A[0]][1])) / 2;

	if (area > maxArea) {
		maxArea = area;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> points[i][0] >> points[i][1];
	}

	int i;
	for (i = 0; i < 3; i++)
	{
		A[i] = i;
	}
	DienTich();
	i = 3 - 1;
	while (i >= 0)
	{
		if (A[i] < n - 3 + i)
		{
			A[i]++;
			for (int j = i + 1; j < 3; j++)
			{
				A[j] = A[j - 1] + 1;
			}

			DienTich();

			i = 3 - 1;
		}
		else { i--; }
	}

	printf("%.1f", maxArea);
	return 0;
}

