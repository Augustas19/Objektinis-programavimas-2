#ifndef funkcijos_H
#define funkcijos_H

#include <vector>
#include "header.h"

studentas gen_vrd();
int gen_pazym();
void skaiciai(long &n, long &m);
void skt(std::vector<studentas>& A);
void skaiciavimai(std::vector<studentas>& A);
void isved(std::vector<studentas>& A);
void failu_kurimas(long kiekis, string pavad);
void rusiavimas(std::vector<studentas> A, std::vector<studentas> vargsai, std::vector<studentas> kietekai);
#endif