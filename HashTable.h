#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../Practica1_PRA/Practica1_PRA/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

template <typename V>
class HashTable: public Dict<V> {

    private:
	int n; // nº elementos almacenados actualmente en la tabla hash
	int max; // tamaño de la tabla hash
	ListLinked<TableEntry<V>>* table; // tabla de cubetas
        int h(std::string key){ // devuelve la posición en la tabla hash de key
		int suma = 0;
            	for (int i = 0; i < key.length(); i++){
                	suma +=int(key.at(i));

                }
            	return (suma%max);
        }


    public:
	HashTable(int size){   // Método constructor
		n = 0;
		max = size;
		table = new ListLinked<TableEntry<V>>[size];
	}
	
	~HashTable() {   // Método destructor
		delete [] table;
	}

	int capacity()const{   // Devuelve nº total de cubetas de la tabla
		return max;
	}

	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
		for (int i = 0; i < th.max; i++){
                out << "cubeta " << i << "elementos ["<< std::endl;
                for (int j = 0; j < th.table[i].size(); j++) {
                    out << "(" << th.table[i].get(j) << ")" << std::endl;
                }
                out << "]" << std::endl;
            }
        	return out;
	}
		
	V operator[](std::string key){
		int valor_Key = h(key);

            TableEntry<V> valor(key);

            if (table[valor_Key].search(valor) == -1){ 

                throw std::runtime_error("¡Clave (Key) '" + key + "' no encontrada!");
            } 

            int Pos_Key = table[valor_Key].search(valor);

            TableEntry<V> result = table[valor_Key].get(Pos_Key);

            return result.value;   
        
        }
        
};

#endif
