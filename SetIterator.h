#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& s);

	//TODO - Representation
	Set* current_elm, * last_elm, * first_elm;


public:
	void first();
	void last();
	void next();
	void prev();
	TElem getCurrent();
	bool valid() const;
};


