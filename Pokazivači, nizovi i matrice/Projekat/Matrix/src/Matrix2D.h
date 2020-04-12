/*
	Autor : Mirko Vojinović
	Datum : 31.3.2020.
*/

#pragma once
#include "Matrix.h"

class Matrix2D : public Matrix
{

public:
	Matrix2D(int rows, int cols, int range);
	void print();
	void process();
	void rotate();
	~Matrix2D();

private:

	int rows;
	int cols;

	// ZA URADITI: 
	// Napisati definiciju polja koje predstavlja matricu

	int** mat;


};

