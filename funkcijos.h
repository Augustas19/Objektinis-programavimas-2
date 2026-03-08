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
#endif