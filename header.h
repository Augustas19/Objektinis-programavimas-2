#ifndef header_H
#define header_H

#include <vector>
#include <string>
#include <iostream>

double mediana(std::vector<double> v);
double vidurkis(std::vector<double> v);


class Studentas {
private:
std::string vardas_;
std::string pavarde_;
double egzaminas_;
std::vector<double> nd_;

public:
Studentas() : egzaminas_(0){ };  // konstr
Studentas(std::istream& is);
// konstruktorius su parametrais
Studentas(const std::string& vardas, const std::string& pavarde, int egzaminas, const std::vector<double>& nd);
//getters
inline std::string vardas() const {return vardas_;}
inline std::string pavarde() const {return pavarde_;}
inline int egzaminas() const {return egzaminas_;}
inline std::vector<double> nd() const {return nd_;}

double galutBalas(double (*f) (std::vector<double>) = mediana) const;
std::istream& readStudent(std::istream& is); 

void setVardas(std::string v){vardas_ = v;}
void setPavarde(std::string p){pavarde_ = p;}
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

~Studentas() {} // destructor

};

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalEgza(const Studentas& a, const Studentas& b);

#endif