#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

// #include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <sstream>
#include <numeric>
#include <fstream>
#include <list>
#include <stack>
#include <vector>
#include "vector.h"

class zmogus{
    protected:
        std::string vardas_;
        std::string pavarde_;
    public:
        virtual void setVardas(const std::string& vardas) = 0;
        virtual void setPavarde(const std::string& pavarde) = 0;
        virtual std::string vardas() const = 0;
        virtual std::string pavarde() const = 0;

    zmogus(){}
    virtual ~zmogus() = default; // I. destructor

    zmogus(const zmogus& other)     // II. copy constructor
        : vardas_(other.vardas_), pavarde_(other.pavarde_) {}

    zmogus(zmogus&& other) noexcept     // III. move constructor
        : vardas_(std::move(other.vardas_)), pavarde_(std::move(other.pavarde_)) {}

    zmogus& operator=(const zmogus& other) { // IV. copy assignment
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
        }
        return *this;
    }

    zmogus& operator=(zmogus&& other) noexcept { // V. move assignment
        if (this != &other) {
            vardas_ = std::move(other.vardas_);
            pavarde_ = std::move(other.pavarde_);
        }
        return *this;
    }
};


class studentas : public zmogus{
    private:
    //    std::string vardas_;
    //    std::string pavarde_;
        std::Vector<int> pazymiai_;
        int egzaminas_;
        double galutinis_, mediana_;
    public:
        studentas() : egzaminas_(0), galutinis_(0), mediana_(0) {}
        studentas(std::istream& is);
        virtual ~studentas() {} // I. destructor

        studentas(const studentas& other) // II. copy constructor
            : zmogus(other), pazymiai_(other.pazymiai_),
              egzaminas_(other.egzaminas_), galutinis_(other.galutinis_), mediana_(other.mediana_) {}

        studentas(studentas&& other) noexcept // III. move constructor
            : zmogus(std::move(other)),
              pazymiai_(std::move(other.pazymiai_)), egzaminas_(other.egzaminas_),
              galutinis_(other.galutinis_), mediana_(other.mediana_) {
                other.egzaminas_ = NULL;
                other.galutinis_ = NULL;
                other.mediana_ = NULL;
                }

        studentas& operator=(const studentas& other) { // IV. copy assignment
            zmogus::operator=(other);
            pazymiai_ = other.pazymiai_;
            egzaminas_ = other.egzaminas_;
            galutinis_ = other.galutinis_;
            mediana_ = other.mediana_;
            return *this;
        }

        studentas& operator=(studentas&& other) noexcept { // V. move assignment
            zmogus::operator=(std::move(other));
            pazymiai_ = std::move(other.pazymiai_);
            egzaminas_ = other.egzaminas_;
            galutinis_ = other.galutinis_;
            mediana_ = other.mediana_;
            other.egzaminas_ = NULL;
            other.galutinis_ = NULL;
            other.mediana_ = NULL;
            return *this;
        }

        inline std::string vardas() const override { return vardas_; }
        inline std::string pavarde() const override { return pavarde_; }
        inline std::Vector<int> pazymiai() const { return pazymiai_; }
        inline int egzaminas() const { return egzaminas_; }
        inline double galutinis() const { return galutinis_; }
        inline double mediana() const { return mediana_; }

        inline void setVardas(const std::string& vardas) override { vardas_ = vardas; }
        inline void setPavarde(const std::string& pavarde) override { pavarde_ = pavarde; }
        inline void setPazymiai(const std::Vector<int>& pazymiai) { pazymiai_ = pazymiai; }
        inline void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
        inline void setGalutinis(double galutinis) { galutinis_ = galutinis; }
        inline void setMediana(double mediana) { mediana_ = mediana; }

        std::string spausdinti_elementus();

        friend std::istream& operator>>(std::istream& is, studentas& s);
        friend std::ostream& operator<<(std::ostream& os, const studentas& s);
};

void baloSkaiciavimas(studentas &);
void vardoSkaitymas(studentas &);
void pazymiuSkaitymas(studentas &);
void generuoti_varda(studentas &);
void generuoti_pazymius(int, studentas &);
void generuoti_egzamina(studentas &);
void test();

bool sortbyVardas(const studentas &, const studentas &);
bool sortbyPavarde(const studentas &, const studentas &);
bool sortbyGalutinis(const studentas &, const studentas &);
bool sortbyMediana(const studentas &, const studentas &);
bool compareByGalutinis(const double b, const studentas& a);
bool compareByMediana(const double b, const studentas& a);

template <typename Container>
void failoSkaitymas(std::ifstream &, Container&);
void failoGeneravimas(int, std::string);
bool yraint(std::string);
void spausdinimas(std::Vector<studentas> &);
void rusiavimas(std::Vector<studentas>&);
void uzd4(int, std::string);

#endif
