#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Container {
    protected:
        T * storage;
        int numitems;
        int storage_size;
        
        Container() :storage(NULL), numitems(0), storage_size(0) {
        }
        virtual ~Container() {
            
        }
        
        virtual void operator += (const T item) {
            
        }
        T & operator[] (int index) {
            return storage[index];
        }
        
        int size() {
            return numitems;
        }
};

template <typename T>
class Box : public Container<T> {
    
    Box() { }
    
    virtual ~Box() { 
        if (storage != NULL) {
            delete [] storage;
        }
    }

    virtual void operator += (const T item) {
        if (storage_size == 0) {
            storage_size = 2;
            storage = new T[storage_size];
        } else {
            if (numitems >= storage_size) {
                storage_size=storage_size*2;
                T * temp = new T[storage_size];
                
                for (int i=0;i<storage_size/2;i++) {
                    temp[i] = storage[i];
                }
                delete [] storage;
                storage = temp;
            }
        }
        
        storage[numitems] = item;
        numitems++;
    }
};

int main(int argc, char** argv) {
    Container<long> * store = new Box();
    *store += 10;
    *store += 20;
    *store += 30;
    
    for (int i=0;i<store->size();i++) {
        cout << (*store)[i] << " " ;
    }
    delete store;
            
    return 0;
}




