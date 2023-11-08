#include <iostream>
#include <string>
using namespace std;

class Autoturism
{
private:
	string marca;
	string model;
	int putere;
	double pret;
	float* distanteParcurse;
	//the number of elements for the array above
	int nrDrumuri; //nr de elemente al vectorului de mai sus
	char* taraDeProductie;

public:
	Autoturism()
	{
		marca = "Necunoscuta";
		model = "Necunoscut";
		putere = 0;
		pret = 5000;
		distanteParcurse = nullptr;
		nrDrumuri = 0;
		taraDeProductie = nullptr;
	}

	Autoturism(string marca, string model, int putere) : Autoturism()
	{
		this->marca = marca;
		this->model = model;
		this->putere = putere;
	}

	Autoturism(string marca, string model, float* distante, int nrDrumuri) : Autoturism()
	{
		this->marca = marca;
		this->model = model;
		if (distante != nullptr && nrDrumuri > 0) {
			distanteParcurse = new float[nrDrumuri];
			for (int i = 0; i < nrDrumuri; i++) {
				distanteParcurse[i] = distante[i];
			}
			this->nrDrumuri = nrDrumuri;
		}
	}

	Autoturism(const Autoturism& copie) {
		marca = copie.marca;
		model = copie.model;
		putere = copie.putere;
		pret = copie.pret;
		nrDrumuri = copie.nrDrumuri;

		if (copie.distanteParcurse != nullptr && copie.nrDrumuri > 0) {
			distanteParcurse = new float[copie.nrDrumuri];
			for (int i = 0; i < copie.nrDrumuri; i++) {
				distanteParcurse[i] = copie.distanteParcurse[i];
			}
		}
		else {
			distanteParcurse = nullptr;
			nrDrumuri = 0;
		}

		if (copie.taraDeProductie != nullptr) {
			taraDeProductie = new char[strlen(copie.taraDeProductie) + 1];
			strcpy_s(taraDeProductie, strlen(copie.taraDeProductie) + 1, copie.taraDeProductie);
		}
	}

	~Autoturism() {
		if (distanteParcurse != nullptr)
			delete[] distanteParcurse;
		distanteParcurse = nullptr; // Nu stiu daca mai trebuie sa facem asta tinand cont ca obiectul oricum va fi sters.
		if (taraDeProductie != nullptr)
			delete[] taraDeProductie;
		taraDeProductie = nullptr;
	}

	string getMarca()
	{
		return marca;
	}

	void setMarca(string marca)
	{
		if (marca.length() >= 3) {
			this->marca = marca;
		}
	}

	int getNrDrumuri()
	{
		return nrDrumuri;
	}

	float* getDistanteParcurse()
	{
		if (distanteParcurse != nullptr && nrDrumuri > 0) {
			float* copie = new float[nrDrumuri];
			for (int i = 0; i < nrDrumuri; i++) {
				copie[i] = distanteParcurse[i];
			}
			return copie;
		}
		return nullptr; // cred ca ar fi mers sa intorc distanteParcurse ca va fi nullptr in orice caz in care nu a fost alocat (toti constructorii au valoare implicita)
		// dar nu vreau sa risc
	}

	void setDistante(float* distante, int numarDrumuri)
	{
		if (distante == nullptr || nrDrumuri < 1) {
			throw invalid_argument("Vectorul de drumuri si numarul de drumuri trebuie sa existe.");
		}

		if (this->distanteParcurse != nullptr) {
			delete[] this->distanteParcurse;
			this->distanteParcurse = nullptr; // iar nu stiu daca are rost sa il facem null tinand cont ca il vom aloca fix dupa asta?
			this->nrDrumuri = 0; 
		}

		if (distante != nullptr && numarDrumuri > 0) {
			this->distanteParcurse = new float[numarDrumuri];
			for (int i = 0; i < numarDrumuri; i++) {
				this->distanteParcurse[i] = distante[i];
			}
			this->nrDrumuri = numarDrumuri;
		}
	}

	char* getTaraDeProductie()
	{
		if (taraDeProductie != nullptr) {
			char* copie = new char[strlen(taraDeProductie) + 1];
			strcpy_s(copie, strlen(taraDeProductie) + 1, taraDeProductie);
			return copie;
		}
		return nullptr;
	}

	void setTaraDeProductie(const char* tara)
	{
		if (taraDeProductie != nullptr) {
			delete[] taraDeProductie;
			taraDeProductie = nullptr;
		}
		if (tara != nullptr) {
			taraDeProductie = new char[strlen(tara) + 1];
			strcpy_s(taraDeProductie,strlen(tara)+1, tara);
		}
	}

	char* AdresaInceputTaraDeProductie()
	{
		return taraDeProductie;
	}
};



int main() 
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
	//Test here the functions that you need and use the debugger to identify the problems
}