#ifndef _Vector_H_
#define _Vector_H_

#include <iostream>

// template is the C++'s version of the mathematical "for all T " or more precisely " for all types T"
// the member functions might be defined similarly
// the template typename T prefix makes T a parameter of the declaration it

template<typename T>
class Vector {
    private:
        T* elem;  // elem points to an array of sz elements of type T
        int sz;
    public:
        Vector(int s);
        ~Vector(){delete[] elem;}  //destructor release resources

        // ..copy and move operations
        T& operator[](int i);
        const T& operator[](int i) const;
        int size () const {return sz;}

};



#include "Vector.tpp"   //Include the implementation file here

#endif //  _Vector_H_