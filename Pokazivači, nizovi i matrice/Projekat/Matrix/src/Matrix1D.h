/*
	Autor : Mirko Vojinović
	Datum : 31.3.2020.
*/

#pragma once
#include "Matrix.h"
class Matrix1D : public Matrix
{

public:
	Matrix1D(int rows, int cols, int range);
	void print();
	void process();
	void rotate();
	~Matrix1D();

private:
	int rows;
	int cols;

	// ZA URADITI: 
	// Napisati definiciju polja koje predstavlja matricu

	int *matrix1D;
};

