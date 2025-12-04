bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp TableEntry.h

bin/testHashTable: testHashTable.cpp HashTable.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp HashTable.h

clean:
	rm -rf *.o *.gch bin
