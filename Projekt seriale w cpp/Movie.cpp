//    © 2018 Damian Tabaczynski All Rights Reserved

#include "pch.h"
#include "Movie.h"


Movie::Movie()
{
}


Movie::~Movie()
{
}

void Movie::set_Length(unsigned int &leng) {
	Length = leng;
}

unsigned int Movie::get_Length() {
	return Length;
}


void Movie::show() {
	cout << "----------------------------------------------------------------------------" << endl;
	Media::show();
	cout << "Dlugosc filmu : " << Length << endl;
	cout << endl << "Rodzaj produkcji : Film" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}

void Movie::load(std::istream& in) {

	Media::load(in);
	if (typeid(in).hash_code() == typeid(std::cin).hash_code()) {

		bool correct = false;
		string word;
		while (!correct)
		{
			cout << "Podaj dlugosc filmu w minutach : ";
			getline(in, word);
			correct = true;
			try
			{
				if (stoi(word) < 0) {
					cout << "----------------------------------------------------------------------------" << endl;
					cout << endl << "Prosze wpisac poprawna dlugosc filmu w minutach (liczba naturalna) !!!" << endl << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					correct = false;
				}
				else
				{
					Length = stoi(word);
				}
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna dlugosc filmu w minutach (liczba naturalna) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}
	}
	else
	{
		in >> Length;
	}
}


void Movie::edit() {
	Media::edit();
	bool correct = false;
	string word;
	while (!correct)
	{
		cout << "Zmien dlugosc filmu (w minutach): ";
		getline(cin, word);
		correct = true;
		if (word != "") {
			try
			{
				if (stoi(word) < 0) {
					cout << "----------------------------------------------------------------------------" << endl;
					cout << endl << "Prosze wpisac poprawna dlugosc filmu w minutach (liczba naturalna) !!!" << endl << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					correct = false;
				}
				else
				{
					Length = stoi(word);
				}
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna dlugosc filmu w minutach (liczba naturalna) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}
	}
}

void Movie::save(std::ostream& out) {
	out << "Movie" << "\n";
	Media::save(out);
	out << Length << "\n";
}