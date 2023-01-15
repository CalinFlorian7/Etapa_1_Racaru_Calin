#pragma once

#include <iostream>
#include <string>

using namespace std;

class DetaliiEveniment
{

private:
	const int nr_eveniment;
	int nr_locuri_maxim;
	int randuri;
	int* zona;
	int nr_zone;
	int** matrice;
public:

	DetaliiEveniment() :nr_eveniment(1)
	{
		nr_locuri_maxim = 1;
		randuri = 1;
		zona = NULL;
		nr_zone = 1;
		matrice = NULL;

	}
	DetaliiEveniment(int nr_sala, int nr_zone, int* zona, int randuri, int nr_locuri_maxim, int** matrice) :nr_eveniment(nr_sala)
	{

		int s = 0;
		int ok = 1;
		int nr = 0;
		if (zona != NULL && nr_zone > 0)
		{
			for (int i = 0; i < nr_zone; i++)
			{
				if (zona[i] % randuri == 0)
					nr++;
				s = s + zona[i];
				if (zona[i] < 0)
					ok = 0;
			}

		}
		if (s == nr_locuri_maxim && ok == 1 && nr == nr_zone)
		{
			if (nr_zone > 0 && zona != NULL)
			{
				int s = 0;
				this->nr_zone = nr_zone;
				this->zona = new int[nr_zone];
				for (int i = 0; i < nr_zone; i++)
					this->zona[i] = zona[i];
				this->nr_locuri_maxim = nr_locuri_maxim;
				if (nr_locuri_maxim % randuri == 0)
					this->randuri = randuri;

			}
		}
		else
			cout << "nr de locuri pe zone a fost introdus incorect!";

		if (matrice != NULL && nr_zone > 0 && zona != NULL)
		{
			this->matrice = new int* [nr_zone];
			for (int i = 0; i < nr_zone; i++)
				this->matrice[i] = new int[zona[i]];

			for (int i = 0; i < nr_zone; i++)
				for (int j = 0; j < zona[i]; j++)
					this->matrice[i][j] = matrice[i][j];
		}

	}
	DetaliiEveniment(const DetaliiEveniment& sala) :nr_eveniment(sala.nr_eveniment)
	{
		this->nr_zone = sala.nr_zone;
		this->randuri = sala.randuri;
		if (sala.nr_zone > 0 && sala.zona != NULL)
		{
			this->zona = new int[nr_zone];
			for (int i = 0; i < nr_zone; i++)
				zona[i] = sala.zona[i];
		}
		this->nr_locuri_maxim = sala.nr_locuri_maxim;
		if (sala.nr_zone > 0 && sala.zona != NULL)
		{
			/*for (int i = 0; i < nr_zone; i++)
				delete[] matrice[i];
			delete[]matrice;
			matrice = NULL;*/
			this->matrice = new int* [nr_zone];
			for (int i = 0; i < nr_zone; i++)
				this->matrice[i] = new int[zona[i]];

			for (int i = 0; i < nr_zone; i++)
				for (int j = 0; j < zona[i]; j++)
					this->matrice[i][j] = sala.matrice[i][j];
		}
	}
	~DetaliiEveniment()
	{
		/*if (zona != NULL)
			delete[] zona;
		zona = NULL;
		if (matrice != NULL)
		{
			for (int i = 0; i < nr_zone; i++)
				delete[] matrice[i];
			delete[] matrice;
			matrice = NULL;

		}*/
	}
	DetaliiEveniment& operator=(const DetaliiEveniment& sala)
	{
		if (zona != NULL)
		{
			delete[] zona;
			zona = NULL;
		}
		if (sala.nr_zone > 0 && sala.zona != NULL)
		{
			nr_zone = sala.nr_zone;
			zona = new int[nr_zone];
			for (int i = 0; i < nr_zone; i++)
				zona[i] = sala.zona[i];
			randuri = sala.randuri;
			this->nr_locuri_maxim = sala.nr_locuri_maxim;
			if (nr_zone > 0 && zona != NULL && zona != NULL)
			{
				for (int i = 0; i < nr_zone; i++)
					delete[] matrice[i];
				delete[]matrice;
				matrice = NULL;
				this->matrice = new int* [nr_zone];
				for (int i = 0; i < nr_zone; i++)
					this->matrice[i] = new int[zona[i]];

				for (int i = 0; i < nr_zone; i++)
					for (int j = 0; j < zona[i]; j++)
						this->matrice[i][j] = sala.matrice[i][j];
			}
			return *this;

		}
	}

	int operator[](int index)
	{
		if (index >= 0 && index < nr_zone)
			return zona[index];
	}
	DetaliiEveniment& operator+(int surplus_locuri)
	{
		if (surplus_locuri % randuri == 0)
			nr_locuri_maxim = nr_locuri_maxim + surplus_locuri;
		return *this;
	}
	bool verifica_locuri_libere()
	{
		int nr;
		nr = 0;
		if (matrice != NULL && zona != NULL && nr_zone > 0)
			for (int i = 0; i < nr_zone; i++)
				for (int j = 0; j < zona[i]; j++)
					if (matrice[i][j] > 0)
						nr++;
		if (nr > 0)
			return true;
		else
			return false;

	}
	bool verifica_locuri_pe_zona(int zona_de_verificat)
	{
		int nr;
		int ok;
		ok = 0;
		nr = 0;
		if (zona_de_verificat < 0)
			return false;
		if (nr_zone > 0)
			for (int i = 0; i < nr_zone; i++)
				if (i == zona_de_verificat)
					ok = 1;
		if (ok == 1 && matrice != NULL && zona != NULL && nr_zone > 0)
			for (int j = 0; j < zona[zona_de_verificat]; j++)
			{
				if (matrice[zona_de_verificat][j] > 0)
					nr++;

			}
		if (nr > 0)
			return true;
		else
			return false;

	}
	int extrage_zona_ceruta(int a)
	{
		if (a >= 0 && a < nr_zone)
			return a;
	}
	int get_element_din_matrice(int a, int b)
	{

		if (a >= 0 && a <= nr_zone && b <= zona[a] && matrice != NULL && zona != NULL)

			return matrice[a][b];
	}
	int get_numar_locuri_maxim()
	{
		return nr_locuri_maxim;
	}
	void set_numar_locuri_maxim(int nr_locuri_maxim)
	{
		if (nr_locuri_maxim >= 0)
			this->nr_locuri_maxim = nr_locuri_maxim;
	}
	int get_nr_eveniment()
	{
		return nr_eveniment;
	}

	int get_randuri()
	{
		return randuri;
	}
	void set_randuri(int randuri)
	{
		int s = 0;
		int ok = 1;
		int nr = 0;
		if (zona != NULL && nr_zone > 0)
		{
			for (int i = 0; i < nr_zone; i++)
			{
				if (zona[i] % randuri == 0)
					nr++;
				s = s + zona[i];
				if (zona[i] < 0)
					ok = 0;
			}

		}
		if (s == nr_locuri_maxim && ok == 1 && nr == nr_zone)
			this->randuri = randuri;
	}
	int extrage_nr_locuri_pe_zona(int a)
	{

		if (nr_zone > 0 && zona != NULL)
			for (int i = 0; i < nr_zone; i++)
				if (a == i)
					return zona[a];
	}
	void seteaza_loc_ocupat(int a, int b)
	{
		if (a >= 0 && a <= nr_zone && b >= 0 && b <= zona[a] && matrice != NULL && zona != NULL)
			matrice[a][b] = -matrice[a][b];
	}
	int get_nr_zone()
	{
		return nr_zone;
	}
	void set_nr_zone(int nr_zone)
	{
		if (nr_zone > 0)
			this->nr_zone = nr_zone;
	}
	int* get_zona()
	{
		if (zona == NULL || nr_zone <= 0)
			return NULL;
		int* copie;
		copie = new int[nr_zone];
		for (int i = 0; i < nr_zone; i++)
			copie[i] = zona[i];
		return copie;
	}
	void set_zona(int* zone_de_setat, int nr_zone_de_setat, int nr_locuri_maxim_nou)
	{
		int s = 0;
		int ok = 1;
		if (zone_de_setat != NULL && nr_zone_de_setat > 0)
		{
			for (int i = 0; i < nr_zone_de_setat; i++)
			{
				s = s + zone_de_setat[i];
				if (zone_de_setat[i] < 0)
					ok = 0;
			}

		}
		if (s == nr_locuri_maxim_nou && ok == 1)
		{
			nr_locuri_maxim = nr_locuri_maxim_nou;
			if (zone_de_setat != NULL && nr_zone_de_setat > 0)
			{
				delete[] zona;
				zona = NULL;
				nr_zone = nr_zone_de_setat;
				for (int i = 0; i < nr_zone_de_setat; i++)
					zona[i] = zone_de_setat[i];
			}
		}
	}
	int** get_matrice()
	{
		if (matrice == NULL || nr_zone <= 0)
			return NULL;
		int** copie;

		copie = new int* [nr_zone];
		for (int i = 0; i < nr_zone; i++)
			copie[i] = new int[zona[i]];

		for (int i = 0; i < nr_zone; i++)
			for (int j = 0; j < zona[i]; j++)
				copie[i][j] = matrice[i][j];

		return copie;
	}
	void set_matrice(int** matrice, int* zona, int nr_zone)
	{
		int s = 0;
		int ok = 1;
		int nr = 0;
		if (zona != NULL && nr_zone > 0)
		{
			for (int i = 0; i < nr_zone; i++)
			{
				if (zona[i] % randuri == 0)
					nr++;
				s = s + zona[i];
				if (zona[i] < 0)
					ok = 0;
			}

		}
		if (s == nr_locuri_maxim && ok == 1 && nr == nr_zone)
			if (nr_zone > 0 && zona != NULL)
			{
				int s = 0;
				this->nr_zone = nr_zone;
				this->zona = new int[nr_zone];
				for (int i = 0; i < nr_zone; i++)
					this->zona[i] = zona[i];
				this->nr_locuri_maxim = nr_locuri_maxim;
				if (nr_locuri_maxim % randuri == 0)
					this->randuri = randuri;

			}

		if (matrice != NULL && nr_zone > 0 && zona != NULL)
		{
			this->matrice = new int* [nr_zone];
			for (int i = 0; i < nr_zone; i++)
				this->matrice[i] = new int[zona[i]];

			for (int i = 0; i < nr_zone; i++)
				for (int j = 0; j < zona[i]; j++)
					if (matrice[i][j] > 0)
						this->matrice[i][j] = matrice[i][j];


		}

	}
	//friend Bilete;
	friend ostream& operator<<(ostream& out, DetaliiEveniment);
	friend istream& operator>>(istream& out, DetaliiEveniment&);
};

ostream& operator<<(ostream& out, DetaliiEveniment d)
{

	out << "numar eveniment:" << d.nr_eveniment << endl;
	out << "numar maxim de locuri:" << d.nr_locuri_maxim << endl;
	out << "randuri:" << d.randuri << endl;
	out << "numar de zone:" << d.nr_zone << endl;
	out << "zone:" << endl;
	if (d.nr_zone >= 0 && d.zona != NULL)
		for (int i = 0; i < d.nr_zone; i++)
			out << d.zona[i] << " ";
	out << endl;
	out << "locuri totatle:" << endl;
	if (d.zona != NULL && d.matrice != NULL && d.nr_zone >= 0)
		for (int i = 0; i < d.nr_zone; i++)
		{
			for (int j = 0; j < d.zona[i]; j++)
				out << d.matrice[i][j] << " ";
		}

	return out;

}
istream& operator>>(istream& in, DetaliiEveniment& d)
{
	cout << "introduceti numar maxim de locuri:" << endl;
	in >> d.nr_locuri_maxim;
	cout << "introduceti numar de randuri:" << endl;
	in >> d.randuri;
	cout << "introduceti numarul de zone:" << endl;
	in >> d.nr_zone;
	cout << "introduceti numar de locuri pe zone:" << endl;
	if (d.nr_zone >= 0)
	{
		d.zona = new int[d.nr_zone];
		for (int i = 0; i < d.nr_zone; i++)
		{
			cout << "zona " << i << ":";
			in >> d.zona[i];
		}
	}
	cout << "introduceti numere locuri(numere>0):" << endl;
	if (d.zona != NULL && d.nr_zone > 0)
	{
		d.matrice = new int* [d.nr_zone];
		for (int i = 0; i < d.nr_zone; i++)
			d.matrice[i] = new int[d.zona[i]];

		for (int i = 0; i < d.nr_zone; i++)
			for (int j = 0; j < d.zona[i]; j++)
				in >> d.matrice[i][j];
	}
	int s = 0;
	int ok = 1;
	int nr = 0;
	if (d.zona != NULL && d.nr_zone > 0)
	{
		for (int i = 0; i < d.nr_zone; i++)
		{
			if (d.zona[i] % d.randuri == 0)
				nr++;
			s = s + d.zona[i];
			if (d.zona[i] < 0)
				ok = 0;
		}

	}
	if (s != d.nr_locuri_maxim || ok != 1 || nr != d.nr_zone)
	{
		cout << "numarul de randuri pe zone a fost introdus gresit";
		d.randuri = 0;
	}

	return in;

}
