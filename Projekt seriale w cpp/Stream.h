//    © 2018 Damian Tabaczynski All Rights Reserved

#ifndef Stream_h
#define Stream_h
#include "Media.h"
class Stream :
	public Media
{
public:
	Stream();
	virtual ~Stream();

	void set_Streamer(string& Name);
	string get_Streamer();
	void set_Begin_time(int &time);
	time_t get_Begin_time();

	void show_time();
	void reminder();

	virtual void save(std::ostream& out);
	virtual void load(std::istream& in = std::cin);
	virtual void show();
	virtual void edit();

private:
	string Streamer;
	time_t Begin_time;
};

#endif