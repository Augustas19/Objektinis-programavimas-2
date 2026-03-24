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
//void skt(std::vector<studentas>& A, std::string failopav);
void skaiciavimai(std::vector<studentas>& A);
void isved(std::vector<studentas>& A);
void failu_kurimas();
void rusiavimas(std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai);
void isvedimas_faila(std::vector<studentas>& A, std::string pav);
void tyrimas1();
void tyrimas2(std::vector<studentas>& A);
void rikiav(std::vector<studentas>& A, int rik);
int pasirink();

void skt(std::vector<studentas>& A, std::string failopav);
void skt(std::list<studentas>& A, std::string failopav);
void skt(std::deque<studentas>& A, std::string failopav);

void skaiciavimai(std::vector<studentas>& A);
void skaiciavimai(std::list<studentas>& A);
void skaiciavimai(std::deque<studentas>& A);
#endif