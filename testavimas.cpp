#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include "header.h"

TEST_CASE(" testas") {
    
    
    
}
TEST_CASE("Copy constructor"){

    std::vector<double> nd = {8, 10, 6};
    Studentas a("Saulius", "Saulaitis", 10, nd);
    Studentas b(a);

    REQUIRE(b.vardas()==a.vardas());
    REQUIRE(b.pavarde()==a.pavarde());
    REQUIRE(b.egzaminas()==a.egzaminas());
    REQUIRE(b.nd()==a.nd());
}