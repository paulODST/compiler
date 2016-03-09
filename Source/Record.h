#ifndef RECORD_H
#define RECORD_H
#include <string>

using namespace std;

class Record
{
public:
	Record(string);
	Record *after;
	string key;
};
#endif