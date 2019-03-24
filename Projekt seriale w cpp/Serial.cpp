//    © 2018 Damian Tabaczynski All Rights Reserved

#include "pch.h"
#include "Serial.h"
#include<iostream>

using namespace std;

Serial::Serial() {}

Serial::~Serial()
{
}


unsigned int Serial::get_Number_Episodes() {
	return Number_Episodes;
}

void Serial::set_Number_Episodes(unsigned int &number)
{
	Number_Episodes = number;
}

unsigned int Serial::get_Watched() {
	return Watched;
}

void Serial::set_Watched(unsigned int &variable)
{
	Watched = variable;
}

void Serial::show() {
	cout << "----------------------------------------------------------------------------" << endl;
	Media::show();
	cout << "Liczba odcinkow serialu : " << Number_Episodes << endl;;
	cout << "Liczba juz obejrzanych odcinkow : " << Watched << endl;
	cout << endl << "Rodzaj produkcji : Serial" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}

void Serial::load(std::istream& in) {
	Media::load(in);
	if (typeid(in).hash_code() == typeid(std::cin).hash_code()) {

		bool correct = false;
		string word;
		while (!correct)
		{
			cout << "Podaj ilosc odcinkow : ";
			getline(in, word);
			correct = true;
			try
			{
				if (stoi(word) < 0) {
					cout << "----------------------------------------------------------------------------" << endl;
					cout << endl << "Prosze wpisac poprawna ilosc odcinkow (liczba naturalna) !!!" << endl << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					correct = false;
				}
				else
				{
					Number_Episodes = stoi(word);
				}
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna ilosc odcinkow (liczba naturalna) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}

		correct = false;
		while (!correct)
		{
			cout << "Podaj ilosc juz obejrzanych odcinkow: ";
			getline(in, word);
			correct = true;
			try
			{
				if (stoi(word) > Number_Episodes || stoi(word) < 0)
				{
					cout << "----------------------------------------------------------------------------" << endl;
					cout << endl << "Prosze wpisac liczbe nie wieksza niz ilosc odcinkow serialu (naturalna) !!!" << endl << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					correct = false;
				}
				else
				{
					Watched = stoi(word);
				}
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna ilosc odcinkow juz obejrzanych (liczba naturalna) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}
	}
	else
	{
		in >> Number_Episodes;
		in >> Watched;
	}
}


void Serial::edit() {
	Media::edit();
	string word;



	bool correct = false;
	while (!correct)
	{
		cout << "Zmien ilosc odcinkow : ";
		getline(cin, word);
		correct = true;
		if (word != "") {
			try
			{
				if (stoi(word) < 0) {
					cout << "----------------------------------------------------------------------------" << endl;
					cout << endl << "Prosze wpisac poprawna ilosc odcinkow (liczba naturalna) !!!" << endl << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					correct = false;
				}
				else
				{
					Number_Episodes = stoi(word);
				}
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna ilosc odcinkow (liczba naturalna) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}
	}

	correct = false;
	while (!correct)
	{

		cout << "Zmien ilosc juz obejrzanych odcinkow: ";
		getline(cin, word);
		correct = true;
		if (word != "") {
			try
			{
				if (stoi(word) > Number_Episodes || stoi(word) < 0)
				{
					cout << "----------------------------------------------------------------------------" << endl;
					cout << endl << "Prosze wpisac liczbe nie wieksza niz ilosc odcinkow serialu (naturalna) !!!" << endl << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					correct = false;
				}
				else
				{
					Watched = stoi(word);
				}
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna ilosc odcinkow juz obejrzanych (liczba naturalna) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}
	}
}


void Serial::save(std::ostream& out) {
	out << "Serial" << "\n";
	Media::save(out);
	out << Number_Episodes << "\n";
	out << Watched << "\n";
}