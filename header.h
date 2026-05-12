#ifndef header_H
#define header_H

#include <vector>
#include <string>
#include <iostream>

double mediana(std::vector<double> v);
double vidurkis(std::vector<double> v);

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;
public:
    Zmogus (){}
    Zmogus(const std::string& vardas, const std::string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}

    virtual std::string vardas() const {return vardas_;}
    virtual std::string pavarde() const {return pavarde_;}

    virtual void setVardas(std::string& v){vardas_ = v;}
    virtual void setPavarde(std::string& p){pavarde_ = p;}

    virtual void spausdinti() const = 0;

    virtual ~Zmogus(){
        vardas_.clear();
        pavarde_.clear();
    }

};
class Studentas : public Zmogus {
private : 
    double egzaminas_;
    std::vector<double> nd_;
public:
    Studentas() : Zmogus(), egzaminas_(0){}
    Studentas(std::istream& is);
    // konstruktorius su parametrais
    Studentas(const std::string& vardas, const std::string& pavarde, int egzaminas, const std::vector<double>& nd);
    //getters
    inline int egzaminas() const {return egzaminas_;}
    inline std::vector<double> nd() const {return nd_;}
    //skaiciavimai
    double galutBalas(double (*f) (std::vector<double>) = mediana) const;
    std::istream& readStudent(std::istream& is); 
    //setters
    void setEgz(double egzam){egzaminas_ = egzam;}
    void setNd(double x){nd_.push_back(x);}    

    // ivestis, isvestis
    friend std::istream& operator>>(std::istream& is, Studentas& s);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

    // rule of five
    Studentas(const Studentas& other); // copy constructor

    Studentas(Studentas&& other) noexcept; // move constructor

    Studentas& operator=(const Studentas& other); // priskyrimo kopijavimo operatorius

    Studentas& operator=(Studentas&& other) noexcept; // priskyrimo move operatorius

    void spausdinti() const override;

    ~Studentas() {
    vardas_.clear();
    pavarde_.clear();
    nd_.clear();
    egzaminas_=0;
    }// destructor
};

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalEgza(const Studentas& a, const Studentas& b);



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