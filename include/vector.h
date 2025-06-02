//
// Created by matteoverz on 6/2/25.
//

#pragma once
#include <ostream>
#include <istream>
#include <cassert>

// http://www.cplusplus.com/reference/vector/vector/

/* Vector:
    - container
    - resize a.i. sa ocupe ~ numar de el. memorie
        - capacity = 2^k spatiu unde k minim, k >= size
    - tipul de elemente dat prin template

    Functionalitati:
        - contructori:
            - ()
            - (int size, default_val)
            - (vector)

        - size()
        - capacity()
        - resize(int size)
        - empty()
        - reserve(int capacity)
        - shrink_to_fit()

        - front()
        - back()
        - operator [] (int pos)
        - begin()
        - end()

        - push_back(x)
        - pop_back()
        // - insert -> 3 variante
        - erase -> sterge range de elemente
        - clear()
*/

template<class type>
class Vector {
public:
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const type& default_value);
    Vector(const Vector<type>& other);
    ~Vector();

    unsigned int size() const;
    unsigned int capacity() const;
    bool empty() const;
    void resize(unsigned int size, const type& default_value = type());
    // face capacitatea macar capacitatea data
    void reserve(unsigned int capacity);
    void shrink_to_fit();

    type& front();
    const type& front() const;
    type& back();
    const type& back() const;
    type& operator [](int pos);
    const type& operator [](int pos) const;
    type * begin();
    type * end();

    void push_back(const type& value);
    void pop_back();
    void clear();

    // nu inca
    // void erase(type* begin, type* end);

private:
    static constexpr unsigned int kMinCapacity = 1;

    // modif capacity_ => realloc
    // size_ <= capacity_
    unsigned int size_ = 0;
    unsigned int capacity_ = 0;
    type* contents_;
};

template<class type>
Vector<type>::Vector() {
    capacity_ = kMinCapacity;
    contents_ = new type[capacity_];
}

template<class type>
Vector<type>::Vector(const unsigned int size) {
    size_ = capacity_ = size;
    contents_ = new type[capacity_]();
}

template<class type>
Vector<type>::Vector(const unsigned int size, const type& default_value) {
    size_ = capacity_ = size;
    contents_ = new type[capacity_];
    for (std::size_t i = 0; i < size_; i++)
        contents_[i] = default_value;
}

template<class type>
Vector<type>::Vector(const Vector<type>& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    contents_ = new type[capacity_];
    for (std::size_t i = 0; i < size_; i++)
        contents_[i] = other.contents_[i];
}

template<class type>
Vector<type>::~Vector() {
    size_ = capacity_ = 0;
    delete[] contents_;
}

template<class type>
unsigned int Vector<type>::size() const {
    return size_;
}

template<class type>
unsigned int Vector<type>::capacity() const {
    return capacity_;
}

template<class type>
bool Vector<type>::empty() const {
    return (size_ == 0);
}

// v = 4 5 2 4 3
// v.resize()
// daca size_ > size:
//      - micsoram numarul de elemente
// daca size_ < size:
//      - crestem size_
//      - size > capacity_ -> capacity_ creste
template<class type>
void Vector<type>::resize(const unsigned int size, const type& default_value) {
    if (size > size_) {
        type* new_contents = new type[size];
        size_t copy_size = (size < size_) ? size : size_;
        for (size_t i = 0; i < copy_size; i++)
            new_contents[i] = contents_[i];

        for (size_t i = size_; i < size; i++)
            new_contents[i] = default_value;

        delete[] contents_;
        contents_ = new_contents;
    }

    size_ = capacity_ = size;
}

// Dacă capacitatea actuala este mai mica decat cea data,
// aloca suficient cat cea data sa incapa
template<class type>
void Vector<type>::reserve(const unsigned int capacity) {
    if (capacity_ >= capacity) return;

    type* new_contents = new type[capacity];
    for (size_t i = 0; i < size_; i++)
        new_contents[i] = contents_[i];

    delete[] contents_;
    contents_ = new_contents;
    capacity_ = capacity;
}

// Vector 5 elem => 5 elem in memorie
// mai exact, capacitatea ar trebui sa ajunga exact cat size-ul
template<class type>
void Vector<type>::shrink_to_fit() {
    capacity_ = size_;
}

// daca size-ul depaseste capacitatea => dublam capacitatea
// si realocam
template<class type>
void Vector<type>::push_back(const type& x) {
    if (capacity_ == size_) {
        capacity_ *= 2;
        type* new_contents = new type[capacity_];
        for (size_t i = 0; i < size_; i++)
            new_contents[i] = contents_[i];

        delete[] contents_;
        contents_ = new_contents;
    }

    contents_[size_++] = x;
}

// daca size_ <= capacity_ / 3 => capacity_ /= 2
// si realocam
template<class type>
void Vector<type>::pop_back() {
    size_--;
    if (size_ <= capacity_ / 3) {
        capacity_ /= 2;
        type* new_contents = new type[capacity_];
        for (size_t i = 0; i < size_; i++)
            new_contents[i] = contents_[i];

        delete[] contents_;
        contents_ = new_contents;
    }
}

// elimina elementele vectorului fara a le dealoca
// => size_ ajunge 0, dar capacity nu neaparat
template<class type>
void Vector<type>::clear() {
    size_ = 0;
}

// random access (v[i])
template<class type>
type& Vector<type>::operator [](const int pos) {
    assert(0 <= pos && pos < (int)size_);
    return contents_[pos];
}

// random access (v[i])
template<class type>
const type& Vector<type>:: operator [](const int pos) const {
    assert(0 <= pos && pos < (int)size_);
    return contents_[pos];
}

// returneaza referinta la primul element
template<class type>
type& Vector<type>::front() {
    assert(!empty());
    return contents_[0];
}

// returneaza referinta la primul element
template<class type>
const type& Vector<type>::front() const {
    assert(!empty());
    return contents_[0];
}

// returneaza referinta la ultimul element
template<class type>
type& Vector<type>::back() {
    assert(!empty());
    return contents_[size_ - 1];
}

// returneaza referinta la ultimul element
template<class type>
const type& Vector<type>::back() const {
    assert(!empty());
    return contents_[size_ - 1];
}

// pointer la primul element
// for (type* it = v.begin(); it != v.end(); it++)
template<class type>
type * Vector<type>::begin() {
    assert(!empty());
    return contents_;
}

// pointer la ultimul element
// for (type* it = v.begin(); it != v.end(); it++)
template<class type>
type * Vector<type>::end() {
    assert(!empty());
    return contents_ + size_;
}

template<class type>
std::ostream& operator <<(std::ostream& out, const Vector<type>& to_print) {
    for (std::size_t i = 0; i < to_print.size(); i++)
        out << to_print[i] << ' ';
    return out;
}

template<class type>
std::istream& operator >>(std::istream& in, Vector<type>& to_read) {
    size_t n;
    in >> n;
    to_read.resize(n);
    for (size_t i = 0; i < n; ++i)
        in >> to_read[i];
    return in;
}
