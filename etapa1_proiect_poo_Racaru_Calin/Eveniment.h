#pragma once

#include <iostream>
#include <string>

using namespace std;

class Eveniment
{
private:
	static string locatie_eveniment;
	char* denumire_eveniment;
	int dim_denumire;
	static string program_eveniment;
	string ora_eveniment;
	string data_eveniment;
public:
	Eveniment()
	{
		string sir = "";
		dim_denumire = sir.length() + 1;
		denumire_eveniment = new char[dim_denumire];
		strcpy_s(denumire_eveniment, dim_denumire, sir.c_str());
		ora_eveniment = "00:00";
		data_eveniment = "00/00/0000";
	
	}

	Eveniment(char* denumire_eveniment, int dim_denumire, string ora_eveniment, string data_eveniment)
	{
		string s;
		string s1;
		if (dim_denumire > 0 && denumire_eveniment != NULL)
		{
			this->dim_denumire = dim_denumire;
			this->denumire_eveniment = new char[dim_denumire];
			for (int i = 0; i < dim_denumire; i++)
				this->denumire_eveniment[i] = denumire_eveniment[i];
		}
		if (ora_eveniment != "" && ora_eveniment.length() == 5)
		{
			s = ora_eveniment[2];
			if (s.compare(":") == 0)
				this->ora_eveniment = ora_eveniment;
			else
				cout << "intre ora si minut trebuie sa fie caracterul : " << endl;
		}
		else
			cout << "ora nu contine 5 caractere";
		if (data_eveniment != "" && data_eveniment.length() == 10)
		{
			s = data_eveniment[2];
			s1 = data_eveniment[5];
			if (s.compare("/") == 0 && s1.compare("/") == 0)
				this->data_eveniment = data_eveniment;
			else
				cout << "intre zi,luna si an trebuie sa fie caracterul /"<<endl;
		}
		else
			cout << "data trebuie sa contina 10 caractere"<<endl;
	}
	~Eveniment()
	{
		if (denumire_eveniment != NULL)
		{
			delete[]denumire_eveniment;
			denumire_eveniment = NULL;
		}
	}
	Eveniment(const Eveniment& cine)
	{
		this->dim_denumire = strlen(cine.denumire_eveniment) + 1;
		this->denumire_eveniment = new char[strlen(cine.denumire_eveniment) + 1];
		for (int i = 0; i < dim_denumire; i++)
			this->denumire_eveniment[i] = cine.denumire_eveniment[i];
		ora_eveniment = cine.ora_eveniment;
		data_eveniment = cine.data_eveniment;
	}
	Eveniment& operator=(const Eveniment& cine)
	{
		if (this->denumire_eveniment != NULL)
		{
			delete[] this->denumire_eveniment;
			denumire_eveniment = NULL;
			this->dim_denumire = strlen(cine.denumire_eveniment) + 1;
			this->denumire_eveniment = new char[strlen(cine.denumire_eveniment) + 1];
			for (int i = 0; i < dim_denumire; i++)
				this->denumire_eveniment[i] = cine.denumire_eveniment[i];
		}
		ora_eveniment = cine.ora_eveniment;
		data_eveniment = cine.data_eveniment;
		return *this;
	}
	string extrage_locatie()
	{
		string sir = "Locatie:";

		if (denumire_eveniment != NULL && strlen(denumire_eveniment) > 0)
		{
			for (int i = 0; i < strlen(denumire_eveniment); i++)
				sir = sir + (denumire_eveniment[i]);
			sir = sir + ",";
		}
		if (locatie_eveniment != "")
		{
			sir = sir + locatie_eveniment;
			sir = sir + ",";
		}
		if (data_eveniment != "")
		{
			sir = sir + data_eveniment;
			sir = sir + ",";
		}
		if (ora_eveniment != "")
			sir = sir + ora_eveniment;

		return sir;
	}
	bool verifica_locatie_eveniment_valida()
	{
		if (locatie_eveniment != "")
			return true;
		else
			return false;
	}
	bool operator==(Eveniment ev)
	{
		if (strcmp(denumire_eveniment, ev.denumire_eveniment) == 0 && locatie_eveniment == ev.locatie_eveniment && ora_eveniment == ev.ora_eveniment)
			return true;
		else
			return false;
	}
	Eveniment operator++()
	{
		dim_denumire++;
		return *this;
	}
	Eveniment operator++(int a)
	{
		Eveniment copie = *this;
		dim_denumire++;
		return copie;
	}
	void set_data_eveniment(string sir)
	{
		string s;
		string s1;
		if (sir != "" && sir.length() == 10)
		{
			s = sir[2];
			s1 = sir[5];
			if (s.compare("/") == 0 && s1.compare("/") == 0)
				data_eveniment = sir;
			else
				cout << "intre zi,luna si an trebuie sa fie caracterul /"<<endl;
		}
		else
			cout << "data trebuie sa contina 10 caractere"<<endl;
		
	}
	string get_data_eveniment()
	{
		return data_eveniment;
	}
	int get_dim_denumire()
	{
		return dim_denumire;
	}
	void set_dim_denumire(int a)
	{
		if (a > 0)
			dim_denumire = a;
	}
	static string get_locatie_eveniment()
	{
		return locatie_eveniment;
	}
	void set_locatie_eveniment(string locatie)
	{
		if (locatie != "")
			locatie_eveniment = locatie;

	}
	static	 string get_program_eveniment()
	{
		return program_eveniment;
	}
	void set_program_eveniment(string program)
	{
		string s;
		string s1;
		string s2;
		if (program != "" && program.length() == 11)
		{
			s = program[2];
			s1 = program[5];
			s2 = program[8];
			if (s.compare(":") == 0 && s1.compare("-") == 0 && s2.compare(":") == 0)
				program_eveniment = program;
			else
				cout << "programul evenimentului a fost intodus gresit,programul trebuie sa fie de forma aa:bb-cc:dd"<<endl;
		}
		else
			cout << " programului nu are 11 caractere"<<endl;
	}
	char* get_denumire_eveniment()
	{
		if (denumire_eveniment == NULL && dim_denumire <= 0)
			return NULL;
		char* copie;
		copie = new char[dim_denumire];
		for (int i = 0; i < dim_denumire; i++)
			copie[i] = denumire_eveniment[i];
		return copie;
	}
	void set_denumire_eveniment(char* denumire)
	{
		if (denumire != NULL && strlen(denumire) > 0)
		{
			this->dim_denumire = strlen(denumire) + 1;
			if (denumire_eveniment != NULL)
			{
				delete[] denumire_eveniment;
				denumire_eveniment = NULL;
			}
			denumire_eveniment = new char[strlen(denumire) + 1];
			for (int i = 0; i < strlen(denumire) + 1; i++)
				denumire_eveniment[i] = denumire[i];
		}

	}
	string get_ora_eveniment()
	{
		return ora_eveniment;
	}
	void set_ora_eveniment(string a)
	{
		string s;
		if (a != "" && a.length() == 5)
		{
			s = a[2];
			if (s.compare(":") == 0)
				ora_eveniment =a;
			else
				cout << "intre ora si minut trebuie sa fie caracterul : "<<endl;
		}
		else
			cout << "ora nu contine 5 caractere"<<endl;
			
	}

	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
};
string Eveniment::locatie_eveniment = "-";
string Eveniment::program_eveniment = "00:00-00:00";

ostream& operator<<(ostream& out, Eveniment cine)
{
	if (cine.denumire_eveniment != NULL && cine.dim_denumire > 0)

	{
		out << "denumire eveniment:" << endl;
		for (int i = 0; i < cine.dim_denumire; i++)
			out << cine.denumire_eveniment[i];
	}
	else
		out << "denumire eveniment INVALIDA" << endl;
	out << endl << "locatie eveniment:" << endl << cine.locatie_eveniment << endl;
	out << "program eveniment" << endl << cine.program_eveniment << endl;

	out << "ora eveniment:" << cine.ora_eveniment;
	out <<"data eveniment:" <<cine.data_eveniment;
	return out;
}
istream& operator>>(istream& in, Eveniment& cine)
{
	
	string sir;

	cout << "introdu denumire eveniment:" << endl;
	in >> sir;
	if (cine.denumire_eveniment != NULL)
	{
		delete[] cine.denumire_eveniment;
		cine.denumire_eveniment = NULL;
	}
	int dim = sir.length() + 1;
	cine.denumire_eveniment = new char[dim];
	strcpy_s(cine.denumire_eveniment, dim, sir.c_str());
	cout << "introdu locatie eveniment" << endl;
	in >> cine.locatie_eveniment;

	cout << "introdu program eveniment:" << endl;
	in >> sir;
	string s;
	string s1;
	string s2;
	if (sir!= "" && sir.length() == 11)
	{
		s = sir[2];
		s1 = sir[5];
		s2 = sir[8];
		if (s.compare(":") == 0 && s1.compare("-") == 0 && s2.compare(":") == 0)
			cine.program_eveniment = sir;
		else
			cout << "programul evenimentului a fost intodus gresit,programul trebuie sa fie de forma aa:bb-cc:dd"<<endl;
	}
	else
		cout << " programul nu are 11 caractere"<<endl;

	cout << "introdu ora eveniment:" << endl;
	in >> sir;
	if (sir!= "" && sir.length() == 5)
	{
		s = sir[2];
		if (s.compare(":") == 0)
			cine.ora_eveniment = sir;
		else
			cout << "intre ora si minut trebuie sa fie caracterul : "<<endl;
	}
	else
		cout << "ora nu contine 5 caractere"<<endl;
	in >> sir;
	if (sir != "" && sir.length() == 10)
	{
		s = sir[2];
		s1 = sir[5];
		if (s.compare("/") == 0 && s1.compare("/") == 0)
			cine.data_eveniment = sir;
		else
			cout << "intre zi,luna si an trebuie sa fie caracterul /" << endl;
	}
	else
		cout << "data trebuie sa contina 10 caractere" << endl;

	return in;
}
