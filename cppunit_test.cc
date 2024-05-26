#include "biblioteka.h"
#include "cppunit.h"

class StudentasTests : public Cppunit {
public:
    void testDefaultConstructor() {
        studentas s1;
        CHECKS(s1.vardas(), "");
        CHECKS(s1.pavarde(), "");
        CHECK(s1.pazymiai().size(), 0);
        CHECK(s1.egzaminas(), 0);
        CHECK(s1.galutinis(), 0);
        CHECK(s1.mediana(), 0);
    }

    void testInputConstructor() {
        test_cin("Petras Petraitis 8 10 6 4 2");
        studentas s2(std::cin);
        CHECKS(s2.vardas(), "Petras");
        CHECKS(s2.pavarde(), "Petraitis");
        CHECK(s2.pazymiai().size(), 4);
        CHECK(s2.pazymiai()[0], 8);
        CHECK(s2.egzaminas(), 2);
        CHECK(s2.galutinis(), 4.0);
        CHECK(s2.mediana(), 4.0);
    }

    void testCopyConstructor() {
        test_cin("Petras Petraitis 8 10 6 4 2");
        studentas s2(std::cin);
        studentas s3(s2);
        CHECKS(s3.vardas(), "Petras");
        CHECKS(s3.pavarde(), "Petraitis");
        CHECK(s3.pazymiai().size(), 4);
        CHECK(s3.pazymiai()[0], 8);
        CHECK(s3.egzaminas(), 2);
        CHECK(s3.galutinis(), 4.0);
        CHECK(s3.mediana(), 4.0);
    }

    void testMoveConstructor() {
        test_cin("Petras Petraitis 8 10 6 4 2");
        studentas s2(std::cin);
        studentas s4(std::move(s2));
        CHECKS(s4.vardas(), "Petras");
        CHECKS(s4.pavarde(), "Petraitis");
        CHECK(s4.pazymiai().size(), 4);
        CHECK(s4.pazymiai()[0], 8);
        CHECK(s4.egzaminas(), 2);
        CHECK(s4.galutinis(), 4.0);
        CHECK(s4.mediana(), 4.0);
    }

    void testCopyAssignment() {
        test_cin("Petras Petraitis 8 10 6 4 2");
        studentas s2(std::cin);
        studentas s5;
        s5 = s2;
        CHECKS(s5.vardas(), "Petras");
        CHECKS(s5.pavarde(), "Petraitis");
        CHECK(s5.pazymiai().size(), 4);
        CHECK(s5.pazymiai()[0], 8);
        CHECK(s5.egzaminas(), 2);
        CHECK(s5.galutinis(), 4.0);
        CHECK(s5.mediana(), 4.0);
    }

    void testMoveAssignment() {
        test_cin("Petras Petraitis 8 10 6 4 2");
        studentas s2(std::cin);
        studentas s6;
        s6 = std::move(s2);
        CHECKS(s6.vardas(), "Petras");
        CHECKS(s6.pavarde(), "Petraitis");
        CHECK(s6.pazymiai().size(), 4);
        CHECK(s6.pazymiai()[0], 8);
        CHECK(s6.egzaminas(), 2);
        CHECK(s6.galutinis(), 4.0);
        CHECK(s6.mediana(), 4.0);
    }

    void testInputOperator() {
        test_cin("Jonas Jonaitis 10 8 6 4 2");
        studentas s7(std::cin);
        CHECKS(s7.vardas(), "Jonas");
        CHECKS(s7.pavarde(), "Jonaitis");
        CHECK(s7.pazymiai().size(), 4);
        CHECK(s7.pazymiai()[0], 10);
        CHECK(s7.egzaminas(), 2);
        CHECK(s7.galutinis(), 4.0);
        CHECK(s7.mediana(), 4.0);
    }

    void test_list() override {
        testDefaultConstructor();
        testInputConstructor();
        testCopyConstructor();
        testMoveConstructor();
        testCopyAssignment();
        testMoveAssignment();
        testInputOperator();
    }
};

int main(int argc, char *argv[]) {
    return (new StudentasTests)->run();
}