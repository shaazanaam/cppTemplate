// Vector.tpp
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