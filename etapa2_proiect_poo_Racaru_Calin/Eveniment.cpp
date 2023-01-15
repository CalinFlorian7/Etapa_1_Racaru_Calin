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

		if (dim_denumire > 0 && denumire_eveniment != NULL)
		{
			this->dim_denumire = dim_denumire;
			this->denumire_eveniment = new char[dim_denumire];
			for (int i = 0; i < dim_denumire; i++)
				this->denumire_eveniment[i] = denumire_eveniment[i];
		}
		if (ora_eveniment != "")
			this->ora_eveniment = ora_eveniment;
		if (data_eveniment != "")
			this->data_eveniment = data_eveniment;
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
		if (sir != "")
			data_eveniment = sir;
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
		if (program != "")
			program_eveniment = program;
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
		if (a != "")
			ora_eveniment = a;
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

	//getline(in, cine.locatie_eveniment);
	cout << "introdu program eveniment:" << endl;
	in >> cine.program_eveniment;
	//getline(in, cine.program_eveniment);
	cout << "introdu ora eveniment:" << endl;
	in >> cine.ora_eveniment;
	return in;
}