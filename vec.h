#ifndef vec.h
#define vec.h

#include <vector>
#include <string>
#include <iostream>


template<class T, class Allocator=std::allocator<T>>
class Vector {
public:
    // member types
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    using iterator = T*;
    using const_iterator = const T*;    
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
private:
    T* data_;
    size_type size_;
    size_type capacity_;

    void reallocate(size_type new_cap){
        T* new_data =new T[new_cap];
        for(size_type i =0; i<size_; i++){
            new_data[i] = std::move(data_[i]);
        } 
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;    
    }
public:
// constr 
Vector() : data_(nullptr), size_(0), capacity_(0) {}

explicit Vector(size_type n, const T& value = T()):data_(new T[n]), size_(n), capacity_(n){
    for(size_type i=0; i<n; i++){
        data_[i]=value;
    }
}
Vector(std::initializer_list<T> init):data_(new T[init.size()]), size_(init.size()), capacity_(init.size()){
size_type i = 0;
for(const auto& v: init){
    data_[i++] = v;
}
}
// RULE OF FIVE ---------------
~Vector() {delete[] data_;}

Vector(const Vector& orther):
data_(new T[other.capacity_]),
size_(other.size_),
capacity_(other.capacity_){
    std::copy(other.data_, other.data_+ size_, data_);
}

Vector(Vector&& other) noexcept
:data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

Vector& operator=(const Vector& other){
    if(this != &other){
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        std::copy(other.data_, other.data_ + size_, data_);
    }
    return *this;
}

Vector& operator=(Vector&& other) noexcept{
    if(this != &other){
        delete[] data_;
        data_ = other.data_;
        size_=other.size_;
        capacity_=other.capacity_;
        other.data_=nullptr;
        other.size_=0;
        other.capacity_=0;
    }
    return *this;
}

// assign 
void assign(size_type count, const T& value){
    if(count > capacity_){
        reserve(count);
    }
    for(size_type i = 0; i<count; i++){
        data_[i] = value;
    }
    size_ = count;
}

template<typename InputIt>
void assign(InputIt first, InputIt last){
    clear();
    for(; first != last; ++first){
        push_back(*first);
    }
}

// element access

T& operator[](size_type i){ return data_[i]; }
const T& operator[](size_type i) const {return data_[i];}

T& at(size_type i ){
    if(i >= size_) throw std::out_of_range("Vector::at");
    return data_[i];
}
const T& at(size_type i) const {
    if(i >= size_) throw std::out_of_range("Vector::at");
    return data_[i];
}
T& front() {return data_[0];}
T& back() {return data_[size_ -1];}

// iterators

iterator begin() { return data_; }
iterator end() { return data_ + size_; }

const_iterator begin() const { return data_; }
const_iterator end() const { return data_ + size_; }

const_iterator cbegin() const { return data_; }
const_iterator cend() const { return data_ + size_; }

// capacity

size_type size() const { return size_; }
size_type capacity() const { return capacity_; }
bool empty() const { return size_ == 0; }

void reserve(size_type new_cap){
    if(new_cap > capacity_)
        reallocate(new_cap);
}

void resize(size_type new_size){
    if(new_size > capacity_)
        reallocate(new_size);
    
    for(size_type i = size_; i < new_size; ++i)
        data_[i]=T();

    size_ = new_size;
}

};

#endif