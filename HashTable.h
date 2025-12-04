#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../Practica1_PRA/Practica1_PRA/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

using namespace std;

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
		int valor_Key = h(key);     // Obtenemos la posición (cubeta) en la tabla hash en función de la key.

            TableEntry<V> valor(key);   // Creamos una variable de tipo TableEntry<V>, donde almacenamos la clave sin valor.

            if (table[valor_Key].search(valor) == -1){  // Comprobamos si la clave (key) est
                throw std::runtime_error("¡Clave (Key) '" + key + "' no encontrada!");
            } 

            int Pos_Key = table[valor_Key].search(valor);

            TableEntry<V> result = table[valor_Key].get(Pos_Key);

            return result.value;   
        
        }

	// Métodos heredados de la interfaz Dict<T>

        void insert(std::string key, V value) override{ 	// Inserta el par key->value en el diccionario.

            int valor_Key = h(key);     // Obtenemos la posición (cubeta) en la tabla hash en función de la key.

            TableEntry<V> valor(key, value);  // Creamos una variable de tipo TableEntry<V>, donde almacenamos los pares clave→valor

            if (table[valor_Key].search(valor) != -1){  // Comprobamos si la clave (key) ya existe en el diccionario. Si no existe devuelve un -1.
                throw std::runtime_error("¡La clave (Key) '" + key + "' ya existe!");   // Si ya existe lanzamos una excepción.
            } 

            table[valor_Key].prepend(valor);    // Insertamos la variable de tipo TableEntry<V> al principio de la lista.

            n++;    // Incrementamos el número de elementos almacenados actualmente en la tabla hash.
        } 
        

        V search(std::string key) override{	    // Busca el valor correspondiente a key. Devuelve el valor value asociado si key está en el diccionario.
            
            int valor_Key = h(key);     // Obtenemos la posición (cubeta) en la tabla hash en función de la key.

            TableEntry<V> valor(key);   // Creamos una variable de tipo TableEntry<V>, donde almacenamos la clave sin valor.

            if (table[valor_Key].search(valor) == -1){  // Comprobamos si la clave (key) está en el diccionario. Si no existe devuelve un -1.
                throw std::runtime_error("¡Clave (Key) '" + key + "' no encontrada!");   // Si no se encuentra, lanza una excepción
            } 

            int Pos_Key = table[valor_Key].search(valor);           // Guardamos la posición donde se guarda el valor de la clave (Key).
            TableEntry<V> result = table[valor_Key].get(Pos_Key);   // Buscamos el valor que se guarda en la posición de la clave (Key).
            return result.value;    // Retornamos el resultado
        }


        V remove(std::string key) override{ 	// Elimina el par key->value si se encuentra en el diccionario.
            
            int valor_Key = h(key);     // Obtenemos la posición (cubeta) en la tabla hash en función de la key.

            TableEntry<V> valor(key);   // Creamos una variable de tipo TableEntry<V>, donde almacenamos la clave sin valor.

            if (table[valor_Key].search(valor) == -1){  // Comprobamos si la clave (key) está en el diccionario. Si no existe devuelve un -1.
                throw std::runtime_error("¡Clave (Key) '" + key + "' no encontrada!");   // Si no se encuentra, lanza una excepción
            } 

            n--;    // Decrementamos el número de elementos almacenados actualmente en la tabla hash.

            int Pos_Key = table[valor_Key].search(valor);           // Guardamos la posición donde se guarda el valor de la clave (Key).
            TableEntry<V> result = table[valor_Key].remove(Pos_Key);// Eliminamos el valor que se guarda en la posición de la clave (Key).
            return result.value;    // Retornamos el resultado
        } 
        

        int entries() override{	            // Devuelve el número de elementos que tiene el Diccionario.
            return n;
        } 
        
};

#endif
