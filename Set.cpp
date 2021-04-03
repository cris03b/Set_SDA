#include "Set.h"
#include "SetITerator.h"
#define NULL 0
#include <cstdlib>

//complexitate theta(1)
Set::Set() {
	//TODO - Implementation
	info = NULL_TELEM;
	next = NULL;
	prev = NULL;
	head = NULL;
	tail = NULL;

}

//complexitate theta(1)
bool Set::add(TElem elem) {
	//TODO - Implementation

	// CAZ 1: adaugare primul element; nu trebuie verificat daca sunt elemente cu aceeasi valoare in container
	// head = NULL => nu sunt elemente in lista / if (isEmpty())
	if (head == NULL) {
		Set* new_node = new Set();  //alocare spatiu nod nou
		new_node->info = elem;  //atribuire valoare
		// new_node va fi primul si ultimul elm din lista => next si prev = NULL (nu tine adresele niciunui alt nod)
		new_node->next = NULL;
		new_node->prev = NULL;
		// new_node va fi primul element => va fi si head si tail
		head = new_node;
		tail = new_node; 
		length++;  //creste lungimea listei
		return true;
	}

	else {		
		// CAZ 2: adaugare pe ultima pozitie daca valoarea nu se gaseste in set
		// am folosit functia de search, daca returneaza false => nu s-a gasit val => se poate adauga
		if (!search(elem)) {
			Set* new_node = new Set();  //alocare spatiu nod nou
			new_node->info = elem;  //atribuire valoare
			new_node->next = NULL;  //pt ca este ultimul elm din lista
			new_node->prev = tail;  //se face conexiunea cu ultimul nod (tail)
			tail->next = new_node;  //-,,-
			tail = new_node;  //new_node se adauga la sfarsit => va deveni tail
			length++;  //creste lungimea listei
			return true;
		}
	}
	// CAZ 3: daca valoarea s-a gasit in lista => return false
	return false;
}

//Complexitate O(n)
bool Set::remove(TElem elem) {
	//TODO - Implementation
	// daca e un singur element in set si are valoarea = elem => destroy
	if (size() == 1 && head->info == elem) {
			head = NULL;
			tail = NULL;
			length = 0;
			return true;
	}

	// verificam daca sunt elemente in set
	else if (size() > 1) {
			// verificam daca elementul pe care vrem sa il stergem e chiar head => trebuie mutat head-ul
			// prev de la urmatorul nod va pointa spre NULL => devine head
			if (head->info == elem) {
				head = head->next;
				head->prev = NULL;
				length--;
				return true;
			}

			// verificam daca elementul pe care vrem sa il stergem e chiar tail => trebuie mutat tail-ul
			// next de la nodul anterior va pointa spre NULL => devine tail
			else if (tail->info == elem) {
				tail = tail->prev;
				tail->next = NULL;
				length--;
				return true;
			}

			// daca nu => il cautam in lista, pe acelasi principiu ca la functia de search
			// cu exceptia ca salvam current_node pentru a ne putea referi la next-ul si prev-ul lui
			// daca se gaseste trebuie mutate next de la nodul anterior pe prev de la current_node si prev de la nodul urmator pe next de la current_node
			else {
				bool found = false;
				Set* current_node = head;
				while (current_node != NULL) {
					if (current_node->info == elem) {
						found = true;
						break;
					}
					current_node = current_node->next;
				}

				if (found) {
					current_node->prev->next = current_node->next;
					current_node->next->prev = current_node->prev;
					// delete current_node;
					length--;
					return true;
				}
			}
		}

	return false;
}

//Complexitate O(n)
bool Set::search(TElem elem) const {
	//TODO - Implementation
	// setam current_node pe head, ca sa inceapa cautarea de la inceput 
	// daca ajunge current_node = NULL => s-a ajuns la capatul listei
	// daca nu este niciun element in lista => head = NULL => nu intra in while si nu gaseste elementul
	Set* current_node = head;
	while (current_node != NULL) {
		if (current_node->info == elem) {
			return true;
		}
		current_node = current_node->next;
	}

	return false;
}

//complexitate theta(1)
int Set::size() const {
	//TODO - Implementation
	if (length > 0) {
		return length;
	}

	return 0;
}

//complexitate theta(1)
bool Set::isEmpty() const {
	//TODO - Implementation
	if (length == 0) {
		return true;
	}

	return false;
}

//complexitate O(n)
Set::~Set() {
	//TODO - Implementation
	while (head != NULL) {
		Set* aux = head;
		head = head->next;
		aux->~Set();
		free(aux);
	}
}

//complexitate theta(1)
SetIterator Set::iterator() const {
	return SetIterator(*this);
}


