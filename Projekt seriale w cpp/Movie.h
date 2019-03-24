//    © 2018 Damian Tabaczynski All Rights Reserved

#ifndef Movie_h
#define Movie_h
#include "Media.h"
class Movie :
	public Media
{
public:
	Movie();
	virtual ~Movie();

	void set_Length(unsigned int & length);
	unsigned int get_Length();

	virtual void save(std::ostream& out);
	virtual void load(std::istream& in = std::cin);
	virtual void show();
	virtual void edit();
private:
	unsigned int Length;
};

#endif