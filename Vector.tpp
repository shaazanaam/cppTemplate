// Vector.tpp
#include "Vector.h"

template<typename T>
Vector<T>::Vector(int s) {
    if (s < 0) throw std::length_error{"Vector: negative size"};
    elem = new T[s];
    sz = s; // Make sure this matches the declaration in Vector.h
}


template<typename T>
const T& Vector<T>::operator[](int i) const {
    // implementation
    if(i<0 ||size()<=i)
        throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}

template<typename T>
T& Vector<T>::operator[](int i){
    if(i<0||size()<=i)
        throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}

// to support the range for loop for our vector we must define the suitable begin() and the end()
//functions
template<typename T>
T* begin(Vector<T>& x){
    return &x[0];      //pointer to the first element.. remember that the [] operator returns the reference 
                        //to the element at the location i
                       //however the reference to the element will be the address of that element 
}

template<typename T>
T* end(Vector<T>& x)
{
    return &x[0] + x.size(); //returning the pointer to one past-last element
}

//adding const overloads for the begin and the end function 

template<typename T>
const T* begin(const Vector<T>& x){
    return &x[0];
}

template<typename T>
const T* end(const Vector<T>& x){
    return &x[0] +x.size();
}

// writting a function that calculates the sum of the element values of any container like this :
template<typename Container , typename Value>
Value sum(const Container& c, Value v)
{
    for(auto x:c )
        {
          v+=x;  
        }
    return v;
}

//function objects are used to define objects that can be called like functions 

template<typename T>
class Less_than {
    const T val;  //value to compare against

    public: 
        Less_than (const T& v): val(v){}
        bool operator()(const T& x)const{return x<val;}//call operator
};

template<typename C, typename P>
int count(const C& c , P pred){
    int cnt = 0;
    for(const auto& x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}// a pred is something that we can invoke to return true or false 

template<class C, class Oper>
void for_all(C& c, Oper op)
{
    for(auto& x:c)
        op(*x); // pass op() a reference to each element pointed to 
}