#include "SetIterator.h"
#include "Set.h"
#define NULL 0
#include <exception>

//complexitate theta(1)
SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	current_elm = m.head;
	first_elm = m.head;
	last_elm = m.tail;
}

//complexitate theta(1)

void SetIterator::first() {
	//TODO - Implementation
	if (first_elm != NULL) {
		current_elm = first_elm;
	}
	else {
		throw std::exception();
	}
}

//complexitate theta(1)
void SetIterator::last() {
	if (last_elm != NULL) {
		current_elm = last_elm;
	}
	else {
		throw std::exception();
	}
}

//complexitate theta(1)
void SetIterator::next() {
	//TODO - Implementation
	if (valid()) {
		current_elm = current_elm->next;  //adresa nodului curent primeste adresa nodului urm
	}
	else {
		throw std::exception();
	}
}


//complexitate theta(1)
void SetIterator::prev() {
	if (valid()) {
		current_elm = current_elm->prev; //nodul curent primeste nodul anterior
	}
	else {
		throw std::exception();
	}
}

//complexitate theta(1)
TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (valid()) {
		return current_elm->info;
	}
	else {
		throw std::exception();
	}
	
}

//complexitate theta(1)
bool SetIterator::valid() const {
	//TODO - Implementation
	if (current_elm != NULL && first_elm != NULL) {
		return true;
	}
	return false;
}



