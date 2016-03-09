#ifndef LIST_H
#define LIST_H
#include "Record.h"

class List{
public:
	List();
	Record *head;
	Record *current;
};
#endif