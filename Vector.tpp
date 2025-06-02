// Vector.tpp
template<typename T>
Vector<T>::Vector(int s) {
    if (s < 0) throw Negative_size{};
    elem = new T[s];
    sz = s; // Make sure this matches the declaration in Vector.h
}

template<typename T>
T& Vector<T>::operator[](int i) {
    // implementation
}

template<typename T>
const T& Vector<T>::operator[](int i) const {
    // implementation
}