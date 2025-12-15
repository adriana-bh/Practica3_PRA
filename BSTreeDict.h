#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <iostream>
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
        // constructor
        BSTreeDict(){
            tree = new BSTree<TableEntry<V>>;
        }

        // destructor 
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

        // métodos heredados de la interfaz Dict<T>

        void insert(std::string key, V value) override{ 	

            TableEntry<V> valor(key, value);  
            tree->insert(valor);    
        } 
        

        V search(std::string key) override{	    
            
            TableEntry<V> valor(key); 
            TableEntry<V> result = tree->search(valor);

            return result.value;
        }


        V remove(std::string key) override{ 	
            
            TableEntry<V> valor(key)
            TableEntry<V> result = tree->search(valor);
            tree->remove(valor);

            return result.value;
        } 
        

        int entries() override{	            
            return tree->size();
        } 
        
};

#endif
