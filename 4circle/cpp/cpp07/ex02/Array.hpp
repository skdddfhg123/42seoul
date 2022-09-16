#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T* array;
        unsigned int len;
    public:
        Array();
        Array(unsigned int len);
        Array(const Array& src);
        Array& operator=(const Array& src);
        ~Array();

        T& operator[](unsigned int index) const;
        unsigned int getLen() const;
        class OutBoundException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

template <typename T>
Array<T>::Array() : len(0) {
  this->array = new T[0];
}

template <typename T>
Array<T>::Array(const Array& src) : len(src.getLen()) {
    this->array = new T[this->len];
    for (unsigned int i = 0; i < this->len; i++)
        this->array[i] = src.array[i];
}

template <typename T>
Array<T>::Array(unsigned int len) : array(NULL), len(len) {
    if (this->len)
        array = new T[this->len];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src) {
    if (this != &src) {
        delete []this->array;
        this->array = NULL;
        this->len = 0;
        this->len = src.getLen();
        this->array = new T[this->len];
        for (unsigned int i = 0; i < this->len; i++)
            array[i] = src.array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() {
    delete []this->array;
    this->array = NULL;
    this->len = 0;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const {
    if (index >= this->len)
        throw Array<T>::OutBoundException();
    return this->array[index];
}

template <typename T>
unsigned int Array<T>::getLen() const {
    return (this->len);
}

template <typename T>
const char* Array<T>::OutBoundException::what() const throw() {
    return ("index is out bound");
}

#endif
