#ifndef funkcijos_H
#define funkcijos_H

#include <vector>
#include <string>
#include <list>
#include <deque>
#include "header.h"

// generavimas
Studentas gen_vrd();
int gen_pazym();

void skaiciai(long &n, long &m);
int pasirink();

// isvedimai
void isved(std::vector<Studentas>& A);
void isvedimas_faila(std::vector<Studentas>& A, std::string pav);
void isvedimas_faila(std::list<Studentas>& A, std::string pav);
void isvedimas_faila(std::deque<Studentas>& A, std::string pav);

void failu_kurimas();

template <typename c>
void skt(c& A, const std::string& failopav);

// rikiavimas
void rikiav(std::vector<Studentas>& A, int rik);
void rikiav(std::list<Studentas>& A, int rik);
void rikiav(std::deque<Studentas>& A, int rik);

// 3 strategijos
void rusiavimas(std::vector<Studentas>& A, std::vector<Studentas>& vargsai, std::vector<Studentas>& kietekai);
void rusiavimas(std::list<Studentas>& A, std::list<Studentas>& vargsai, std::list<Studentas>& kietekai);
void rusiavimas(std::deque<Studentas>& A, std::deque<Studentas>& vargsai, std::deque<Studentas>& kietekai);

void strat2(std::vector<Studentas>& A, std::vector<Studentas>& vargsai);
void strat2(std::list<Studentas>& A, std::list<Studentas>& vargsai);
void strat2(std::deque<Studentas>& A, std::deque<Studentas>& vargsai);

void strat3(std::vector<Studentas>& A, std::vector<Studentas>& vargsai);
void strat3(std::list<Studentas>& A, std::list<Studentas>& vargsai);
void strat3(std::deque<Studentas>& A, std::deque<Studentas>& vargsai);

// tyrimai
void tyrimas1();
void tyrimas2(std::vector<Studentas>& A);
void tyrimas2_ve(std::vector<Studentas>& A);
void tyrimas2_li(std::list<Studentas>& A);
void tyrimas2_de(std::deque<Studentas>& A);
#endif