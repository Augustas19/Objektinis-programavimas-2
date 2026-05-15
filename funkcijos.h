#ifndef funkcijos_H
#define funkcijos_H

#include <vector>
#include <string>
#include <list>
#include <deque>
#include "header.h"
#include "vec.h"


// generavimas
Studentas gen_vrd();
int gen_pazym();

void skaiciai(long &n, long &m);
int pasirink();

// isvedimai
void isved(Vector<Studentas>& A);
void isvedimas_faila(Vector<Studentas>& A, std::string pav);
void isvedimas_faila(std::list<Studentas>& A, std::string pav);
void isvedimas_faila(std::deque<Studentas>& A, std::string pav);

void failu_kurimas();

// skaitymas
void skt(Vector<Studentas>& A, std::string failopav);
void skt(std::list<Studentas>& A, std::string failopav);
void skt(std::deque<Studentas>& A, std::string failopav);

// rikiavimas
void rikiav(Vector<Studentas>& A, int rik);
void rikiav(std::list<Studentas>& A, int rik);
void rikiav(std::deque<Studentas>& A, int rik);

// 3 strategijos
void rusiavimas(Vector<Studentas>& A, Vector<Studentas>& vargsai, Vector<Studentas>& kietekai);
void rusiavimas(std::list<Studentas>& A, std::list<Studentas>& vargsai, std::list<Studentas>& kietekai);
void rusiavimas(std::deque<Studentas>& A, std::deque<Studentas>& vargsai, std::deque<Studentas>& kietekai);

void strat2(Vector<Studentas>& A, Vector<Studentas>& vargsai);
void strat2(std::list<Studentas>& A, std::list<Studentas>& vargsai);
void strat2(std::deque<Studentas>& A, std::deque<Studentas>& vargsai);

void strat3(Vector<Studentas>& A, Vector<Studentas>& vargsai);
void strat3(std::list<Studentas>& A, std::list<Studentas>& vargsai);
void strat3(std::deque<Studentas>& A, std::deque<Studentas>& vargsai);

// tyrimai
void tyrimas1();
void tyrimas2(Vector<Studentas>& A);
void tyrimas2_ve(Vector<Studentas>& A);
void tyrimas2_li(std::list<Studentas>& A);
void tyrimas2_de(std::deque<Studentas>& A);

// testas
void check(bool salyga, const std::string pavad);
void testavimas();
void laiko_test();
void atminties_testas();

#endif