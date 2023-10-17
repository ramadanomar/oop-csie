#include <iostream>
#include <string>

using namespace std;
static int v[] = { 0, 5, 7, 9, 12, 99, 100 };

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor


//1. v este un vector global alocat static
//calculati si returnati numarul de elemente al acestui vector
int numar_elemente() {	
	// Nu ar trebui functia sa intoarca unsigned long long?
	return (int)sizeof(v) / sizeof(int);
}

//2. Functia de mai jos returneaza maximul dintr-un vector
//alocat dinamic primit ca parametru (alaturi de dimensiune)
//daca vectorul este null sau dimensiunea <= 0
//atunci functia returneaza 0
float maxim_vector(float* vector, int dimensiune) {
	if (vector==nullptr || dimensiune <= 0) {
		return 0.0f; // Cred ca e mai safe sa ii dam cast in float decat sa dau return la 0 dar cred ca se face singura conversia
	}

	float maxim = vector[0];

	for (int i = 1; i < dimensiune; i++) {
		if (vector[i] > maxim) {
			maxim = vector[i];
		}
	}

	return maxim;
}

//3. Returnati o copie a vectorului de caractere
//primit drept parametru
char* returnare_copie_vector_caractere(const char* sir) {
	if (sir == nullptr) {
		cerr << "Problema 3: Sirul primit este null";
		return nullptr;
	}
	size_t lungime = strlen(sir);

	char* copie = nullptr;
	copie = new char[lungime + 1];
	strcpy_s(copie,lungime+1, sir);
	return copie;
}

//4. Functia de mai jos primeste ca si parametri doua stringuri
//returnati lungimea totala a celor doua stringuri
int returnare_lungime_stringuri(string s1, string s2) {
	return (int)s1.length() + (int)s2.length();
}

//5. Functia de mai jos primeste ca si parametri un string si un char*
//si returneaza true daca cele doua siruri de caractere au acelasi continut
bool siruri_egale(string sir1, char* sir2) {
	if (sir2 == nullptr) 
		return false;
	
	return sir1 == sir2;
}

//6. Functia de mai jos primeste ca si parametri o matrice alocata dinamic,
//precum si numarul de linii si de coloane
//functia returneaza true daca matricea primita ca parametru este matrice unitate
//(este patratica, iar pe diagonala principala are doar 1, iar restul elementelor sunt 0)
bool matrice_unitate(int** matrice, int linii, int coloane) {
	if (matrice == nullptr) 
		return false;
	
	if (linii != coloane)
		return false;

	for (int i = 0; i < linii; i++) {
		for (int j=0; j<coloane; j++) {
			if (i == j) {
				if (matrice[i][i] != 1)
					return false;
			}
			else {
				if (matrice[i][j] != 0)
					return false;
			}
		}
	}
	return true;
}

//7. Functia de mai jos returneaza un vector ce contine
//minimul de pe fiecare linie al unei matrice primita ca parametru
//vectorul este alocat dinamic si va contine atatea elemente cate linii are matricea
int* returnare_minim_pe_linii(int** matrice, int linii, int coloane)
{
	if (matrice == nullptr) {
		cerr << "matrice invalida";
		return nullptr;
	}

	int* intColMin = new int[linii];
	
	int minColoana = 0;

	for (int i = 0; i < linii; i++) {
		minColoana = INT_MAX;
		for (int j = 0; j < coloane; j++) {
			if (matrice[i][j] < minColoana)
				minColoana = matrice[i][j];
		}
		intColMin[i] = minColoana;
	}
	return intColMin;
}

//8. Functia de mai jos este asemanatoare celei de mai sus, doar ca transforma
//elementele vectorului intr-un sir de caractere de tip char* folosind spatii
//ex: daca vectorul returnat mai sus este [1, 2, -2] atunci rezultatul va fi "1 2 -2"
char* returnare_minim_pe_linii_ca_sir(int** matrice, int linii, int coloane)
{	
	if (matrice == nullptr) {
		cerr << "matrice invalida";
		return nullptr;
	}
	int* colMin = new int[linii];

	colMin = returnare_minim_pe_linii(matrice, linii, coloane);
	if (colMin == nullptr) {
		return nullptr;
	}

	string strColMin = "";
	for (int i = 0; i < linii; ++i) {
		if (i > 0) { 
			strColMin += " ";
		}
		strColMin += to_string(colMin[i]);
	}
	
	char* charColMin = new char[strColMin.length() + 1];
	strcpy_s(charColMin, strColMin.length() + 1, strColMin.c_str());

	delete[] colMin;
	colMin = nullptr;

	return charColMin;
}

//9. Functia de mai jos primeste drept parametri un vector alocat dinamic,
//dimensiunea sa si elementul ce se doreste a fi sters
//si returneaza vectorul obtinut prin stergerea elementului
int* sterge_element(int* vector, int dimensiune, int element)
{
	if (vector == nullptr) {
		cerr << "vector invalid";
		return nullptr;
	}
	int cate = 0;
	for (int i = 0; i < dimensiune; i++) {
		if (vector[i] == element)
			cate++;
	}
	if (cate == dimensiune) {
		return nullptr;
	}
	int* vectorSters = new int[dimensiune - cate];

	int poz = 0;
	for (int i = 0; i < dimensiune; i++) {
		if (vector[i] != element) {
			vectorSters[poz] = vector[i];
			poz++;
		}
	}

	return vectorSters;
}

//10. Functia de mai jos arhiveaza un sir de caractere primit ca parametru
//arhivarea unui sir de caractere se face prin notarea numarului de repetari
//ale unui caracter atunci cand acesta apare de mai mult (sau egal) de 2 ori consecutiv
//ex1: pentru sirul AAABBC, versiunea arhivata este 3A2BC
//ex2: pentru sirul XYYYYYYYZTTT, versiunea arhivata este X7YZ3T
//precizare: sirul contine doar caractere uppercase (litere mari)
char* arhivare_sir(char* sir) 
{
	if (sir == nullptr) {
		cerr << "invalid string";
		return nullptr;
	}

	unsigned int cate = 0;
	unsigned int poz = 0;
	char gas = sir[0];
	unsigned int idx = 0;

	string arhivat = "";

	while (poz < strlen(sir)) {
		gas = sir[poz];
		idx = poz;
		cate = 0;
		while (gas == sir[idx]) {
			cate++;
			idx++;
		}
		if (cate > 1) {
			arhivat += to_string(cate);
		}
		arhivat += gas;
		poz += cate;
	}
	
	char* charArhivat = new char[(strlen(sir) + 1)];
	strcpy_s(charArhivat, strlen(sir) + 1, arhivat.c_str());

	return charArhivat;
}

int main() 
{
	char test1[] = "XYYYYYYYZTTT";
	arhivare_sir(test1);
	return 0;
}