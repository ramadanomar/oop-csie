#include <iostream>
#include <string>
using namespace std;

class Cartus
{
private:
	string producator = "";
	int nrTotalPagini = 0;
public:
	//Cartus(string producator = "", int nrTotalPagini = 0) {
	//	this->producator = producator;
	//	this->nrTotalPagini = nrTotalPagini;
	//}

	int getNrTotalPagini() {
		return nrTotalPagini;
	}
};

class Imprimanta
{
private:
	const int serialNumber;
	char* producator = nullptr;
	int nrPaginiPrintate;
	static string tipImprimanta;
	Cartus cartus; 

public:

	Imprimanta() : serialNumber(1)
	{
		nrPaginiPrintate = 0;

		if (producator != nullptr) {
			delete[] producator;
		}
		char* tmp = new char[1];
		*tmp = '\0';
		producator = tmp;
	}

	Imprimanta(int serialNumber, char* producator, int nrPaginiPrintate) : serialNumber(serialNumber)
	{
		if (this->producator != nullptr) {
			delete[] this->producator;
			this->producator = nullptr;
		}
		
		if (producator != nullptr) {
			char* newProducator = new char[strlen(producator) + 1];
			strcpy_s(newProducator, strlen(producator) + 1, producator);
			this->producator = newProducator;
		}
		this->nrPaginiPrintate = nrPaginiPrintate;
	}

	Imprimanta(const Imprimanta& copie) : serialNumber(copie.serialNumber) {
		nrPaginiPrintate = copie.nrPaginiPrintate;
		if (copie.producator != nullptr) {
			producator = new char[strlen(copie.producator) + 1];
			strcpy_s(producator, strlen(copie.producator) + 1, copie.producator);
		}
	}

	~Imprimanta() {
		delete[] producator;
		producator = nullptr; // nu sunt sigur daca mai e nevoie de asta dar nu strica
	}

	Imprimanta& operator=(const Imprimanta& other) {
		if (this != &other) { 
			if (producator != nullptr) { // nu cred ca e posibil sa fie un pointer hanging ca deja l am sters de peste tot dar nu cred ca doare sa verific si aici?
				delete[] producator;
			}
			producator = new char[strlen(other.producator) + 1];
			strcpy_s(producator, strlen(other.producator) + 1, other.producator);
			nrPaginiPrintate = other.nrPaginiPrintate;
		}
		return *this; 
	}

	static string getTipImprimanta()
	{
		return tipImprimanta;
	}

	static void setTipImprimanta(const string& tip) {
		tipImprimanta = tip;
	}

	static long getTotalPaginiPerProducator(Imprimanta* imprimante, int nrImprimante, char* producator)
	{
		long totalPagini = 0;
		for (int i = 0; i < nrImprimante; i++) {
			if (strcmp(imprimante[i].producator, producator) == 0) {
				totalPagini += imprimante[i].nrPaginiPrintate;
			}
		}
		return totalPagini;
	}

	void setCartus(const Cartus& c)
	{
		cartus = c;
	}

	Cartus getCartus()
	{
		return cartus;
	}

	int getNumarPaginiRamase()
	{
		int maxPaginiCartus = cartus.getNrTotalPagini();
		return max(maxPaginiCartus - nrPaginiPrintate, 0);
	}
};
string Imprimanta::tipImprimanta = "Cerneala";



//1. Modificati constructorul implicit din clasa Imprimanta de mai sus
//acesta va initializa producatorul cu un sir de caractere vid ("")
//si numarul de pagini printate cu 0

//2. Modificati constructorul cu 3 parametri: serialNumber, producator, nrPaginiPrintate
//acesta va initializa cele 3 atribute cu valorile primite
//atributul constant nu va mai fi initializat la definire
//constructorul implicit va initializa acest atribut cu 1

//3. Adaugati un destructor in clasa pentru a dezaloca
//campul(urile) alocate dinamic
//
//--------------------------------------------------------------------------------

//4. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor
//se va realiza si copierea campului constant
// 
//--------------------------------------------------------------------------------

//5. Modificati supraincarcarea pentru operator=
//aceasta va realiza o copie in profunzime (deep copy) a obiectelor
//operatorul accepta apeluri in cascada

//--------------------------------------------------------------------------------
//
//6. Initializati membrul static tipImprimanta cu valoarea "Cerneala"
//
//--------------------------------------------------------------------------------

//7. Modificati metodele de acces pentru campul static
//astfel incat acestea sa permita modificarea si obtinerea valorii acestui camp

//8. Modificati metoda getTotalPaginiPerProducator pentru a returna numarul total de pagini
//printate de toate imprimantele din vectorul de imprimante primit ca parametru
//care sunt produse de producatorul primit drept parametru
//De ex daca avem 3 imprimante: "Dell" - 120 de pagini, "HP" - 150 de pagini, "Dell" - 170 de pagini
//functia va returna 290 de pagini daca primeste ca parametru producatorul "Dell"
//si 150 de pagini daca primeste ca parametru producatorul "HP"
//pentru orice alt producator functia va returna 0

//9. Modelati o relatie de compunere intre clasa Cartus si clasa Imprimanta
//astfel incat sa reiasa faptul ca Imprimanta are (foloseste) un Cartus
//Modificati metoda setCartus astfel incat sa puteti schimba cartusul curent al imprimantei
//cu cel primit drept parametru si metoda getCartus pentru a returna cartusul curent

//10. Modificati metoda getNumarPaginiRamase astfel incat sa returneze numarul de pagini
//pe care imprimanta respectiva la mai poate printa avand in vedere ca stim 
//cate pagini se pot printa maxim cu cartusul curent si cate pagini au fost printate pana acum
//functia nu poate returna o valoare negativa, asa ca daca numarul curent de pagini il
//depaseste pe cel maxim, va returna 0

int main() 
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
	//Test here the functions that you need and use the debugger to identify the problems
}