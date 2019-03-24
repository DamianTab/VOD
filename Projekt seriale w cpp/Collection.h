//    © 2018 Damian Tabaczynski All Rights Reserved

#ifndef Collection_h
#define Collection_h
#include <iostream>
#include <vector>
#include <fstream>
#include "Serial.h"
#include "Media.h"
#include "Movie.h"
#include "Media.h"
#include "Stream.h"
using namespace std;

template <class T>
class Collection
{
public:
	Collection();
	virtual ~Collection();


	T* find_Elem(string title, T* what_type);
	void show_all();
	void recomendation();
	void show_statistic();
	void show_selected(T* what);
	void save_all(string path);
	void remind_streams(time_t time);

	void my_destructor(); // Aby nie by³o wycieku pamiêci - niestety tylko wskazniki s¹ usuwane w przypadku standardowego destruktora :(


	Collection& operator+=(T* B) {
		All_Objects.push_back(B);
		return *this;
	}

	Collection& operator-=(T* B) {
		for (unsigned int i = 0; i < All_Objects.size(); i++)
		{
			if (All_Objects[i] == B) {
				All_Objects.erase(All_Objects[i]);
			}
		}
		return *this;
	}

private:
	vector <T*> All_Objects;
};




template <class T> Collection <T>::Collection()
{
}


template <class T> Collection <T>::~Collection()
{
}

template <class T> void Collection<T>::my_destructor() {
	for (unsigned int i = 0; i < All_Objects.size(); i++)
	{
		delete All_Objects[i];
	}
}

template<class T> bool greaterThan(T* a, T* b)
{
    return a->get_Rating()>b->get_Rating();
}


template <class T>T* Collection<T>::find_Elem(string title, T* what_type) {
	//if (typeid(*it).hash_code() == typeid(what_type).hash_code()) {}
	//NIESTETY COS TAKIEGO NIE DZIALA, BO WSKAZUJE NA KLASE BAZOW¥ :(
	if (dynamic_cast <Serial*> (what_type))
	{
		for (unsigned int i = 0; i < All_Objects.size(); i++)
		{
			if (dynamic_cast <Serial*>(All_Objects[i]) && All_Objects[i]->get_Title() == title) return All_Objects[i];
		}
	}
	if (dynamic_cast<Movie*>(what_type))
	{
		for (unsigned int i = 0; i < All_Objects.size(); i++)
		{
			if (dynamic_cast<Movie*>(All_Objects[i]) && All_Objects[i]->get_Title() == title) return All_Objects[i];
		}
	}
	if (dynamic_cast<Stream*>(what_type))
	{
		for (unsigned int i = 0; i < All_Objects.size(); i++)
		{
			if (dynamic_cast<Stream*>(All_Objects[i]) && All_Objects[i]->get_Title() == title) return All_Objects[i];
		}
	}
	throw "Nie ma produkcji o takiej nazwie !!!  :(";
	return nullptr;
}


template <class T> void Collection<T>::remind_streams(time_t now) {

		for (unsigned int i = 0; i < All_Objects.size(); i++)
		{
			if (dynamic_cast<Stream*>(All_Objects[i]) && (static_cast<Stream*>(All_Objects[i])->get_Begin_time()>now-3600) && (static_cast<Stream*>(All_Objects[i])->get_Begin_time() < (now + 6*3600)) ) {
				static_cast<Stream*>(All_Objects[i])->reminder();
			}
		}
}


template <class T> void Collection<T>::show_all() {
	for (unsigned int i = 0; i < All_Objects.size(); i++) All_Objects[i]->show();
}

template<class T> void Collection<T>::show_selected(T* A) { //Nigdzie nie bylo potrzebne no ale trudno
	A->show();
}

template<class T>void Collection<T>::recomendation() {
	
	sort(All_Objects.begin(), All_Objects.end(),greaterThan<T>);
	show_all();
}

template <class T>void Collection<T>::show_statistic() {
	
	int sum_serial = 0, sum_movie = 0, sum_stream = 0;
	int subscribed_serial = 0, subscribed_movie = 0, subscribed_stream = 0;
	int sum_watched_serials = 0, sum_length_movie = 0, sum_number_episodes = 0;;
	int average_rating_serial = 0, average_rating_movie = 0, average_rating_stream = 0;

	for (unsigned int i = 0; i < All_Objects.size(); i++)
	{
		if (dynamic_cast <Serial*>(All_Objects[i])) {
			sum_serial++;
			subscribed_serial+= All_Objects[i]->get_Subscribed();
			sum_number_episodes += static_cast<Serial*> (All_Objects[i])->get_Number_Episodes();
			sum_watched_serials += static_cast<Serial*> (All_Objects[i])->get_Watched();
			average_rating_serial += All_Objects[i]->get_Rating();
		}
		if (dynamic_cast <Movie*>(All_Objects[i])) {
			sum_movie++;
			subscribed_movie += All_Objects[i]->get_Subscribed();
			sum_length_movie += static_cast<Movie*>(All_Objects[i])->get_Length();
			average_rating_movie += All_Objects[i]->get_Rating();
		}
		if (dynamic_cast <Stream*>(All_Objects[i])) {
			sum_stream++;
			subscribed_stream += All_Objects[i]->get_Subscribed();
			average_rating_stream += All_Objects[i]->get_Rating();
		}
	}
	if (sum_serial!=0) average_rating_serial /= sum_serial;
	if (sum_movie != 0) average_rating_movie /= sum_movie;
	if (sum_stream != 0) average_rating_stream /= sum_stream;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << endl << "---Statystyki Seriali--- " << endl;
	cout << endl << "Ilosc wszystkich seriali wynosi : " << sum_serial << endl;
	cout << endl << "Ilosc seriali subskrybowanych wynosi : " << subscribed_serial << endl;
	cout << endl << "Laczna ilosc odcinkow wszystkich seriali wynosi : " << sum_number_episodes << endl;
	cout << endl << "Laczna ilosc obejrzanych odcinkow seriali wynosi : " << sum_watched_serials << endl;
	cout << endl << "Srednia ocen seriali wynosi : " << average_rating_serial << endl << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << endl << "---Statystyki Filmow--- " << endl;
	cout << endl << "Ilosc wszystkich filmow wynosi : " << sum_movie << endl;
	cout << endl << "Ilosc filmow subskrybowanych wynosi : " << subscribed_movie << endl;
	cout << endl << "Potrzebny czas na obejrzenie wszystkich filmow w bazie (w minutach) wynosi : " << sum_length_movie << endl;
	cout << endl << "Srednia ocen filmow z IMDB wynosi : " << average_rating_movie << endl << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	cout << endl << "---Statystyki Streamow--- " << endl;
	cout << endl << "Ilosc wszystkich streamow wynosi : " << sum_stream << endl;
	cout << endl << "Ilosc streamow subskrybowanych wynosi : " << subscribed_stream << endl;
	cout << endl << "Srednia ocen streamow wynosi : " << average_rating_stream << endl << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}

template <class T>void Collection<T>::save_all(string path) {
	fstream File;
	File.open(path, ios::out | ios::trunc);
	if (File.good() == false) throw "BLAD PRZY ZAPISYWANIU PLIKU ";
	for (unsigned int i = 0; i < All_Objects.size(); i++)
	{
		All_Objects[i]->save(File);
	}
	File.close();
}
#endif