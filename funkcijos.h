#ifndef funkcijos_H
#define funkcijos_H

#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::mt19937;
using std::setprecision;
using std::fixed;
using std::string;
using std::getline;

using laik = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_dis;


struct studentas{
    string vard;
    string pav;
    int egz;
    std::vector<int> nd;    
    double vid;
    double med;
    double suma=0;
    double gal;
    double gal2;
};

studentas gen_vrd();
int gen_pazym();
void skaiciai(long &n, long &m);
void skt(std::vector<studentas>& A);
void skaiciavimai(std::vector<studentas>& A);
void isved(std::vector<studentas>& A);

#endif