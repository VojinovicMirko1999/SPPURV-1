/*
	Autor : Mirko Vojinović
	Datum : 31.3.2020.
*/

#include "Matrix2D.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/* Konstruktor matrice:

	- matrica je realizovana pomoću dvostrukog pokazivača koji pokazuje na niz pokazivača;

	- svaki element niza pokazivača pokazuje na novi niz;

	- prolaskom pomoću dvostruke for petlje kroz celu matricu, svakom elementu dodeljena je slučajna vrednost pomoću f-je rand();

	- indeksiranje je klasično : ime_matrice[indeks_vrste][indeks_kolone].
*/

Matrix2D::Matrix2D(int rows, int cols, int range) : rows(rows), cols(cols)
{
	// ZA URADITI:
	// Zauzeti memoriju za matricu dimenzija rows*cols

	mat = new int *[rows];

	for (int i = 0; i < rows; i++) {
		mat[i] = new int[cols];
	}

	// Matricu inicijalizovati nasumičnim vrednostima u opsegu [0, range)

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mat[i][j] = rand() % (range + 1);
		}
	}
}


/* Funkcija koja štampa sadržaj matrice na terminal:
	
	- ideja je da se prodje kroz matricu pomoću dvostruke for petlje, preuzme sadržaj svakog elementa matrice,
	  zatim isti ispiše na terminal;

	- indeksiranje je isto kao kod dodeljivanja vrednosti elementima.

*/

void Matrix2D::print()
{
	// ZA URADITI:
	// Odštampati sadržaj matrice na ekran

	cout << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << mat[i][j] << "\t";
		}

		cout << endl << endl;
	}
}

/* Funkcija koja broji neparne elemente u svakoj koloni i ispisuje ih na terminal:

	- ideja i realizacija ove funkcije je većinski ista kao kod 1D matrice (objašnjeno u Matrica1D.cpp), osim dela indeksiranja elemenata -> ime_matrice[indeks_kolone][indeks_vrste]
*/

void Matrix2D::process()
{
	// ZA URADITI:
	// Realizovati zadatu obradu nad matricom

	int i, j;

	int broj;
	int brojNeparnihBrojeva = 0;

	for (i = 0; i < cols; i++) {
		for (j = 0; j < rows; j++) {
			broj = mat[j][i];
			if (broj % 2 != 0) {
				brojNeparnihBrojeva += 1;
			}
		}
		cout << "Broj neparnih elemenata u " << i + 1 << ". koloni = " << brojNeparnihBrojeva << endl;
		brojNeparnihBrojeva = 0;
	}
}

/* Funkcija koja rotira svoj sadržaj za 90 stepeni:

	- rotacija za 90 stepeni predstavlja zamenu prve vrste i poslednje kolone, druge vrste i pretposlednje kolone..., poslednje vrste i prve kolone;

	- ideja je da se napravi potpuno nova matrica koja prima rotiran sadržaj početne matrice;

	- nakon raspisivanja indeksa elemenata početne i rotirane matrice, može se zaključiti sledeće:
			
			1.kod početne matrice promena vrednosti indeksa vrsta dešava se tek nakon n-ostruke promene vrednost indeksa kolona (n - broj kolona);
			2.kod rotirane matrice promena vrednosti indeksa kolona dešava se tek nakon n-ostruke promene vrednosti indeksa vrsta (n - broj vrsta);

	- primer 3x3 matrice : početna matrica:       rotirana matrica:
								
								V K	                    V K
								0 0                     2 0
								0 1                     1 0
								0 2						0 0
								1 0						2 1
								1 1						1 1
								1 2						0 1
								2 0						2 2
								2 1						1 2
								2 2						0 2

							
							00	01	02				20	10	00

							10	11	12				21	11	01

							20	21	22				22	12	02

						  
	- na osnovu prethodnih činjenica => indeksiranje početne matrice = ime_matrice(broj_kolona - kolona_iterator - 1][red_iterator];

	- nakon transfera rotiran_sadržaj_početne_matrice => sadržaj_nove_matrice, početna matrica preuzima sadržaj novokreirane matrice.
*/

void Matrix2D::rotate() {

	int** newMatrix = new int*[rows];

	for (int i = 0; i < cols; i++) {
		newMatrix[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix[i][j] = mat[cols - j - 1][i];
		}
	}

	mat = newMatrix;
	
}

/* Destruktor objekta koji predstavlja matricu:
	
	- ideja je da se prvo obrišu nizovi koji su zapravo elementi jednog niza, zatim niz kom oni pripadaju;
	- brisanje se vrši pomoću operatora delete[].

*/

Matrix2D::~Matrix2D()
{
	// ZA URADITI:
	// Osloboditi zauzetu memoriju

	for (int i = 0; i < rows; i++) {
		delete[] mat[i];
	}

	delete[] mat;
}
