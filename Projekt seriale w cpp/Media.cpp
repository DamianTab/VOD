//    © 2018 Damian Tabaczynski All Rights Reserved

#include "pch.h"
#include "Media.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


Media::Media()
{
}

Media::~Media()
{
}

//Niepotrzebne
/* 
bool Media::operator<(Media &other) {
	return Rating < other.Rating;
}
*/


bool Media::get_Subscribed() {
	return Subscribed;
}

void Media::set_Subscribed(bool &subscribed) {
	Subscribed = subscribed;
}


string Media::get_Date() {
	return Date;
}

void Media::set_Date(string &date)
{
	Date = date;
}

string Media::get_Title() {
	return Title;
}

void Media::set_Title(string &title)
{
	Title = title;
}

unsigned int Media::get_Rating() {
	return Rating;
}

void Media::set_Rating(unsigned int &rating)
{
	Rating = rating;
}


void Media::show() {
	cout << "Tytul produkcji : " << Title << endl;
	cout << "Data produkcji : " << Date << endl;;
	cout << "Ocena produkcji : " << Rating << endl;
	cout << "Czy jest subskrybowany : ";
	if (Subscribed)
	{
		cout << "Tak" << endl;
	}
	else
	{
		cout << "Nie" << endl;
	}
}

void Media::load(std::istream& in) {
	if (typeid(in).hash_code() == typeid(std::cin).hash_code()) {
		cout << "Podaj tytul produkcji : ";
		getline(in,Title);
		cout << "Podaj date produkcji : ";
		getline(in, Date);

		bool correct = false;
		string word;
		while (!correct)
		{
			cout << "Podaj ocene produkcji : ";
			getline(in, word);
			correct = true;
			try
			{
				if (stoi(word) < 0) {
					cout << "----------------------------------------------------------------------------" << endl;
					cout << endl << "Prosze wpisac poprawna ocene (liczba naturalna) !!!" << endl << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					correct = false;
				}
				else
				{
					Rating = stoi(word);
				}
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna ocene (liczba naturalna) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}
		
		word = "";
		while (word != "tak" && word != "nie")
		{
			cout << "Podaj czy produkcja ma byc z automatu subskrybowana. Wpisz 'tak' lub 'nie' : ";
			getline(in,word);
			if (word=="nie")
			{
				Subscribed = false;
			}
			if(word =="tak")
			{
				Subscribed = true;
			}
		}
	}
	else
	{
		getline(in,Title);
		getline(in, Date);
		in >> Rating;
		in >> Subscribed;
	}
}



void Media::edit() {
	string word;
		cout << "Zmien tytul produkcji : ";
		getline(cin, word);
		if (word != "")
		{
			Title = word;
		}
		cout << "Zmien date produkcji : ";
		getline(cin, word);
		if (word != "")
		{
			Date = word;
		}


		bool correct = false;
		while (!correct)
		{
			cout << "Zmien ocene produkcji : ";
			getline(cin, word);
			correct = true;
			if (word != "")
			{
				try
				{
					if (stoi(word) < 0) {
						cout << "----------------------------------------------------------------------------" << endl;
						cout << endl << "Prosze wpisac poprawna ocene (liczba naturalna) !!!" << endl << endl;
						cout << "----------------------------------------------------------------------------" << endl;
						correct = false;
					}
					else
					{
						Rating = stoi(word);
					}
				}
				catch (const std::exception& error)
				{
					cout << "----------------------------------------------------------------------------" << endl;
					cout << endl << "Prosze wpisac poprawna ocene (liczba naturalna) !!!" << endl << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					correct = false;
				}
			}
		}

		word = "-1";
		while (word != "tak" && word != "nie" && word!="")
		{
			cout << "Podaj czy produkcja ma byc subskrybowana. Wpisz 'tak' lub 'nie' lub nacisnij <ENTER> aby pominac : ";
			getline(cin, word);
			if (word != "")
			{
				if (word == "nie")
				{
					Subscribed = false;
				}
				if (word == "tak")
				{
					Subscribed = true;
				}
			}
		}
}


void Media::save(std::ostream& out ) {
	out << Title<<"\n";
	out << Date << "\n";
	out << Rating << "\n";
	out << Subscribed << "\n";
}