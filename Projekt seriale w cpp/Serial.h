//    © 2018 Damian Tabaczynski All Rights Reserved

#ifndef Serial_h
#define Serial_h
#include "Media.h"
#include <string>
#include <iostream>

using namespace std;

class Serial : public Media
{
public:
	Serial();
	virtual ~Serial();

	void set_Number_Episodes(unsigned int &number);
	void set_Watched(unsigned int &watched);

	unsigned int get_Watched();
	unsigned int get_Number_Episodes();

	virtual void save(std::ostream& out);
	virtual void load(std::istream& in = std::cin);
	virtual void show();
	virtual void edit();

private:
	unsigned int Number_Episodes, Watched;
};
#endif