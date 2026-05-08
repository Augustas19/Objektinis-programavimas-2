#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include "header.h"
#include <sstream>

// rule of five testai
TEST_CASE("Copy constructor"){

    std::vector<double> nd = {8, 10, 6};
    Studentas a("Saulius", "Saulaitis", 10, nd);
    Studentas b(a);

    REQUIRE(b.vardas()==a.vardas());
    REQUIRE(b.pavarde()==a.pavarde());
    REQUIRE(b.egzaminas()==a.egzaminas());
    REQUIRE(b.nd()==a.nd());
}
TEST_CASE("Move constructor"){

    std::vector<double> nd = {8, 10, 6};
    Studentas a("Saulius", "Saulaitis", 10, nd);
    Studentas mv(std::move(a));

    REQUIRE(mv.vardas()=="Saulius");
    REQUIRE(mv.pavarde()=="Saulaitis");
    REQUIRE(mv.egzaminas()==10);
    REQUIRE(mv.nd()==std::vector<double>({8, 10, 6}));

    REQUIRE(a.vardas().empty());
    REQUIRE(a.pavarde().empty());
    REQUIRE(a.nd().empty());
}
TEST_CASE("Copy assignment"){
    std::vector<double> nd = {5, 6, 7};
    Studentas a("Saulius", "Saulaitis", 9, nd);
    Studentas b;
    b=a;

    REQUIRE(b.vardas()==a.vardas());
    REQUIRE(b.pavarde()==a.pavarde());
    REQUIRE(b.egzaminas()==a.egzaminas());
    REQUIRE(b.nd()==a.nd());
}
TEST_CASE("Move assignment"){

    std::vector<double> nd = {5, 6, 7};
    Studentas a("Saulius", "Saulaitis", 9, nd);
    Studentas mv;
    mv=std::move(a);

    REQUIRE(mv.vardas()=="Saulius");
    REQUIRE(mv.pavarde()=="Saulaitis");
    REQUIRE(mv.egzaminas()==9);
    REQUIRE(mv.nd()==std::vector<double>({5, 6, 7}));

    REQUIRE(a.vardas().empty());
    REQUIRE(a.pavarde().empty());
    REQUIRE(a.nd().empty());
}

// kiti testai

TEST_CASE("Vidurkio testas") {
    std::vector<double> nd = {1,5,9};
    REQUIRE(vidurkis(nd) == 5.0);
}
TEST_CASE("Medianos testas") {
    std::vector<double> nd = {1,3,5};
    REQUIRE(vidurkis(nd) == 3.0);
}
TEST_CASE("Galutinis balas testas") {
    std::vector<double> nd = {10,8,6};
    Studentas a("a", "b", 10, nd);
    double tgal= 0.4*vidurkis(nd) + 0.6*10;
    REQUIRE(a.galutBalas(vidurkis) == tgal);
}