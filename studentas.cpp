#include "header.h"
#include <algorithm>
#include <sstream>

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
std::istream& operator>>(std::istream& is, Studentas& s) {
    return s.readStudent(is);
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
