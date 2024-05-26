#include <bits/stdc++.h>
#include "studentai.h"
using namespace std;

//Rikiavimas
bool compareByGalutinis(const double b, const studentas &a) { return a.galutinis() < b; }
bool compareByMediana(const double b, const studentas &a) { return a.mediana() < b; }
//Generavimas
studentas::studentas(std::istream& r)
{
    r >> vardas_ >> pavarde_;
    int x;
    while(r >> x)
    {
        pazymiai_.push_back(x);
    }
    egzaminas_ = pazymiai_.back();
    pazymiai_.pop_back();
    balo_skaiciavimas(*this);
}
void generuoti_varda(studentas &stud) {
    string vardas, pavarde;
    for (int i = 0; i < 7; i++) {
        if (i == 0)
            vardas += (char)(65 + rand() % 25);
        else
            vardas += (char)(97 + rand() % 25);
    }
    for(int i = 0; i < 13; i++)
    {
        if(i==0) 
            pavarde += (char) (65 + rand() % 25);
        else 
            pavarde += (char) (97 + rand() % 25);
    }
}
void generuoti_pazymius(int dydis, studentas &stud) {
    vector<int> pazymiai(dydis);
    for (int i = 0; i < dydis; i++) {
        pazymiai[i] = rand() % 10;
    }
    stud.setPazymiai(pazymiai);
}

void generuoti_egzamina(studentas &stud) {
    stud.setEgzaminas(rand()%10);
};

void vardo_skaitymas(studentas &stud) {
    string vardas_, pavarde_;
    cout << "Irasykite studento varda\n";
    while (!(cin >> vardas_)) {
        try {
            throw runtime_error("Netinkama ivestis");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Irasykite studento varda\n";
        }
    };
    cout << "Irasykite studento pavarde\n";
    while (!(cin >> pavarde_)) {
        try {
            throw runtime_error("Netinkama ivestis");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Irasykite studento pavarde\n";
        }
    };
    stud.setVardas(vardas_);
    stud.setPavarde(pavarde_);
}

void pazymio_skaitymas(studentas &stud) {
    vector<int> pazymiai;
    int egzaminas_;
    while (true) {
        int kintamasis;
        cout << "Irasykite studento pazymi arba noredami uzbaigti iveskite -1\n";
        while (!(cin >> kintamasis) || kintamasis < 1 || kintamasis > 10) {
            if (kintamasis == -1) break;
            try {
                throw runtime_error("Netinkama ivestis");
            } catch (const runtime_error &e) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << e.what();
                cout << "Iveskite skaiciu nuo 1 iki 10\n";
            }
        }
        if (kintamasis == -1) break;
        pazymiai.push_back(kintamasis);
    }
    cout << "Irasykite studento egzamino pazymi\n";
    while (!(cin >> egzaminas_) || egzaminas_ < 1 || egzaminas_ > 10) {
        try {
            throw runtime_error("Netinkama ivestis");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Iveskite skaiciu [1-10]\n";
        }
    }
    stud.setPazymiai(pazymiai);
    stud.setEgzaminas(egzaminas_);
}

void balo_skaiciavimas(studentas &stud) {
    vector<int> pazymiai_ = stud.pazymiai();
    double galutinis_, mediana_;
    if (pazymiai_.size()) {
        int sum = accumulate(pazymiai_.begin(), pazymiai_.end(), 0);
        galutinis_ = 0.4 * sum / pazymiai_.size() + 0.6 * stud.egzaminas();
        sort(pazymiai_.begin(), pazymiai_.end());
        int vid = pazymiai_.size() / 2;
        if (pazymiai_.size() % 2) {
            mediana_ = pazymiai_[vid];
        } else {
            mediana_ = (pazymiai_[vid] + pazymiai_[vid - 1]) / 2.0;
        }
        mediana_ = 0.4 * mediana_ + 0.6 * stud.egzaminas();
    } else {
        galutinis_ = 0.6 * stud.egzaminas();
        mediana_ = 0.6 * stud.egzaminas();
    }
    stud.setGalutinis(galutinis_);
    stud.setMediana(mediana_);
}
// Spausdinimas
string studentas::spausdinti_elementus()
{
    stringstream a;
    a  << left << fixed << setprecision(2) << setw(18) << pavarde_ << setw(18) << vardas_ << setw(19) << galutinis_ << setw(20) << mediana_ <<"\n";
    return a.str();
}
void spausdinimas(vector<studentas> &v)
{
    stringstream spausdinimas;
    //Spausdinimas
    spausdinimas << left << setw(18)  << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 65;
    while(bruksneliai--) spausdinimas << '-';
    spausdinimas << "\n";

    for (auto &i:v)
    {
        spausdinimas << i.spausdinti_elementus();
    }
    cout << spausdinimas.rdbuf();
}
std::istream& operator>>(std::istream& is, studentas& s) {
    std::string line;
    std::getline(is, line);
    std::istringstream a(line);
    studentas temp(a);
    s = temp;
    return is;
}
std::ostream& operator<<(std::ostream& os, studentas& s) {
    os << s.spausdinti_elementus();
    return os;
}

bool rikiavimas_vardas(const studentas &a, const studentas &b) { return (a.vardas() > b.vardas()); }
bool rikiavimas_pavarde(const studentas &a, const studentas &b) { return (a.pavarde() > b.pavarde()); }
bool rikiavimas_galutinis(const studentas &a, const studentas &b) { return (a.galutinis() > b.galutinis()); }
bool rikiavimas_mediana(const studentas &a, const studentas &b) { return (a.mediana() > b.mediana()); }

// Template
template <typename Container>
void failo_skaitymas(ifstream &fd, Container &v)
{
    long long cnt = 0;
    string s;
    std::stringstream buffer;
    buffer << fd.rdbuf();
    if constexpr (std::is_same<Container, std::vector<studentas>>::value)
    {
        std::stringstream::pos_type pos = buffer.tellg();
        while(!buffer.eof())
        {
            getline(buffer, s);
            cnt++;
        }
        buffer.clear();
        buffer.seekg (pos, buffer.beg);
        v.reserve(cnt);
        cnt = 0;
    }
    while(getline(buffer, s))
    {
        if(s=="") continue;
        if(cnt)
        {
            istringstream ss(s);
            studentas stud(ss);
//            stud.readStudent(ss);
            v.push_back(stud);
        }
        cnt++;
    }
}
// Visi duomenu tipai
template void failo_skaitymas<std::vector<studentas>>(std::ifstream &, std::vector<studentas> &);
template void failo_skaitymas<std::list<studentas>>(std::ifstream &, std::list<studentas> &);
template void failo_skaitymas<std::deque<studentas>>(std::ifstream &, std::deque<studentas> &);

void rusiavimas(vector<studentas> &v) {
    cout << "1 - vardas, 2 - pavarde, 3 - galutinis_ vidurkis, 4 - galutinis_ mediana_\n";
    int variantas;
    while (!(cin >> variantas) || variantas < 1 || variantas > 5) {
        try {
            throw runtime_error("Netinkama ivestis\n");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkama ivestis\n";
            cout << "1 - vardas, 2 - pavarde, 3 - galutinis_ vidurkis, 4 - galutinis_ mediana_\n";
        }
    }
    if (variantas == 1) sort(v.begin(), v.end(), rikiavimas_vardas);
    if (variantas == 2) sort(v.begin(), v.end(), rikiavimas_pavarde);
    if (variantas == 3) sort(v.begin(), v.end(), rikiavimas_galutinis);
    if (variantas == 4) sort(v.begin(), v.end(), rikiavimas_mediana);
    return;
}

void failo_generavimas(int dydis, string pavadinimas) {
    auto start = chrono::high_resolution_clock::now();
    stringstream buf;
    buf << left << setw(30) << "Vardas" << setw(30) << "Pavarde";
    for (int i = 1; i <= 10; i++) {
        buf << "ND" << setw(4) << i;
    }
    buf << "Egz.\n";
    for (int i = 1; i <= dydis; i++) {
        buf << "Vardas" << setw(24) << i << "Pavarde" << setw(23) << i;
        for (int j = 0; j < 11; j++) {
            buf << setw(6) << rand() % 10;
        }
        if (i != dydis) buf << "\n";
    }
    ofstream fr(pavadinimas);
    fr << buf.rdbuf();
    fr.close();
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Sugeneruotas " << pavadinimas << " failas per: " << diff.count() << " ms\n";
}
//Spausdinimas
template <typename Container>
void failo_spausdinimas(Container &v, string pavadinimas) {
    stringstream spausdinimas;
    //Spausdinimas
    spausdinimas << left << setw(15)  << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while(bruksneliai--) spausdinimas << '-';
    spausdinimas << "\n";

    for (auto &i:v)
    {
        spausdinimas << i;
    }
    ofstream fr(pavadinimas);
    fr << spausdinimas.rdbuf();
    fr.close();
}
//Strategijos 
template <typename Container>
void Strategija1(Container &a, int kintamasis) {
    auto start = chrono::high_resolution_clock::now();

    typename Container::iterator vieta;
    if (kintamasis == 1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);

    Container b, c;

    b.insert(b.begin(), a.begin(), vieta);
    c.insert(c.begin(), vieta, a.end());

    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija1 pirmunai ir vargsai per: " << diff.count() << " ms\n";
}

template <typename Container>
void Strategija2(Container &a, Container &b, int kintamasis) {
    auto start = chrono::high_resolution_clock::now();

    typename Container::iterator vieta;
    if (kintamasis == 1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);

    b.insert(b.begin(), vieta, a.end());
    a.erase(vieta, a.end());

    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija2 pirmunai ir vargsai per: " << diff.count() << " ms\n";
}
template <typename Container>
void Strategija3(Container &a, Container &b, int kintamasis) {
    auto start = chrono::high_resolution_clock::now();

    typename Container::iterator vieta;
    if (kintamasis == 1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);
    std::copy(vieta, a.end(), std::back_inserter(b));
    a.erase(vieta, a.end());
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija3 pirmunai ir vargsai per: " << diff.count() << " ms\n";
}

template <typename Container>
void Strategija4(Container &a, Container &b, int kintamasis) {
    auto start = chrono::high_resolution_clock::now();
    typename Container::iterator vieta;
    if (kintamasis == 1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);

    if constexpr (is_same<Container, list<studentas>>::value) {
        b.splice(b.begin(), a, vieta, a.end());
    } else {
        b.assign(vieta, a.end());
        a.erase(vieta, a.end());
    }
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija4 pirmunai ir vargsai per: " << diff.count() << " ms\n";
}
//Laiko skaiciavimas
template <typename Container>
void laiko_skaiciavimas(ifstream &fd) {
    auto visasLaikas = chrono::high_resolution_clock::now();
    auto start = chrono::high_resolution_clock::now();
    Container pirmunai, vargsai;
    failo_skaitymas(fd, pirmunai);
    fd.close();
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Failas perskaitytas per: " << diff.count() << " ms\n";
    auto rinkLaikas = chrono::high_resolution_clock::now();
    int kintamasis = 0;
    cout << "Rusiuoti pagal 1 - galutinis_ vid., 2 - galutinis_ med.\n";
    while (!(cin >> kintamasis) && kintamasis > 2 && kintamasis < 1) {
        try {
            throw runtime_error("Netinkama ivestis\n");
        } catch (const runtime_error &e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Rusiuoti pagal 1 - galutinis_ vid., 2 - galutinis_ med.\n";
        }
    }
    auto rinkLaikasPab = chrono::high_resolution_clock::now();
    auto rinkLaikasdiff = chrono::duration_cast<chrono::milliseconds>(rinkLaikasPab - rinkLaikas);

    start = chrono::high_resolution_clock::now();
    if constexpr (std::is_same<Container, std::list<studentas>>::value) {
        if (kintamasis == 1)
            pirmunai.sort(rikiavimas_galutinis);
        else
            pirmunai.sort(rikiavimas_mediana);
    } else {
        if (kintamasis == 1)
            sort(pirmunai.begin(), pirmunai.end(), rikiavimas_galutinis);
        else
            sort(pirmunai.begin(), pirmunai.end(), rikiavimas_mediana);
    }

    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Surikiuoti studentai per: " << diff.count() << " ms\n";

    Strategija1(pirmunai, kintamasis);
    Strategija2(pirmunai, vargsai, kintamasis);
    Strategija3(pirmunai, vargsai, kintamasis);
    Strategija4(pirmunai, vargsai, kintamasis);

    start = chrono::high_resolution_clock::now();
    failo_spausdinimas(pirmunai, "pirmunai.txt");
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Isspausdintas pirmunu failas per: " << diff.count() << " ms\n";

    start = chrono::high_resolution_clock::now();
    failo_spausdinimas(vargsai, "vargsai.txt");
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Isspausdintas vargsu failas per: " << diff.count() << " ms\n";

    auto visasLaikasPab = chrono::high_resolution_clock::now();
    auto visasLaikasdiff = chrono::duration_cast<chrono::milliseconds>(visasLaikasPab - visasLaikas);
    cout << "Visas programos veikimo laikas: " << visasLaikasdiff.count() - rinkLaikasdiff.count() << " ms\n";
}
//Paskutinei daliai
void paskutine(int dydis, string pavadinimas) {
    cout << "\n" << pavadinimas.substr(0, pavadinimas.size() - 4) << "\n";

    failo_generavimas(dydis, pavadinimas);

    cout << "\nVector\n";
    ifstream fd(pavadinimas);
    laiko_skaiciavimas<vector<studentas> >(fd);
    fd.close();

    cout << "\nList\n";
    fd.open(pavadinimas);
    laiko_skaiciavimas<list<studentas>>(fd);
    fd.close();

    cout << "\nDeque\n";
    fd.open(pavadinimas);
    laiko_skaiciavimas<deque<studentas>>(fd);
    fd.close();
    return;
}

void test() {
    // Test default constructor
    studentas s1;
    assert(s1.vardas().empty());
    assert(s1.pavarde().empty());
    assert(s1.pazymiai().empty());
    assert(s1.egzaminas() == 0);
    assert(s1.galutinis() == 0);
    assert(s1.mediana() == 0);

    // Test input constructor
    std::istringstream is("Petras Petraitis 8 10 6 4 2");
    studentas s2(is);
    assert(s2.vardas() == "Petras");
    assert(s2.pavarde() == "Petraitis");
    assert(s2.pazymiai().size() == 4);
    assert(s2.pazymiai()[0] == 8);
    assert(s2.egzaminas() == 2);
    assert(s2.galutinis() == 4.0);
    assert(s2.mediana() == 4.0);

    // Test copy constructor
    studentas s3(s2);
    assert(s3.vardas() == "Petras");
    assert(s3.pavarde() == "Petraitis");
    assert(s3.pazymiai().size() == 4);
    assert(s3.pazymiai()[0] == 8);
    assert(s3.egzaminas() == 2);
    assert(s3.galutinis() == 4.0);
    assert(s3.mediana() == 4.0);

    // Test move constructor
    studentas s4(std::move(s3));
    assert(s4.vardas() == "Petras");
    assert(s4.pavarde() == "Petraitis");
    assert(s4.pazymiai().size() == 4);
    assert(s4.pazymiai()[0] == 8);
    assert(s4.egzaminas() == 2);
    assert(s4.galutinis() == 4.0);
    assert(s4.mediana() == 4.0);

    // Test copy assignment
    studentas s5;
    s5 = s2;
    assert(s5.vardas() == "Petras");
    assert(s5.pavarde() == "Petraitis");
    assert(s5.pazymiai().size() == 4);
    assert(s5.pazymiai()[0] == 8);
    assert(s5.egzaminas() == 2);
    assert(s5.galutinis() == 4.0);
    assert(s5.mediana() == 4.0);

    // Test move assignment
    studentas s6;
    s6 = std::move(s4);
    assert(s6.vardas() == "Petras");
    assert(s6.pavarde() == "Petraitis");
    assert(s6.pazymiai().size() == 4);
    assert(s6.pazymiai()[0] == 8);
    assert(s6.egzaminas() == 2);
    assert(s6.galutinis() == 4.0);
    assert(s6.mediana() == 4.0);

    // Test output operator
    std::ostringstream os;
    os << s1;
    assert(!os.str().empty());

    // Test input operator
    std::istringstream is2("Jonas Jonaitis 10 8 6 4 2");
    is2 >> s1;
    assert(s1.vardas() == "Jonas");
    assert(s1.pavarde() == "Jonaitis");
    assert(s1.pazymiai().size() == 4);
    assert(s1.pazymiai()[0] == 10);
    assert(s1.egzaminas() == 2);
    assert(s1.galutinis() == 4.0);
    assert(s1.mediana() == 4.0);

    static_assert(std::is_abstract<zmogus>::value);

}