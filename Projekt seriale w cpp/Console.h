//    © 2018 Damian Tabaczynski All Rights Reserved

#ifndef Console_h
#define Console_h
#include "Collection.h"
#include "Media.h"
class Console
{
public:
	Console();
	virtual ~Console();


	void exit();
	void main_manu();

	Collection<Media> load(Collection <Media> List_of_serials);
	string choose_menu();
	string title_menu();

private:
	string path_to_file;
};

#endif