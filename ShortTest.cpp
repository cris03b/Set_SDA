#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"

void testAll() { 
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0);
	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);
	assert(s.search(1) == false);


	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);

	// verificare functii last si prev 
	SetIterator it2 = s.iterator();
	it2.last();
	int sum2 = 0;
	while (it2.valid()) {
		TElem e2 = it2.getCurrent();
		sum2 += e2;
		it2.prev();
	}
	assert(sum2 == 19);

	Set s2;
	assert(s2.isEmpty() == true);
	assert(s2.size() == 0);
	assert(s2.add(5) == true);
	assert(s2.add(1) == true);
	assert(s2.add(10) == true);
	assert(s2.add(7) == true);
	assert(s2.size() == 4);

	//Set s3 = s.intersection(s2);
	//assert(s3.size() == 3);

}

