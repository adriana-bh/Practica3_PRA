#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
        // miembros públicos
	std::string key;
	V value;

    	TableEntry(std::string key, V value){ // método constructor del par clave-valor
		this->key = key;
		this->value = value;
	}

	TableEntry(std::string key){  // método constructor clave
		this->key = key;	
	}

	TableEntry(){ // método constructor clave vacía
		key = "";
	}


	friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){ // devuelve si dos claves son iguales
		return te1.key == te2.key;
	}
	friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){ // devuelve si dos claves son distintas
		return te1.key != te2.key;
	}
	friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){ // imprime el par clave-valor
		out << te.key << "->" << te.value;
		return out;
	}
};

#endif
