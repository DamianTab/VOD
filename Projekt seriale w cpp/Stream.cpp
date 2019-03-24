//    © 2018 Damian Tabaczynski All Rights Reserved

#include "pch.h"
#include "Stream.h"
#include <time.h>

Stream::Stream()
{
}


Stream::~Stream()
{
}

void Stream::set_Streamer(string &Name) {
	Streamer = Name;
}

string Stream::get_Streamer() {
	return Streamer;
}

void Stream::set_Begin_time(int& seconds) {
	
	time(&Begin_time);
	Begin_time +=seconds;
}

time_t Stream::get_Begin_time() {
	return Begin_time;
}

void Stream::show_time() {
	struct tm * data;
	char godzina[100];
	data = localtime(&Begin_time);
	strftime(godzina, 80, "Czas rozpoczecia streamu: %H:%M:%S.", data);
	cout << godzina << endl;
}

void Stream::reminder() {
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Tytul produkcji : " << get_Title() << endl;
	cout << "Pseudonim Streamera : " << Streamer << endl;
	show_time();
	cout << "----------------------------------------------------------------------------" << endl;
}

void Stream::show() {
	cout << "----------------------------------------------------------------------------" << endl;
	Media::show();
	cout << "Pseudonim Streamera : " << Streamer << endl;
	show_time();
	cout <<endl<< "Rodzaj produkcji : Stream" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}

void Stream::load(std::istream& in) {
	Media::load(in);
	if (typeid(in).hash_code() == typeid(std::cin).hash_code()) {
		cout << "Podaj pseudonim Streamera  : ";
		getline(in, Streamer);

		bool correct = false;
		string word;
		int number;
		while (!correct)
		{
			cout << "Podaj za ile sekund rozpoczyna sie Stream: ";
			getline(in, word);
			correct = true;
			try
			{
				number = stoi(word);
				set_Begin_time(number);
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna ilosc sekund (- jesli chcesz cofnac w czasie) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}
	}
	else
	{
		string word;
		in.ignore();
		getline(in,Streamer);
		in >> Begin_time;
	}
}


void Stream::edit() {
	Media::edit();
	string word;
	cout << "Zmien pseudonim Streamera: ";
	getline(cin, word);
	if (word != "") {
		Streamer = word;
	}


	bool correct = false;
	int number;
	while (!correct)
	{
		cout << "Zmien czas rozpoczecia Streamu liczac od teraz, podajac liczbe sekund: ";
		getline(cin, word);
		correct = true;
		if (word != "") {
			try
			{
				number = stoi(word);
				set_Begin_time(number);
			}
			catch (const std::exception& error)
			{
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl << "Prosze wpisac poprawna ilosc sekund (- jesli chcesz cofnac w czasie) !!!" << endl << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				correct = false;
			}
		}
	}
	
}


void Stream::save(std::ostream& out) {
	out << "Stream" << "\n";
	Media::save(out);
	out << Streamer << "\n";
	out << Begin_time << "\n";
}