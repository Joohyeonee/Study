#include <iostream>
#include <vector>
#include <stdio.h>
#include <random>
#include <iomanip>

using namespace std;

void selection_sort() {
	int i, j, min, index, temp;
	int space[10];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 10);

	for (int i = 0; i < 10; i++) {
		space[i] = dis(gen);
	}

	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (space[j] < min) {
				min = space[j];
				index = j;
			}
		}
		temp = space[i];
		space[i] = min;
		space[index] = temp; // swaping
	}

	cout << "selection sort result" << endl;
	for (i = 0; i < 10; i++) {
		cout << space[i] << endl;
	}
}



void bubble_sort() {
	int min = -1;
	int space[10];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 10);

	for (int i = 0; i < 10; i++) {
		space[i] = dis(gen);
	}
	
	for (int i = 0; i < 10; i++) {
		int temp = -1;
		for (int j = 0; j < 9; j++) {
			if (space[j] > space[j+1]) {
				temp = space[j];
				space[j] = space[j+1];
				space[j+1] = temp;
			}
		}
	}

	printf("bubble sort result\n");
	for (int i = 0; i < 10; i++) {
		printf("#%d %d\n", i, space[i]);
	}
}



void insertion_sort() {
	int min = -1;
	int space[10];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 10);

	for (int i = 0; i < 10; i++) {
		space[i] = dis(gen);
	}

	for (int i = 1; i < 10; i++) {
		int temp = -1;
		for (int j = 0; j < i; j++) {
			if (space[i] < space[j]) {
				temp = space[j];
				space[j] = space[i];
				space[i] = temp;
			}
		}
	}

	printf("insertion sort result\n");
	for (int i = 0; i < 10; i++) {
		printf("#%d %d\n", i, space[i]);
	}
}



void quick_sort() {
	int min = -1;
	int space[10];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 10);
	int len = 10;

	for (int i = 0; i < len; i++) {
		space[i] = dis(gen);
	}

	int pivot = space[0];
	int temp = -1;
	for (int i = 1; i < len/2; i++) {
		if (space[i] > space[len - i]) {
			temp = space[i];
			space[i] = space[len - i];
			space[len - i] = space[i];
		}
	}

	printf("insertion sort result\n");
	for (int i = 0; i < 10; i++) {
		printf("#%d %d\n", i, space[i]);
	}
}


int linear_search() {
	int space[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int key = 15;
	int idx = -1;
	for (int i = 0; i < 10; i++) {
		if (space[i] == 15) {
			idx = i;
		}
	}
	return idx + 1;
}

int binary_search() {
	int space[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int key = 15;
	int start = 0;
	int end = 9;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2; // 중앙 값

		if (space[mid] == key) { // key 값을 찾았을 때
			return mid;
		}
		else if (space[mid] > key) { // key 값이 mid의 값보다 작을때 (왼쪽으로)
			end = mid - 1;
		}
		else { // key 값이 mid의 값보다 클 때(오른쪽으로)
			start = mid + 1;
		}
	}
}



int main() {

	linear_search();

	system("pause");
	return 0;
};

