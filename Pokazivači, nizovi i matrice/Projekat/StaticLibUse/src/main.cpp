/*
	Autor : Mirko Vojinović 
	Datum : 31.3.2020.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


//Relativna putanja do fajlova statičke biblioteke

#include "../../Matrix/src/Matrix1D.h"
#include "../../Matrix/src/Matrix2D.h"
#include "../../Matrix/src/MatrixVec.h"
#include "../../Matrix/src/Matrix.h"

#define NUMBER_RANGE 10

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Niste uneli potrebne argumente za pokretanje programa!" << endl;
		cout << "Argumenti komandne linije treba da budu:" << endl;
		cout << "1. N dimenzija matrice" << endl;
		cout << "2. M dimenzija matrice" << endl;
		exit(-1);
	}

	// inicijalizacija generatora nasumičnih brojeva
	srand(unsigned int(time(NULL)));

	int rowNum = atoi(argv[1]);
	int colNum = atoi(argv[2]);

	// a)
	cout << endl << endl << "a) Matrix 1D representation" << endl;

	// ZA URADITI:
	// Napraviti objekat klase Matrix1D

	Matrix1D matrix1D(rowNum, colNum, NUMBER_RANGE);

	// Pozvati metodu print nad objektom

	matrix1D.print();

	// Pozvati metodu process nad objektom

	matrix1D.process();

	//DODATNI
	//Rotacija

	if (rowNum == colNum) {
		matrix1D.rotate();

		cout << endl << "Rotirana 1D matrica:" << endl << endl;
		matrix1D.print();
	}
	else
		cout << endl << "Rotiranje nije moguce.Broj vrsta i broj kolona nije jednak!";


	//b)
	cout << endl << endl << "b) Matrix 2D representation" << endl;

	// ZA URADITI:
	// Napraviti objekat klase Matrix2D

	Matrix2D matrix2D(rowNum, colNum, NUMBER_RANGE);

	// Pozvati metodu print nad objektom

	matrix2D.print();

	// Pozvati metodu process nad objektom

	matrix2D.process();

	//DODATNI ZADATAK
	// Rotiranje
	
	if (rowNum == colNum) {
		matrix2D.rotate();

		cout << endl << "Rotirana 2D matrica:" << endl << endl;
		matrix2D.print();
	}
	else
		cout << endl << "Rotiranje nije moguce.Broj vrsta i broj kolona nije jednak!";

	//c)
	cout << endl << endl << "c) Matrix vector of vector representation" << endl;

	// ZA URADITI:
	// Napraviti objekat klase MatrixVec

	MatrixVec matrixVec(rowNum, colNum, NUMBER_RANGE);

	// Pozvati metodu print nad objektom

	matrixVec.print();

	// Pozvati metodu process nad objektom

	matrixVec.process();

	cout << endl;

	//DODATNI
	//Rotacija
	
	if (rowNum == colNum) {
		matrixVec.rotate();
		cout << endl << "Rotirana matrica vektora:" << endl << endl;
		matrixVec.print();
	}
	else
		cout << endl << "Rotiranje nije moguce.Broj vrsta i broj kolona nije jednak!" << endl << endl;
	
	return 0;
}


