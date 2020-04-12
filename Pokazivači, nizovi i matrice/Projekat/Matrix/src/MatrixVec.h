/*
	Autor : Mirko Vojinović
	Datum : 31.3.2020.
*/

#pragma once
#include "Matrix.h"
#include <vector>


using namespace std;

class MatrixVec : public Matrix
{

public:
	MatrixVec(int rows, int cols, int range);
	void print();
	void process();
	void rotate();



private:
	// ZA URADITI: 
	// Napisati definiciju polja koje predstavlja matricu

	vector<vector<int>> matrixVec;
	int rows;
	int cols;
};

