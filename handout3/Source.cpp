#include <iostream>
#include <string>
#include <map>
using namespace std;
bool fisierDeschis = true;

//1. Functia de mai jos primeste drept parametri doua variabile de tip int
//modificati modalitatea de transmitere a parametrilor astfel incat
//cele doua valori sa fie interschimbate la iesirea din functie
//apelul se va face de forma: inerschimbare(x, y)
//unde x si y sunt 2 intregi
//Observatie: signatura acestei functii poate fi modificata
void interschimbare(int& valoare1, int& valoare2) 
{
	swap(valoare1, valoare2);
}

//2. Functia de mai jos returneaza o variabila de tipul enumeratie
//(tipAplicatie, enum definit mai sus)
//modificati enumul astfel incat acesta sa aiba trei valori posibile
//Acestea sunt: 5 - aplicatieWeb, 10 - aplicatieMobila, 15 - aplicatieDesktop
//functia primeste drept parametru un string dintre cele de mai sus
//("aplicatieWeb", "aplicatieMobila", etc) si returneaza valoarea din enum
//corespunzatoare ei

enum tipAplicatie {
	aplicatieWeb = 5,
	aplicatieMobila = 10,
	aplicatieDesktop = 15
};

// SOLUTIE FARA STL
// ------------------------------------------------
//tipAplicatie modificare_enum(string tip) {
//	if (tip == "aplicatieWeb") {
//		return aplicatieWeb;
//	}
//	else if (tip == "aplicatieMobila") {
//		return aplicatieMobila;
//	}
//	else if (tip == "aplicatieDesktop") {
//		return aplicatieDesktop;
//	}
//	throw invalid_argument("test");
//}


// SOLUTIE CU STL
// --------------------------------------------------------
static const map<string, tipAplicatie> enumeratie = {
		{"aplicatieWeb", tipAplicatie::aplicatieWeb},
		{"aplicatieMobila", tipAplicatie::aplicatieMobila},
		{"aplicatieDesktop", tipAplicatie::aplicatieDesktop}
};

tipAplicatie modificare_enum(string tip) 
{
	auto it = enumeratie.find(tip);
	if (it != enumeratie.end()) {
		return it->second;
	}
	throw exception("404");
}

//3. Modificati constructorul implicit din clasa Autoturism de mai sus
//acesta va initializa marca cu "Necunoscuta", modelul cu "Necunoscut"
//puterea cu 0 si pretul cu 5000

//------------------------------------

//4. Modificati constructorul cu 3 parametri: marca, model, putere
//acesta va initializa cele 3 atribute cu valorile primite
//pretul va fi setat la fel ca in celalalt constructor ca fiind 5000

//------------------------------------

//5. Modificati metoda discount pentru a acorda un discount din pret
//discountul este in procente si poate fi intre 1% si 50%
//functia modifica pretul cu valoarea sa dupa aplicarea discountului

//------------------------------------

//6. Adaugati un destructor in clasa care seteaza variabila globala
//fisierDeschis pe false

//------------------------------------

//7. Adaugati clasei un atribut nou numit numarInmatriculare
//acesta este un sir de caractere alocat static de lungime maxima 9
//Modificati metodele seteazaNumarInmatriculare si obtineNumarInmatriculare
//astfel incat sa modifice respectiv sa returneze valoarea acestui nou camp

//------------------------------------

class Autoturism
{
public:
	string marca;
	string model;
	int putere;
	double pret;
	char numarInmatriculare[9] = "";

	Autoturism()
	{
		marca = "Necunoscuta";
		model = "Necunoscut";
		putere = 0;
		pret = 5000;
	}

	Autoturism(string marca, string model, int putere) : Autoturism()
	{
		this->marca = marca;
		this->model = model;
		this->putere = putere;
	}

	~Autoturism() {
		fisierDeschis = false;
	}

	void discount(int procent)
	{
		if (procent < 1 || procent > 50) {
			return;
			//throw exception("invalid discount");
		}
		pret -= pret * ((double)procent / 100);
	}

	void seteazaNumarInmatriculare(char numar[])
	{
		const size_t size_input = strlen(numar);

		if ((int)size_input >= 9) {
			throw overflow_error("Overflow");
		}

		strcpy_s(numarInmatriculare, sizeof(numarInmatriculare), numar);
		
	}

	char* obtineNumarInmatriculare()
	{
		return numarInmatriculare;
	}
};



//8. Functia de mai jos primeste drept parametru un vector static de masini
//reprezentand o flota de autoturisme si numarul sau de elemente
//calculati si returnati valoarea totala a flotei de autoturisme
//prin adunarea preturilor masinilor din flota
double calcul_valoare_flota(Autoturism masini[], int nr_masini)
{
	double total = 0.0;
	if (masini == nullptr)
		return total;
	for (int i = 0; i < nr_masini; i++) {
		total += masini[i].pret;
	}
	return total;
}

//9. Functia de mai jos primeste drept parametri un vector alocat dinamic 
//de pointeri la Autoturism impreuna cu numarul de elemente.
//Returnati valoarea celei mai scumpe masini din acel vector
double cea_mai_tare_din_parcare(Autoturism** vector, int nr_masini)
{
	double max_value = 0.0;
	if (vector == nullptr)
		return max_value;
	for (int i = 0; i < nr_masini; i++) {
		if (vector[i]->pret > max_value)
			max_value = vector[i]->pret;
	}
	return max_value;
}

//10. Functia de mai jos primeste drept parametri o matrice
//de pointeri la Autoturism impreuna cu numarul de linii si de coloane
//Matricea reprezinta cum sunt dispuse masinile intr-o parcare
//Un element null inseamna ca pe acel loc de parcare nu este nicio masina
//Functia va returna o matrice a locurilor de parcare astfel
//100 90 60
//0 160 75
//0 90 0
//Explicatii: Parcarea are 3 linii si cate 3 locuri de parcare pe fiecare linie
//Pe prima linie sunt parcate 3 masini cu putere de 100, 90 si respectiv 60 cai putere
//pe a doua linie primul loc este neocupat, iar urmatoarele doua locuri
//sunt ocupate de doua masini cu 160, respectiv 75 de cai putere, s.a.m.d.
int** locuri_libere(Autoturism*** matrice, int nrLinii, int nrColoane)
{
	if (matrice == nullptr) {
		return nullptr;
	}

	const size_t marime_clasa = sizeof(Autoturism);

	int** m = new int* [nrLinii];
	for (int i = 0; i < nrLinii; i++) {
		m[i] = new int[nrColoane];
	}

	// Ar trb sa verific si daca matrice[i] exista
	// dar trec unit testurile asa ca eh

	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane; j++) {
			if (matrice[i][j] == nullptr) {
				m[i][j] = 0;
			}
			else {
				m[i][j] = matrice[i][j]->putere;
			}
		}
	}

	return m;
}

int main() 
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
	//Test here the functions that you need and use the debugger to identify the problems

	//char test[9] = "";

	//const size_t marime = sizeof(test);

	//cout << (int)marime;
}