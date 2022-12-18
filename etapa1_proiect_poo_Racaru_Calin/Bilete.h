#pragma once
#include <iostream>
#include <string>
#include "Eveniment.h"
#include "DetaliiEveniment.h"
using namespace std;

class Bilete
{
private:
	const int id_bilet;
	string data_emitere;
	string tip_bilet;
	int rand;
	int loc_bilet;
	float pret_intreg;
	float comision;
	float pret_redus;
	int zona_bilet;
	string data_si_locatie;

public:


	Bilete() :id_bilet(1)
	{
		data_emitere = "00/00/000000:00";
		tip_bilet = "intreg";
		rand = 0;
		loc_bilet = 0;
		pret_intreg = 40.3;
		comision = 1;
		pret_redus = pret_intreg * comision;
		data_si_locatie = "-";
		zona_bilet = 0;

	}
	Bilete(string data_emitere, string tip_bilet, int rand, int loc_bilet, float pret_intreg, float comision, string data_si_locatie, int zona_bilet) :id_bilet(id_bilet)
	{
		string s;
		string s1;
		string s2;
		if (data_emitere != "" && data_emitere.length() == 15)
		{
			s = data_emitere[2];
			s1 = data_emitere[5];
			s2 = data_emitere[12];
			if (s.compare("/") == 0 && s1.compare("/") == 0 && s2.compare(":") == 0)
				this->data_emitere = data_emitere;
			else
				cout << "data de emitere a biletului trebuie sa fie de forma: aa/bb/ccccdd:ee"<<endl;


		}
		else
			cout << "data de emitere a biletului nu are 15 caractere"<<endl;
		if (tip_bilet != "")
			this->tip_bilet = tip_bilet;
		if (rand >= 1)
			this->rand = rand;
		if (loc_bilet >= 0)
			this->loc_bilet = loc_bilet;
		if (pret_intreg >= 0)
			this->pret_intreg = pret_intreg;
		if (comision >= 0 && comision <= 1)
		{
			this->comision = comision;
			pret_redus = pret_intreg * comision;
		}
		if (data_si_locatie != "")
			this->data_si_locatie = data_si_locatie;
		if (zona_bilet >= 0)
			this->zona_bilet = zona_bilet;
	}
	Bilete(const Bilete& bilet) :id_bilet(bilet.id_bilet)
	{
		data_emitere = bilet.data_emitere;
		tip_bilet = bilet.tip_bilet;

		rand = bilet.rand;
		loc_bilet = bilet.loc_bilet;
		pret_intreg = bilet.pret_intreg;
		if (bilet.comision >= 0 && bilet.comision <= 1)
			comision = bilet.comision;
		pret_redus = bilet.pret_redus * bilet.comision;
		zona_bilet = bilet.zona_bilet;
	}
	Bilete& operator=(const Bilete& bilet)
	{
		data_emitere = bilet.data_emitere;
		tip_bilet = bilet.tip_bilet;
		rand = bilet.rand;
		loc_bilet = bilet.loc_bilet;
		pret_intreg = bilet.pret_intreg;
		comision = bilet.comision;
		pret_redus = bilet.pret_redus;
		zona_bilet = bilet.zona_bilet;
		return *this;
	}
	void extrage_loc_bilet(DetaliiEveniment& d)
	{
		if (d.verifica_locuri_libere() == true)
		{
			int ok = 0;
			int i = 0;
			int j = 0;
			int nr;
			while (i < d.get_nr_zone() && ok == 0)
			{
				nr = 0;
				while (j < d.extrage_nr_locuri_pe_zona(i) && ok == 0)
				{
					nr++;
					if (d.get_element_din_matrice(i, j) > 0)
					{
						this->loc_bilet = d.get_element_din_matrice(i, j);

						if (nr % d.get_randuri() != 0)
							this->rand = nr / d.get_randuri() + 1;
						else
							this->rand = nr / d.get_randuri();
						ok = 1;
						d.seteaza_loc_ocupat(i, j);

						this->zona_bilet = i;
					}


					j++;
				}
				j = 0;
				i++;
			}
		}
		else cout << "nu sunt locuri libere"<<endl;
	}
	void extrage_loc_bilet_pe_zona(DetaliiEveniment& d, int zona_dorita)
	{
		int j;
		int ok;
		int nr = 0;
		ok = 0;
		j = 0;
		if (zona_dorita >= 0 && zona_dorita < d.get_nr_zone())
		{
			if (d.verifica_locuri_pe_zona(zona_dorita) == true)
			{
				while (j < d.extrage_nr_locuri_pe_zona(zona_dorita) && ok == 0)
				{
					nr++;
					if (d.get_element_din_matrice(zona_dorita, j) > 0)
					{
						this->loc_bilet = d.get_element_din_matrice(zona_dorita, j);
						if (nr % d.get_randuri() != 0)
							this->rand = nr / d.get_randuri() + 1;
						else
							this->rand = nr / d.get_randuri();
						ok = 1;
						d.seteaza_loc_ocupat(zona_dorita, j);

						this->zona_bilet = zona_dorita;
					}


					j++;
				}

			}
			else
				cout << "Nu sunt locuri libere in zona ceruta"<<endl;
		}
	}
	void afla_data_si_locatie(Eveniment a)
	{
		string sir;
		sir = a.extrage_locatie();
		if (sir != "")
			this->data_si_locatie = sir;

	}
	bool operator!()
	{
		if (loc_bilet != 0)
			return true;
		else
			return false;
	}
	operator int()
	{
		return pret_redus;
	}
	int get_zona_bilet()
	{
		return zona_bilet;
	}
	void set_zona_bilet(int zona_bilet)
	{
		if (zona_bilet >= 0)
			this->zona_bilet = zona_bilet;
	}
	string get_data_si_locatie()
	{
		return data_si_locatie;
	}
	void set_data_si_locatie(string s)
	{
		if (s != "")
			data_si_locatie = s;
	}
	int get_id_bilet()
	{
		return id_bilet;
	}
	string get_data_emitere()
	{
		return data_emitere;
	}
	void set_data_emitere(string data_emitere)
	{
		if (data_emitere != "")
			this->data_emitere = data_emitere;
	}
	string get_tip_bilet()
	{
		return tip_bilet;
	}
	void set_tip_bilet(string tip_bilet)
	{
		if (tip_bilet != "")
			this->tip_bilet = tip_bilet;
	}
	int get_rand()
	{
		return rand;
	}
	void set_rand(int rand)
	{
		if (rand > 0)
			this->rand = rand;
	}
	int get_loc_bilet()
	{
		return loc_bilet;
	}
	void set_loc_bilet(int loc_bilet)
	{
		if (loc_bilet > 0)
			this->loc_bilet = loc_bilet;
	}
	float get_pret_intreg()
	{
		return pret_intreg;
	}
	void set_pret_intreg(float pret_intreg)
	{
		if (pret_intreg >= 0)
			this->pret_intreg = pret_intreg;
	}
	float get_comision()
	{
		return comision;
	}
	void set_comision(float comision)
	{
		if (comision >= 0 && comision <= 1)
			this->comision = comision;
	}
	float get_pret_redus()
	{
		return pret_redus;
	}
	void set_pret_redus(float pret_redus)
	{
		if (pret_redus <= pret_intreg && pret_redus >= 0 && pret_redus == comision * pret_intreg)
			this->pret_redus = pret_redus;
	}

	friend ostream& operator<<(ostream&, Bilete);
	friend istream& operator>>(istream&, Bilete&);
};

istream& operator>>(istream& in, Bilete& bilet)
{
	string sirdecitit;
	cout << endl;
	cout << "introdu data emitere:" << endl;
	in >>sirdecitit;
	string s;
	string s1;
	string s2;
	if (sirdecitit != "" && sirdecitit.length() == 15)
	{
		s = sirdecitit[2];
		s1 = sirdecitit[5];
		s2 = sirdecitit[12];
		if (s.compare("/") == 0 && s1.compare("/") == 0 && s2.compare(":") == 0)
			bilet.data_emitere = sirdecitit;
		else
			cout << "data de emitere a biletului trebuie sa fie de forma: aa/bb/ccccdd:ee"<<endl;
	}
	else
		cout << "data de emitere a biletului nu are 15 caractere" << endl;

	cout << "introdu tip bilet:" << endl;
	in >> bilet.tip_bilet;
	cout << "introdu rand:" << endl;
	in >> bilet.rand;
	cout << "introdu loc:" << endl;
	in >> bilet.loc_bilet;
	cout << "introdu pret intreg:" << endl;
	in >> bilet.pret_intreg;
	cout << "introdu comision pt pret:" << endl;
	in >> bilet.comision;

	cout << "introdu pret redus:" << endl;
	in >> bilet.pret_redus;
	cout << endl;
	if (bilet.pret_redus != bilet.pret_intreg * bilet.comision)
	{
		/*throw exception("pret invalid ");
		cout << "pret redus introdus incorect";*/
		bilet.pret_redus = bilet.pret_intreg * bilet.comision;
	}
	cout << "introdu zona bilet:" << endl;
	in >> bilet.zona_bilet;
	return in;

}
ostream& operator<<(ostream& out, Bilete bilet)
{
	out << endl;
	out << "id bilet:" << bilet.id_bilet << endl;
	out << "data emitere:" << bilet.data_emitere << endl;
	out << "tip bilet:" << bilet.tip_bilet << endl;
	out << "zona bilet:" << bilet.zona_bilet << endl;
	out << "rand:" << bilet.rand << endl;
	out << "loc bilet:" << bilet.loc_bilet << endl;

	out << "pret intreg:" << bilet.pret_intreg << endl;
	out << "comision:" << bilet.comision << endl;
	out << "pret redus:" << bilet.pret_redus << endl;

	return out;

}
