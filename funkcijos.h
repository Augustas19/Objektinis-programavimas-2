#ifndef funkcijos_H
#define funkcijos_H

#include <vector>
#include <string>
#include <list>
#include <deque>
#include "header.h"

studentas gen_vrd();
int gen_pazym();
void skaiciai(long &n, long &m);
void isved(std::vector<studentas>& A);
void failu_kurimas();
void tyrimas1();
void tyrimas2(std::vector<studentas>& A);
int pasirink();

template <typename c>
void skt(c& A, const std::string& failopav);


void skaiciavimai(std::vector<studentas>& A);
void skaiciavimai(std::list<studentas>& A);
void skaiciavimai(std::deque<studentas>& A);

void isvedimas_faila(std::vector<studentas>& A, std::string pav);
void isvedimas_faila(std::list<studentas>& A, std::string pav);
void isvedimas_faila(std::deque<studentas>& A, std::string pav);

void rikiav(std::vector<studentas>& A, int rik);
void rikiav(std::list<studentas>& A, int rik);
void rikiav(std::deque<studentas>& A, int rik);

void rusiavimas(std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai);
void rusiavimas(std::list<studentas>& A, std::list<studentas>& vargsai, std::list<studentas>& kietekai);
void rusiavimas(std::deque<studentas>& A, std::deque<studentas>& vargsai, std::deque<studentas>& kietekai);

void strat2(std::vector<studentas>& A, std::vector<studentas>& vargsai);
void strat2(std::list<studentas>& A, std::list<studentas>& vargsai);
void strat2(std::deque<studentas>& A, std::deque<studentas>& vargsai);

void strat3(std::vector<studentas>& A, std::vector<studentas>& vargsai);
void strat3(std::list<studentas>& A, std::list<studentas>& vargsai);
void strat3(std::deque<studentas>& A, std::deque<studentas>& vargsai);

void tyrimas2_ve(std::vector<studentas>& A);
void tyrimas2_li(std::list<studentas>& A);
void tyrimas2_de(std::deque<studentas>& A);
#endif