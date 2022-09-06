#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

class Ptr1D {
public:
	int width;
	double * ptr1d;
	Ptr1D() {};
	Ptr1D(int width) {
		this->width = width;
		ptr1d = new double[width];
		for (int i = 0; i < width; i++) {
			ptr1d[i] = 0;
		}
	};
	double& operator[](int idx) {
		return ptr1d[idx];
	}
};

class Ptr2D {
public:
	int height;
	int width;
	Ptr1D * ptr2d;
	Ptr2D() {};
	Ptr2D(int height, int width) {
		this->height = height;
		this->width = width;
		ptr2d = new Ptr1D[height];
		for (int i = 0; i < height; i++) {
			Ptr1D tmp(width);
			ptr2d[i] = tmp;
		}
	};

	Ptr1D operator[](int idx) {
		return ptr2d[idx];
	}

	void random(double rn) {
		mt19937_64 generator(time(0));
		uniform_real_distribution<double> distribution(-rn, rn);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				ptr2d[i][j] = distribution(generator);
				//ptr2d[i][j] = 1;
			}
		}
	}

	void print() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << setprecision(4) << ptr2d[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
};

class Ptr3D {
public:
	int depth;
	int height;
	int width;
	Ptr2D * ptr3d;
	Ptr3D() {};
	Ptr3D(int depth, int height, int width) {
		this->depth = depth;
		this->height = height;
		this->width = width;
		ptr3d = new Ptr2D[depth];
		for (int i = 0; i < depth; i++) {
			Ptr2D tmp(height, width);
			ptr3d[i] = tmp;
		}
	};

	Ptr2D operator[](int idx) {
		return ptr3d[idx];
	}

	void print() {
		for (int i = 0; i < depth; i++) {
			for (int j = 0; j < height; j++) {
				for (int k = 0; k < width; k++) {
					
					cout << setprecision(4) << ptr3d[i][j][k] << "\t";
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}

	void random(double rn) {
		mt19937_64 generator(time(0));
		uniform_real_distribution<double> distribution(-rn, rn);
		for (int i = 0; i < depth; i++) {
			for (int j = 0; j < height; j++) {
				for (int k = 0; k < width; k++) {
					ptr3d[i][j][k] = distribution(generator);
					//ptr3d[i][j][k] = 1;
				}
			}
		}
	}
};

class Ptr4D {
public:
	int depth2;
	int depth;
	int height;
	int width;
	Ptr3D * ptr4d;
	Ptr4D() {};
	Ptr4D(int depth2, int depth, int height, int width) {
		this->depth2 = depth2;
		this->depth = depth;
		this->height = height;
		this->width = width;
		ptr4d = new Ptr3D[depth2];
		for (int i = 0; i < depth2; i++) {
			Ptr3D tmp(depth, height, width);
			ptr4d[i] = tmp;
		}
	};

	Ptr3D operator[](int idx) {
		return ptr4d[idx];
	}

	void random(double rn) {
		mt19937_64 generator(time(0));
		uniform_real_distribution<double> distribution(-rn, rn);
		for (int i = 0; i < depth2; i++) {
			for (int j = 0; j < depth; j++) {
				for (int k = 0; k < height; k++) {
					for (int l = 0; l < width; l++) {
						ptr4d[i][j][k][l] = distribution(generator);
						//ptr4d[i][j][k][l] = 1;
					}
				}
			}
		}
	}
};
