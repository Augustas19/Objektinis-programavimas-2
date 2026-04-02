#include "header.h"
#include <algorithm>

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
    
    double x;
    std::vector<double> tmp;
    while (is>>x) 
    {tmp.push_back(x);}
    
    if(!tmp.empty()){
        egzaminas_=tmp.back();
        tmp.pop_back();
        nd_ =tmp;
    }
    else {egzaminas_=0;}

    return is;
}

double mediana(std::vector<double> v){
    std::sort(v.begin(), v.end());
    int n = v.size();

    if(n%2){
        return (v[n/2-1]+v[n/2]) /2.0;
    }
    else {
        return v[n/2];
    }
}

double vidurkis(std::vector<double> v){
    double s=0;
    for(auto x:v){
        s+=x;
    }
    return s / v.size();
}
