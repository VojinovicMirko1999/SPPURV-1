/*
	Autor : Mirko Vojinović
	Datum : 31.3.2020.
*/

#include "MatrixVec.h"
#include <cstdlib>
#include <iostream>

using namespace std;


/* Konstruktor matrice:

	- matrica je realizovana pomoću vektora koji kao elemente prima nove vektore;

	- vektor se popunjava dok mu broj elemenata ne stigne do broja vrsta;

	- broj elemenata glavnog vektora predstavlja broj vrsta, a broj elemenata ugnježdenih vektora(kod svakog je broj isti) predstavlja broj kolona;

	- prolaskom pomoću dvostruke for petlje kroz celu matricu, svakom elementu dodeljena je slučajna vrednost pomoću f-je rand();

	- indeksiranje je klasično : ime_matrice[indeks_vrste][indeks_kolone].
*/

MatrixVec::MatrixVec(int rows, int cols, int range) : rows(rows), cols(cols)
{
	// ZA URADITI:
	// Zauzeti memoriju za matricu dimenzija rows*cols
	vector<int> colVec(cols);

	for (int i = 0; i < rows; i++) {
		matrixVec.push_back(colVec);
	}

	// Matricu inicijalizovati nasumičnim vrednostima u opsegu [0, range)

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrixVec[i][j] = rand() % (range + 1);
		}
	}
}

/*	Funkcija koja štampa sadržaj matrice na terminal:
	
		- ideja i realizacija su potpuno iste kao kod 2D matrice (objašnjeno u Matrica2D.cpp).
 
*/


void MatrixVec::print()
{
	// ZA URADITI:
	// Odštampati sadržaj matrice na ekran

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrixVec[i][j] << "\t";
		}
		cout << endl << endl;
	}

}

/* Funkcija koja broji neparne elemente u svakoj koloni i ispisuje ih na terminal:

	- ideja i realizacija su potpuno iste kao kod 2D matrice (objašnjeno u Matrica2D.cpp).

*/

void MatrixVec::process()
{
	// ZA URADITI:
	// Realizovati zadatu obradu nad matricom

	int i, j;
	int broj;
	int brojNeparnihBrojeva = 0;

	for (i = 0; i < cols; i++) {
		for (j = 0; j < rows; j++) {
			broj = matrixVec[j][i];
			if (broj % 2 != 0) {
				brojNeparnihBrojeva += 1;
			}
		}
		cout << "Broj neparnih elemenata u " << i + 1 << ". koloni = " << brojNeparnihBrojeva << endl;
		brojNeparnihBrojeva = 0;
	}
}

/*	Funkcija koja rotira svoj sadržaj za 90 stepeni:
	
		- ideja i realizacija su potpuno iste kao kod 2D matrice (objašnjeno u Matrica2D.cpp).

*/

void MatrixVec::rotate() {
		
	vector<vector<int>> newVec;
	vector<int> newVecCols(cols);

	for (int i = 0; i < rows; i++) {
		newVec.push_back(newVecCols);
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newVec[i][j] = matrixVec[cols - j - 1][i];
		}
	}

	matrixVec = newVec;
}



