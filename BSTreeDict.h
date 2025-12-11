#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

    public:
        BSTreeDict(){
		tree = new BSTree<TableEntry<V>>;		
	}
	
	~BSTreeDict(){
		delete tree;
	}

	friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
		out << *(bs.tree);
		return out;
	}

	V operator[](std::string key){
		TableEntry<V> valor(key);
		TableEntry<V> result = tree->search(valor);
		return result.value;
	}
        
};

#endif
