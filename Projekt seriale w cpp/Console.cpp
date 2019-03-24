//    © 2018 Damian Tabaczynski All Rights Reserved

#include "pch.h"
#include "Console.h"
#include <fstream>
#include <iostream>
#include "Serial.h"
#include "Movie.h"
#include "Stream.h"
#include <string>
#include <algorithm>
#include <time.h>

char switcher(string str) {
	if (str == "1") return '1';
	if (str == "2") return '2';
	if (str == "3") return '3';
	if (str == "4") return '4';
	if (str == "5") return '5';
	if (str == "6") return '6';
	if (str == "7") return '7';
	if (str == "8") return '8';
	if (str == "9") return '9';
	return '0';
}



Console::Console()
{
	path_to_file = "dane.txt";
}


Console::~Console()
{
}

Collection<Media> Console::load(Collection<Media> List_of_object) {

	string what_is_that="";
	fstream File;
	File.open(path_to_file, ios::app | ios::in);
	if (File.good() == false) throw "BLAD PRZY OTWIERANIU PLIKU DO ODCZYTU ";
	while (!File.eof())
	{
		getline(File,what_is_that);
		if (File.eof()) break;

		if (what_is_that == "Serial")
		{
			Serial *Example;
			Example = new Serial;
			Example->load(File);
			List_of_object += Example;
		}
		else if (what_is_that == "Movie")
		{
			Movie *Example;
			Example = new Movie;
			Example->load(File);
			List_of_object += Example;
		}
		else if (what_is_that == "Stream")
		{
			Stream *Example;
			Example = new Stream;
			Example->load(File);
			List_of_object += Example;
		}
	}
	File.close();
	return List_of_object;
}


void Console::main_manu() {

	Collection<Media> List_of_object;
	List_of_object = load(List_of_object);
	string str_in,choos_object,title;
	char what_to_do_next = '0';
	do {
		cout <<
			"----------------------------------------------------------------------------" << endl <<
			"-                                                                           " << endl <<
			"-   WITAMY W GLOWNYM MENU " << endl <<
			"-                                                                           " << endl <<
			"-   Wpisz 1, aby dodac produkcje." << endl <<
			"-   Wpisz 2, aby usunac produkcje. " << endl <<
			"-   Wpisz 3, aby edytowac lub subskrybowac produkcje. " << endl <<
			"-   Wpisz 4, aby zobaczyc statystyki. " << endl <<
			"-   Wpisz 5, aby zobaczyc wszystkie produkcje. " << endl <<
			"-   Wpisz 6, aby zobaczyc nasza rekomendacje wszystkich produkcji." << endl <<
			"-   Wpisz 7, aby zobaczyc konkretna produkcje." << endl <<
			"-   Wpisz 8, aby zobaczyc jakie streamy sa na zywo lub wkrotce sie zaczna." << endl <<
			"-   Wpisz 9, aby wyjsc z programu " << endl <<
			"-                                                                           " << endl <<
			"-   Autor: Damian Tabaczynski, Jesien 2018 " << endl <<
			"----------------------------------------------------------------------------" << endl << endl;
		getline(cin, str_in);
		system("cls");
		what_to_do_next = switcher(str_in);
		switch (what_to_do_next)
		{
		case '1':
			choos_object = choose_menu();
			if (choos_object=="Serial")
			{
				Serial* Example;
				Example = new Serial;
				Example->load();
				List_of_object += Example;
			}
			else if (choos_object=="Movie")
			{
				Movie* Example;
				Example = new Movie;
				Example->load();
				List_of_object += Example;
			}
			else if (choos_object == "Stream")
			{
				Stream* Example;
				Example = new Stream;
				Example->load();
				List_of_object += Example;
			}
			system("cls");
			break;



		case '2':
			choos_object = choose_menu();
			title = title_menu();
			if (choos_object == "Serial")
			{
				Serial* Example;
				Example = new Serial;
				try
				{
					List_of_object -= List_of_object.find_Elem(title, Example);
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			else if (choos_object == "Movie")
			{
				Movie* Example;
				Example = new Movie;
				try
				{
					List_of_object -= List_of_object.find_Elem(title, Example);
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			else if (choos_object == "Stream")
			{
				Stream* Example;
				Example = new Stream;
				try
				{
					List_of_object -= List_of_object.find_Elem(title, Example);
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			cout << endl << "Gratulacje udalo sie :)" << endl << endl;
			system("pause");
			system("cls");
			break;



		case '3':

			choos_object = choose_menu();
			title = title_menu();
			cout <<
				"----------------------------------------------------------------------------" << endl <<
				"-                                                                           " << endl <<
				"-   WITAMY W MENU EDYCJI " << endl <<
				"-                                                                           " << endl <<
				"-   Aby edytowac konkretne pole prosze wpisac nowe dane i zatwierdzic <ENTER>." << endl <<
				"-   Aby pominac edycje konkretnego pola nacisnij <ENTER> !!! " << endl <<
				"-                                                                           " << endl <<
				"----------------------------------------------------------------------------" << endl << endl;
			if (choos_object == "Serial")
			{
				Serial* Example;
				Example = new Serial;
				//Example = static_cast<Serial*>(List_of_object.find_Elem(title, Example)); // trzeba tak zrobic bo wskaznik jest zwracany jako klasa bazowa czyli Media
				try
				{
					static_cast<Serial*>(List_of_object.find_Elem(title, Example))->edit();
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			else if (choos_object == "Movie")
			{
				Movie* Example;
				Example = new Movie;
				//Example = static_cast<Movie*>(List_of_object.find_Elem(title, Example)); // trzeba tak zrobic bo wskaznik jest zwracany jako klasa bazowa czyli Media
				try
				{
					static_cast<Movie*>(List_of_object.find_Elem(title, Example))->edit();
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}

			}
			else if (choos_object == "Stream")
			{
				Stream* Example;
				Example = new Stream;
				//Example = static_cast<Stream*>(List_of_object.find_Elem(title, Example)); // trzeba tak zrobic bo wskaznik jest zwracany jako klasa bazowa czyli Media
				try
				{
					static_cast<Stream*>(List_of_object.find_Elem(title, Example))->edit();
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			cout << endl << "Gratulacje udalo sie :)" << endl << endl;
			system("pause");
			system("cls");
			break;



		case '4':
			cout <<
				"----------------------------------------------------------------------------" << endl <<
				"-                                                                           " << endl <<
				"-   WITAMY W OKNIE STATYSTYK SERIALI " << endl <<
				"-                                                                           " << endl <<
				"-   Poniezej sa przedstawione statystyki wszystkich produkcji w bazie." << endl <<
				"-                                                                           " << endl <<
				"----------------------------------------------------------------------------" << endl << endl;
			system("pause");
			system("cls");
			List_of_object.show_statistic();
			system("pause");
			system("cls");
			break;


		case '5':
			List_of_object.show_all();
			system("pause");
			system("cls");
			break;


		case '6':
			cout <<
				"----------------------------------------------------------------------------" << endl <<
				"-                                                                           " << endl <<
				"-   WITAMY W OKNIE REKOMENDACJI " << endl <<
				"-                                                                           " << endl <<
				"-   To sa wybrane przez nas najlepsze filmy,seriale i streamy !" << endl <<
				"-                                                                           " << endl <<
				"-   Specjalnie DLA CIEBIE posortowalismy je wedlug ocen uzytkownikow  :)" << endl <<
				"-                                                                           " << endl <<
				"----------------------------------------------------------------------------" << endl<<endl;
			system("pause");
			List_of_object.recomendation();
			system("pause");
			system("cls");
			break;


		case '7':
			choos_object = choose_menu();
			title = title_menu();
			if (choos_object == "Serial")
			{
				Serial* Example;
				Example = new Serial;
				try
				{
					List_of_object.find_Elem(title, Example)->show();
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			else if (choos_object == "Movie")
			{
				Movie* Example;
				Example = new Movie;
				try
				{
					List_of_object.find_Elem(title, Example)->show();
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			else if (choos_object == "Stream")
			{
				Stream* Example;
				Example = new Stream;
				try
				{
					List_of_object.find_Elem(title, Example)->show();
				}
				catch (const char*msg)
				{
					cout << endl << msg << endl << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			cout << endl;
			system("pause");
			system("cls");
			break;



		case '8':
			cout <<
				"----------------------------------------------------------------------------" << endl <<
				"-                                                                           " << endl <<
				"-   STREAM REMINDER !!!" << endl <<
				"-                                                                           " << endl <<
				"-   Ponizej umiescilismy liste streamow, ktore rozpoczna sie w ciagu 6h." << endl <<
				"-   Uwaga dodatkowo moga byc streamy, ktore trwaja juz od godziny!" << endl <<
				"-   Pamietaj kazdy stream mozesz zobaczyc tylko raz :( " << endl <<
				"-                                                                           " << endl <<
				"----------------------------------------------------------------------------" << endl << endl;
			system("pause");
			time_t now;
			time(&now);
			List_of_object.remind_streams(now);
			system("pause");
			system("cls");
			break;



		case '9':
			exit();
			break;


		default:
			cout << endl << "Zla kombinacja klawiszy prosze sprobowac jeszcze raz :( " << endl << endl;
			system("pause");
			system("cls");
			break;
		}

		try
		{
			List_of_object.save_all(path_to_file);
			//fstream File(path_to_file, ios::app);
			//File << "eof";
			//File.close();
		}
		catch (const char*msg)
		{
			cout << endl << msg << endl << endl;
			system("pause");
		}
	} while (what_to_do_next != '9');

	List_of_object.my_destructor();// PONIEWAZ DESTRUKTOR VECTORA NIE USUWA WSKAZNIKOW (TYLKO OBIEKTY) TRZEBA TO ZROBIC RECZNIE, ABY NIE BYLO WYCIEKU PAMIECI
}

string Console::choose_menu() {
	string str_in;
	char what_to_do_next = '0';
	do {
		cout <<
			"----------------------------------------------------------------------------" << endl <<
			"-                                                                           " << endl <<
			"-   Czego ma dotyczyc dzialanie ? " << endl <<
			"-                                                                           " << endl <<
			"-   Wpisz 1, jesli serialu." << endl <<
			"-   Wpisz 2, jesli filmu. " << endl <<
			"-   Wpisz 3, jesli streamu. " << endl <<
			"-                                                                           " << endl <<
			"----------------------------------------------------------------------------" << endl << endl;
		getline(cin, str_in);
		system("cls");
		what_to_do_next = switcher(str_in);
		switch (what_to_do_next)
		{
		case '1':
			return "Serial";
			break;
		case '2':
			return "Movie";
			break;
		case '3':
			return "Stream";
			break;
		default:
			cout << endl << "Zla kombinacja klawiszy prosze sprobowac jeszcze raz :( " << endl << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (true);
}


string Console::title_menu() {
	string str_in;
		cout <<
			"----------------------------------------------------------------------------" << endl <<
			"-                                                                           " << endl <<
			"-   Prosze wpisac tytul produkcji - uwaga wielkosc liter ma znaczenie  D: " << endl <<
			"-                                                                           " << endl <<
			"----------------------------------------------------------------------------" << endl << endl;
		getline(cin, str_in);
		system("cls");
		return str_in;
}


void Console::exit() {
	cout << "----------------------------------------------------------------------------" << endl <<
		"-                                                                           " << endl <<
		"-   DZIEKUJEMY ZA SKORZYSTANIE Z NASZEGO PROGRAMU :) " << endl <<
		"-                                                                           " << endl <<
		"-	 DO WIDZENIA !!!"
		"-                                                                           " << endl <<
		"-                                                                           " << endl <<
		"----------------------------------------------------------------------------" << endl << endl;
}


