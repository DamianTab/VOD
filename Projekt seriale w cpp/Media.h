//    © 2018 Damian Tabaczynski All Rights Reserved

#ifndef Media_h
#define Media_h
#include <string>
#include <istream>
#include <typeinfo>
#include <iostream>

using namespace std;

class Media
{
private:
	string Title,Date;
	unsigned int Rating;
	bool Subscribed;

public:
	Media();
	virtual ~Media();

	void set_Title(string &Title);
	void set_Date(string &Date);
	void set_Rating(unsigned int &Rating);
	void set_Subscribed(bool &Subscribed);
	
	string get_Title();
	string get_Date();
	unsigned int get_Rating();
	bool get_Subscribed();

	//bool operator<(Media &other); /Nie potrzene

	virtual void edit();
	virtual void save(std::ostream& out);
	virtual void load(std::istream& in = std::cin);
	virtual void show();
	};


#endif
