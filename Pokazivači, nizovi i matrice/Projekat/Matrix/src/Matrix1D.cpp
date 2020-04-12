/*
	Autor : Mirko Vojinović
	Datum : 31.3.2020.
*/


#include "Matrix1D.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

/* Konstruktor matrice:

	- matrica je realizovana pomoću jednodimenzionog niza čija je memorija zauzeta dinamički pomoću operatora new;

    - prolaskom pomoću for petlje kroz ceo niz, svakom elementu dodeljena je slučajna vrednost pomoću f-je rand(). 
*/
Matrix1D::Matrix1D(int rows, int cols, int range) : rows(rows), cols(cols)
{
	// ZA URADITI:
	// Zauzeti memoriju za matricu dimenzija rows*cols

	matrix1D = new int[rows * cols];

	// Matricu inicijalizovati nasumičnim vrednostima u opsegu [0, range)

	for (int i = 0; i < rows * cols; i++) {
		matrix1D[i] = rand() % (range + 1);
	}
}

/* Funkcija štampanja matrice:

	- prolaskom pomoću dve for petlje kroz niz, pristupa se svakom elementu niza i isti se ispisuje na terminal;

	- ideja je da prva for petlja traje dok njen brojač (i) ne stigne do vrednosti (broj vrsta - 1), a druga dok njen
	  brojač (j) ne stigne do vrednosti (broj kolona - 1);

	- ispis prelazi u novi red nakon svakog završetka druge(unutrašnje) petlje, jer to logički prestavlja kraj jednog reda matrice;

	- Promenljiva index predstavlja indeks svakog člana matrice i iterativno se povećava dok ne stigne do kraja.
*/

void Matrix1D::print()
{
	// ZA URADITI:
	// Odštampati sadržaj matrice na ekran

	int index = 0;

	cout << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix1D[index] << "\t";
			index++;
		}
		cout << endl << endl;
	}

}

/* Funkcija koja broji neparne elemente u svakoj koloni i ispisuje ih na terminal:
	
	- kreirane su 4 promenljive: 1. i - predstavlja brojač za spoljnu petlju
								 2. j - predstavlja brojač za unutrašnju petlju
								 3. broj - preuzima sadržaj svakog elementa matrice i proverava mu parnost
								 4. brojNeparnihBrojeva - u zavisnosti od parnosti promenljive broj, povećava ili zadržava svoju vrednost;
	
	- s obzirom da funkcija broji neparne elemente u svakoj koloni, spoljna petlja prolazi kroz kolone, a unutrašnja kroz vrste;

	- vrednost indeksa prvih članova vrsta povećava se za onoliko koliko ima vrsta(kolona) u matrici, tj. po izrazu (i + j * broj_kolona);
	
	- nakon svakog izvršavanja unutrašnje petlje, na terminal se ispisuje podatak o broju neparnih elemenata te kolone.
*/

void Matrix1D::process()
{
	// ZA URADITI:
	// Realizovati zadatu obradu nad matricom

	int i, j;
	int broj;
	int brojNeparnihBrojeva = 0;

	for (i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			broj = matrix1D[i + j * cols];

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

	- nakon transfera, početna matrica preuzima sadržaj novokreirane matrice;

	- s obzirom da je matrica realizovana pomoću jednodimenzionog niza, kroz matricu se iterira od prvog elementa poslednje kolone do
	  poslednjeg elementa prve vrste;

	- iteracijom se svaki element matrice prosledjuje na kraj niza koji predstavlja novokreiranu matricu;

	- nakon prethodnih činjenica može se zaključiti da je logika prolaska kroz matricu i preuzimanja njenog sadržaja 
	  obrnuta od logike kod funkcije process, zbog toga, indeksi početne matrice se preuzimaju po izrazu (i - j * broj_kolona), gde nam 
	  i predstavlja brojač spoljne petlje, a j brojač unutrašnje petlje.
	  

*/

void Matrix1D::rotate() {
	
	int i, j;
	int index = 0;

	int size = rows * cols;

	int* temp = new int[rows * cols];

	for (i = size - cols; i < size; i++) {
		for (int j = 0; j < rows; j++) {
			temp[index] = matrix1D[i - j * cols];
			index++;
		}
	}

	matrix1D = temp;
}


/* Destruktor objekta koji predstavlja matricu:
	
	- briše sadržaj pomoću operatora delete[].
   
*/ 

Matrix1D::~Matrix1D()
{
	// ZA URADITI:
	// Osloboditi zauzetu memoriju

	delete[] matrix1D;
}
