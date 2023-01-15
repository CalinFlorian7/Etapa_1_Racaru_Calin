#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Bilete.h"
#include "Eveniment.h"
#include "DetaliiEveniment.h"
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
using namespace std;



class EvenimentCaritabil: public Eveniment
{private:
	float suma_totala=0;
public:
	float suma_castigata(Bilete &b,float a)
	{
		
		a=a+b.get_pret_redus();
		return a;
		
	}
	float get_suma_totala()
	{
		return suma_totala;
	}
	void set_suma_totala(float c)
	{
		suma_totala = c;
	}
};

int main()
{
	
	//Bilete a, b;
	//a.set_pret_redus(23);
	//b.set_pret_redus(22);
	//
	//float s = 0;
	//EvenimentCaritabil evc;
	//s=evc.suma_castigata(a, s);
	//s=evc.suma_castigata(b, s);
	//evc.set_suma_totala(s);
	//cout << evc.get_suma_totala()<<endl;







	Eveniment* eveniment;
	eveniment = NULL;
	int nr_de_evenimente;
	DetaliiEveniment* detev;
	detev = NULL;
	cout << "introduceti nr de evenimente:" << endl;
	cin >> nr_de_evenimente;
	if (nr_de_evenimente > 0)
	{
		eveniment = new Eveniment[nr_de_evenimente];
		for (int i = 0; i < nr_de_evenimente; i++)
		{
			cout << "introdu eveniment:" << i + 1 << endl;
			cin >> eveniment[i];
		}
	}
	else
		cout << "nr de evenimente trebuie sa fie >0!!" << endl;
	if (nr_de_evenimente > 0)
	{
		detev = new DetaliiEveniment[nr_de_evenimente];
		for (int i = 0; i < nr_de_evenimente; i++)
		{
			cout << "introdu detalii eveniment:" << i + 1 << endl;
			cin >> detev[i];
		}
	}
	else
		cout << "nr de evenimente trebuie sa fie >0!!" << endl;



	string val;
	cout << "Daca doriti navigarea prin meniu introduceti de la taste \"da\" altfel introduceti \"nu\":" << endl;
	cin >> val;

	if (val == "da" && nr_de_evenimente > 0)
	{
		int nr_bilete;
		cout << "Introdu numarul de bilete dorit" << endl;
		cin >> nr_bilete;
		if (nr_bilete > 0)
		{

			int ord_bilet;
			ord_bilet = 1;
			cout << "Evenimentele disponibile sunt:" << endl;
			for (int i = 0; i < nr_de_evenimente; i++)
			{
				char* d = eveniment[i].get_denumire_eveniment();
				for (int j = 0; j < eveniment[i].get_dim_denumire(); j++)
					cout << d[j];
				cout << "," << eveniment[i].get_data_eveniment() << "," << eveniment[i].get_ora_eveniment() << endl;
			}
			while (ord_bilet <= nr_bilete)
			{
				string a;
				string b;
				string c;
				int poz = -1;
				int ok = 0;
				cout << "Introduceti denumirea evenimentului:" << endl;
				cin >> a;
				cout << "introduceti data evenimentului" << endl;
				cin >> c;
				cout << "introduceti ora evenimentului" << endl;
				cin >> b;
				for (int i = 0; i < nr_de_evenimente; i++)
				{
					if (eveniment[i].get_denumire_eveniment() == a && eveniment[i].get_ora_eveniment() == b && eveniment[i].get_data_eveniment() == c)
					{
						ok = 1;
						poz = i;
					}
				}

				if (ok == 1)
				{
					if (detev[poz].verifica_locuri_libere() == true)
					{
						Bilete bilet(ord_bilet);

						int verif = 0;
						cout << "daca vreti sa luati un bilet cu loc intr-o zona specifica tastati \"da\" altfel tastati \"nu\":" << endl;
						cin >> a;
						if (a == "da")
						{

							int zona_dorita;

							cout << "introduceti zona in care doriti loc:" << endl;
							cin >> zona_dorita;
							if (detev[poz].verifica_locuri_pe_zona(zona_dorita) == true)
							{
								verif = 1;
								bilet.extrage_loc_bilet_pe_zona(detev[poz], zona_dorita);

								bilet.afla_data_si_locatie(eveniment[poz]);
								cout << "daca doriti pret redus tastati \"redus\" altfel tastati \"intreg\" " << endl;
								cin >> b;
								if (b == "redus")
								{
									bilet.set_comision(0.5);
									bilet.set_pret_intreg(40.5);
									bilet.set_pret_redus(bilet.get_comision() * bilet.get_pret_intreg());
									bilet.set_tip_bilet(b);
									string sirr;
									time_t timetoday;
									time(&timetoday);
									sirr = asctime(localtime(&timetoday));
									bilet.set_data_emitere(sirr);
									cout << "biletul  emis este:" << endl;
									cout << bilet<<endl;
									//data emitere
								}
								if (b == "intreg")
								{
									bilet.set_comision(1);
									bilet.set_pret_intreg(40.5);
									bilet.set_pret_redus(bilet.get_comision() * bilet.get_pret_intreg());
									bilet.set_tip_bilet(b);
									string sirr;
									time_t timetoday;
									time(&timetoday);
									sirr = asctime(localtime(&timetoday));
									bilet.set_data_emitere(sirr);
									cout << "biletul  emis este:" << endl;
									cout << bilet<<endl;
									
									//data emitere
								}

							}
							else
								cout << "nu sunt locuri disponibile in zona " << detev[poz].get_zona() << endl;
						}
						//else
						if (a == "nu" || verif == 1)
						{
							/*bilet.extrage_loc_bilet(detev[poz]);
							bilet.afla_data_si_locatie(eveniment[poz]);
							bilet.set_comision(1);
							bilet.set_pret_intreg(40.5);
							bilet.set_pret_redus(bilet.get_comision() * bilet.get_pret_intreg());
							bilet.set_tip_bilet(b);
							string sirr;
							time_t timetoday;
							time(&timetoday);
							sirr = asctime(localtime(&timetoday));
							bilet.set_data_emitere(sirr);
							cout << "biletul  emis este:" << endl;
							cout << bilet << endl;*/
							cout << "daca doriti pret redus tastati \"redus\" altfel tastati \"intreg\" " << endl;
							cin >> b;
							if (b == "redus")
							{
								bilet.set_comision(0.5);
								bilet.set_pret_intreg(40.5);
								bilet.set_pret_redus(bilet.get_comision() * bilet.get_pret_intreg());
								bilet.set_tip_bilet(b);
								string sirr;
								time_t timetoday;
								time(&timetoday);
								sirr = asctime(localtime(&timetoday));
								bilet.set_data_emitere(sirr);
								cout << "biletul  emis este:" << endl;
								cout << bilet<<endl;
								
								//data emitere
							}
							if (b == "intreg")
							{
								bilet.set_comision(1);
								bilet.set_pret_intreg(40.5);
								bilet.set_pret_redus(bilet.get_comision() * bilet.get_pret_intreg());
								bilet.set_tip_bilet(b);
								string sirr;
								time_t timetoday;
								time(&timetoday);
								sirr = asctime(localtime(&timetoday));
								bilet.set_data_emitere(sirr);
								cout << "biletul  emis este:" << endl;
								cout << bilet <<endl;
								//data emitere
							}

							//data emitere bilet
						}

					}
					else
						cout << "Nu mai sunt locuri libere pentru acest eveniment" << endl;
				}
				else
					cout << "evenimnetul dorit a fost introdus gresit" << endl;
				ord_bilet++;
			}

		}
		else
			cout << "numarul de bilete trebuie sa fie mai mare ca 0 sau nu sunt disponibile evenimente" << endl;

	}
	else
		if (val == "nu" && nr_de_evenimente > 0)
		{
			int id = 1;
		
			ifstream f;
			string den_fisier;

			cout << "introduceti denumirea fisierului din care se vor prelua date" << endl;
			cin >> den_fisier;
			
			f.open(den_fisier, ios::in);
			int nr_bilete;
			string denumire;
			string data;
			string ora;
			string tip;
			int zona_dorita;
			int ord_bilet;
			if (f.fail())
				cout << "fisierul introdus nu exista"<<endl;
			else

			
				f >> nr_bilete;
				getline(f, denumire);
				getline(f, denumire);
				getline(f, data);
				getline(f, ora);
				getline(f, tip);
				f >> zona_dorita;

				if (nr_bilete > 0)
				{

					int ord_bilet;
					ord_bilet = 1;

					while (ord_bilet <= nr_bilete)
					{
						string a;
						a = denumire;
						string b;
						b = ora;
						string c;
						c = data;
						int poz = -1;
						int ok = 0;

						for (int i = 0; i < nr_de_evenimente; i++)
						{
							if (eveniment[i].get_denumire_eveniment() == a && eveniment[i].get_ora_eveniment() == b && eveniment[i].get_data_eveniment() == c)
							{
								ok = 1;
								poz = i;
							}
						}

						if (ok == 1)
						{
							if (detev[poz].verifica_locuri_libere() == true)
							{
								Bilete bilet(id);

								int verif = 0;



								if (detev[poz].verifica_locuri_pe_zona(zona_dorita) == true)
								{
									verif = 1;
									bilet.extrage_loc_bilet_pe_zona(detev[poz], zona_dorita);

									bilet.afla_data_si_locatie(eveniment[poz]);

									if (tip == "redus")
									{
										bilet.set_comision(0.5);
										bilet.set_pret_intreg(40.5);
										bilet.set_pret_redus(bilet.get_comision() * bilet.get_pret_intreg());
										bilet.set_tip_bilet(tip);
										string sirr;
										time_t timetoday;
										time(&timetoday);
										sirr = asctime(localtime(&timetoday));
										bilet.set_data_emitere(sirr);
										cout << "biletul  emis este:" << endl;
										cout << bilet<<endl;
										
										id++;
										//data emitere
									}
									if (tip == "intreg")
									{
										bilet.set_comision(1);
										bilet.set_pret_intreg(40.5);
										bilet.set_pret_redus(bilet.get_comision() * bilet.get_pret_intreg());
										bilet.set_tip_bilet(tip);
										string sirr;
										time_t timetoday;
										time(&timetoday);
										sirr = asctime(localtime(&timetoday));
										bilet.set_data_emitere(sirr);
										cout << "biletul  emis este:";
										
										cout << bilet << endl;
										
										//data emitere
										id++;
									}

								}
								else
									cout << "nu sunt locuri disponibile in zona " << detev[poz].get_zona() << endl;

								

							}
							else
								cout << "Nu mai sunt locuri libere pentru acest eveniment" << endl;
						}
						else
							cout << "evenimnetul dorit a fost introdus gresit" << endl;
						ord_bilet++;
					}

				}
				else
					cout << "numarul de bilete trebuie sa fie mai mare ca 0 sau nu sunt disponibile evenimente" << endl;
				
					f.close();

		}







		else
			cout << "nu sunt disponibile evenimente!" << endl;

	



}