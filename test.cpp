#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include "vec.h"
#include <sstream>

TEST_CASE("Constructor"){
    Vector<int> v;
    
    REQUIRE(v.size() == 0);
    REQUIRE(v.empty());

    Vector<int> v2(4, 7);
    REQUIRE(v2.size() == 4);

}
TEST_CASE("Constructor 2"){
    Vector<int> v = {1,2,3};
    
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);

}

TEST_CASE("Copy constructor" ) {
    Vector<int> v1{1, 2, 3};
    Vector<int> v2 = v1;

    REQUIRE(v2.size() == 3);
    REQUIRE(v2[1] == 2);

}

TEST_CASE("Move constructor" ) {
    Vector<int> v1{1, 2, 3};
    Vector<int> v2 = std::move(v1);

    REQUIRE(v2.size() == 3);
    REQUIRE(v1.size() == 0);
}

TEST_CASE("Copy assignment" ) {
    Vector<int> v1{1, 2};
    Vector<int> v2;
    v2 = v1;

    REQUIRE(v2.size() == 2);
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);
}

TEST_CASE("Move assignment" ) {
    Vector<int> v1{1, 2, 3};
    Vector<int> v2;

    v2 = std::move(v1);

    REQUIRE(v2.size() == 3);
    REQUIRE(v1.size() == 0);
}

TEST_CASE("Push back"){
    Vector<int> v;
    
    v.push_back(5);
    v.push_back(10);
    v.push_back(15);

    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 5);
    REQUIRE(v[1] == 10);
    REQUIRE(v[2] == 15);
}

TEST_CASE("At") {
    Vector<int> v(3, 5);

    REQUIRE(v.at(2) == 5);
    REQUIRE_THROWS_AS(v.at(100), std::out_of_range);
}

TEST_CASE("Reserve and capacity") {
    Vector<int> v;
    v.reserve(10);
    REQUIRE(v.capacity() >= 10);
}

TEST_CASE("Insert viena") {
    Vector<int> v{1, 3, 4};
    auto it = v.insert(v.begin()+ 1, 2);

    REQUIRE(*it == 2);
    REQUIRE(v.size() == 4);
    REQUIRE(v[1] == 2);
}

TEST_CASE("Insert kelis") {
    Vector<int> v{1, 4};
    v.insert(v.begin()+ 1, 2, 3);

    REQUIRE(v.size() == 4);

}

TEST_CASE("Erase") {
    Vector<int> v{1, 2, 3, 4};
    v.erase(v.begin()+ 1);

    REQUIRE(v.size() == 3);
    REQUIRE(v[1] == 3);
}

TEST_CASE("Erase kelis") {
    Vector<int> v{1, 2, 3, 4, 5};
    v.erase(v.begin()+ 1, v.begin()+ 4);

    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 5);
}





TEST_CASE("palyginimas") {
    Vector<int> a{1, 2, 3};
    Vector<int> b{1, 2, 3};
    Vector<int> c{1, 2, 4};

    REQUIRE(a == b);
    REQUIRE(a != c);
    REQUIRE(a < c);
    REQUIRE(c > a);
    REQUIRE(a <= b);
    REQUIRE(a >= b);
}

TEST_CASE("Swap") {
    Vector<int> a{1, 2};
    Vector<int> b{3, 4, 5};
    a.swap(b);

    REQUIRE(a.size() == 3);
    REQUIRE(b.size() == 2);
    REQUIRE(a[0] == 3);
    REQUIRE(b[0] == 1);
}
