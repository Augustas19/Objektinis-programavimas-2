#include "header.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

using std::left;
using std::setw;
using std::fixed;
using std::setprecision;

// konstruktoriaus realizacija
Studentas::Studentas(std::istream& is) { 
  readStudent(is);
}

// Studentas::galBalas realizacija
double Studentas::galutBalas(double (*f) (std::vector<double>)) const {
  return 0.4*f(nd_) + 0.6*egzaminas_;
}

// Studentas::readStudent realizacija
std::istream& Studentas::readStudent(std::istream& is) {
    nd_.clear();
    is>>vardas_>>pavarde_;
 
    std::string eilute;
    std::getline(is, eilute);
    std::istringstream buf(eilute);
    std::vector<double> sk;
    int paz;
    while(buf>>paz) sk.push_back(paz);

    if(!sk.empty()){
        egzaminas_=sk.back();
        sk.pop_back();
        nd_ = sk;
    }
    return is;
    
}
// ivestis
std::istream& operator>>(std::istream& is, Studentas& s) {
    return s.readStudent(is);
}
// isvestis
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os<<left<<setw(20)<<s.pavarde_<<left<<setw(20)<<s.vardas_<<" ND: ";
    for(const auto& x : s.nd_){
        os<<x<<" ";
    }
    os<<"EGZ: "<<s.egzaminas_<<fixed<<setprecision(2)<<" VID: "<<s.galutBalas(vidurkis)<<" MED: "<<s.galutBalas();

    return os;
}

double mediana(std::vector<double> v){
    std::sort(v.begin(), v.end());
    int n = v.size();

    if(n%2){
        return v[n/2];   
    }
    else {
        return (v[n/2-1]+v[n/2]) /2.0;
    }
}

double vidurkis(std::vector<double> v){
    double s=0;
    for(auto x:v){
        s+=x;
    }
    return s / v.size();
}

//palyginimai
bool compare(const Studentas& a, const Studentas& b){
    return a.vardas() < b.vardas();
}
bool comparePagalPavarde(const Studentas& a, const Studentas& b){
    return a.pavarde() < b.pavarde();
}
bool comparePagalEgza(const Studentas& a, const Studentas& b){
    return a.egzaminas() < b.egzaminas();
}


// Rule of five

//copy constructor
Studentas::Studentas(const Studentas& other):  
vardas_{other.vardas_},
pavarde_{other.pavarde_},
egzaminas_{other.egzaminas_},
nd_{std::move(other.nd_)}{}


//move constructor
Studentas::Studentas(Studentas&& other) noexcept:   
vardas_ (std::move(other.vardas_)),
pavarde_ (std::move(other.pavarde_)),
egzaminas_ (std::move(other.egzaminas_)),
nd_ (std::move(other.nd_)){
    other.egzaminas_=0.0;
}


// priskyrimas
Studentas& Studentas::operator=(const Studentas& other){ 
    if(&other == this) return *this;

    vardas_=other.vardas_;
    pavarde_=other.pavarde_;
    egzaminas_=other.egzaminas_;
    nd_=other.nd_;

    return *this;
}


// priskyrimo move
Studentas& Studentas::operator=(Studentas&& other) noexcept{
    if(&other == this ) return *this; //saves priskyrimo tikrinimas

    vardas_=std::move(other.vardas_);
    pavarde_=std::move(other.pavarde_);
    egzaminas_=other.egzaminas_;
    nd_=std::move(other.nd_);

    return *this;
}