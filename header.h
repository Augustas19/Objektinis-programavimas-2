#ifndef header_H
#define header_H

#include <vector>
#include <string>
#include <iostream>
#include "vec.h"

double mediana(Vector<double> v);
double vidurkis(Vector<double> v);

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
    Vector<double> nd_;
public:
    Studentas() : Zmogus(), egzaminas_(0){}
    Studentas(std::istream& is);
    // konstruktorius su parametrais
    Studentas(const std::string& vardas, const std::string& pavarde, int egzaminas, const Vector<double>& nd);
    //getters
    inline int egzaminas() const {return egzaminas_;}
    inline Vector<double> nd() const {return nd_;}
    //skaiciavimai
    double galutBalas(double (*f) (Vector<double>) = mediana) const;
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


#endif