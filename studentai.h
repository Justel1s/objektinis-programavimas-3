#ifndef studentai_h
#define studentai_h
#include <bits/stdc++.h>
using namespace std;

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
        // string vardas_;
        // string pavarde_;
        vector<int> pazymiai_;
        int egzaminas_ = 0;
        double galutinis_ = 0, mediana_ = 0;
    public:
        studentas() = default;
        studentas(std::istream& is);
        ~studentas() = default;

        studentas(const studentas& other)
            : vardas_(other.vardas_), pavarde_(other.pavarde_), pazymiai_(other.pazymiai_),
              egzaminas_(other.egzaminas_), galutinis_(other.galutinis_), mediana_(other.mediana_) {}

        studentas(studentas&& other) noexcept
            : vardas_(move(other.vardas_)), pavarde_(move(other.pavarde_)),
              pazymiai_(move(other.pazymiai_)), egzaminas_(other.egzaminas_),
              galutinis_(other.galutinis_), mediana_(other.mediana_) {}

        studentas& operator=(const studentas& other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            pazymiai_ = other.pazymiai_;
            egzaminas_ = other.egzaminas_;
            galutinis_ = other.galutinis_;
            mediana_ = other.mediana_;
            return *this;
        }

        studentas& operator=(studentas&& other) noexcept {
            vardas_ = move(other.vardas_);
            pavarde_ = move(other.pavarde_);
            pazymiai_ = move(other.pazymiai_);
            egzaminas_ = other.egzaminas_;
            galutinis_ = other.galutinis_;
            mediana_ = other.mediana_;
            return *this;
        }

        inline std::string vardas() const { return vardas_; }
        inline std::string pavarde() const { return pavarde_; }
        inline std::vector<int> pazymiai() const { return pazymiai_; }
        inline int egzaminas() const { return egzaminas_; }
        inline double galutinis() const { return galutinis_; }
        inline double mediana() const { return mediana_; }

        inline void setVardas(const std::string& vardas) { vardas_ = vardas; }
        inline void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
        inline void setPazymiai(const std::vector<int>& pazymiai) { pazymiai_ = pazymiai; }
        inline void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
        inline void setGalutinis(double galutinis) { galutinis_ = galutinis; }
        inline void setMediana(double mediana) { mediana_ = mediana; }

        std::string spausdinti_elementus();

        friend std::istream& operator>>(std::istream& is, studentas& s);
        friend std::ostream& operator<<(std::ostream& os, const studentas& s);

};

void balo_skaiciavimas(studentas &);
void vardo_skaitymas(studentas &);
void pazymio_skaitymas(studentas &);
void generuoti_varda(studentas &);
void generuoti_pazymius(int, studentas &);
void generuoti_egzamina(studentas &);
void test();

bool rikiavimas_vardas(const studentas &, const studentas &);
bool rikiavimas_pavarde(const studentas &, const studentas &);
bool rikiavimas_galutinis(const studentas &, const studentas &);
bool rikiavimas_mediana(const studentas &, const studentas &);
bool compareByGalutinis(const double b, const studentas& a);
bool compareByMediana(const double b, const studentas& a);

template <typename Container>
void failo_skaitymas(std::ifstream &, Container&);
void failo_generavimas(int, std::string);
void spausdinimas(std::vector<studentas> &);
void rusiavimas(std::vector<studentas>&);
void paskutine(int, std::string); 

#endif
