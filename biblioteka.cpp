#include "biblioteka.h"

using namespace std;

studentas::studentas(std::istream& ss)
{
    ss >> vardas_ >> pavarde_;
    int x;
    while(ss >> x)
    {
        pazymiai_.push_back(x);
    }
    egzaminas_ = pazymiai_.back();
    pazymiai_.pop_back();
    baloSkaiciavimas(*this);
}

string studentas::spausdinti_elementus()
{
    stringstream a;
    a  << left << fixed << setprecision(2) << setw(18) << pavarde_ << setw(18) << vardas_ << setw(19) << galutinis_ << setw(20) << mediana_ <<"\n";
    return a.str();
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


void baloSkaiciavimas(studentas &stud)
{
    Vector<int> pazymiai_ = stud.pazymiai();
    double galutinis_, mediana_;
    if(pazymiai_.size())
    {
        int sum = accumulate(pazymiai_.begin(), pazymiai_.end(), 0);
        galutinis_ = 0.4 * sum/pazymiai_.size() + 0.6 * stud.egzaminas();
        sort(pazymiai_.begin(), pazymiai_.end());
        int vid = pazymiai_.size()/2;
        if (pazymiai_.size()%2)
        {
            mediana_ = pazymiai_[vid];
        }
        else
        {
            mediana_ = (pazymiai_[vid] + pazymiai_[vid - 1]) / 2.0;
        }
        mediana_ = 0.4*mediana_ + 0.6*stud.egzaminas();
    }
    else
    {
        galutinis_ = 0.6*stud.egzaminas();
        mediana_ = 0.6*stud.egzaminas();
    }
    stud.setGalutinis(galutinis_);
    stud.setMediana(mediana_);
}

void vardoSkaitymas(studentas &stud)
{
    string vardas_, pavarde_;
    cout << "Irasykite studento varda\n";
    while( !(cin >> vardas_) || yraint(vardas_) )
    {
        try
        {
            throw runtime_error("Netinkama ivestis. ");
        }
        catch(const runtime_error &e)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Iveskite varda be skaiciu\n";
            cout << "Irasykite studento varda\n";
        }
    };
    cout << "Irasykite studento pavarde\n";
    while( !(cin >> pavarde_) || yraint(pavarde_) )
    {
        try
        {
            throw runtime_error("Netinkama ivestis. ");
        }
        catch(const runtime_error &e)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Iveskite varda be skaiciu\nIrasykite studento pavarde\n";
        }
    };
    stud.setVardas(vardas_);
    stud.setPavarde(pavarde_);
}

void pazymiuSkaitymas(studentas &stud)
{
    Vector<int> pazymiai;
    int egzaminas_;
    while(true)
    {
        int x;
        cout << "Irasykite studento pazymi arba noredami uzbaigti iveskite -1\n";
        while(!(cin >> x) || x<1 || x>10)
        {
            if(x == -1) break;
            try
            {
                throw runtime_error("Netinkama ivestis. ");
            }
            catch(const runtime_error &e)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << e.what();
                cout << "Iveskite skaiciu nuo 1 iki 10\n";
            }
        }
        if(x == -1) break;
        pazymiai.push_back(x);
    }
    cout << "Irasykite studento egzamino pazymi\n";
    while(!(cin >> egzaminas_) || egzaminas_<1 || egzaminas_ > 10)
    {
        try
        {
            throw runtime_error("Netinkama ivestis. ");
        }
        catch(const runtime_error &e)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << e.what();
            cout << "Iveskite skaiciu nuo 1 iki 10\n";
        }
    }
    stud.setPazymiai(pazymiai);
    stud.setEgzaminas(egzaminas_);
}

void generuoti_varda(studentas &stud)
{
    string vardas, pavarde;
    for(int i=0; i<7; i++)
    {
        if(i==0) vardas += (char) (65 + rand()%25);
        else vardas += (char) (97 + rand()%25);
    }
    for(int i=0; i<13; i++)
    {
        if(i==0) pavarde += (char) (65 + rand()%25);
        else pavarde += (char) (97 + rand()%25);
    }
    stud.setVardas(vardas);
    stud.setPavarde(pavarde);
}

void generuoti_pazymius(int dydis, studentas &stud)
{
    Vector<int> pazymiai(dydis);
    for(int i=0; i<dydis; i++)
    {
        pazymiai[i] = rand()%10;
    }
    stud.setPazymiai(pazymiai);
}

void generuoti_egzamina(studentas &stud)
{
    stud.setEgzaminas(rand()%10);
};



template <typename Container>
void failoSkaitymas(ifstream &fd, Container &v)
{
    long long cnt = 0;
    string s;
    std::stringstream buffer;
    buffer << fd.rdbuf();
    if constexpr (std::is_same<Container, std::Vector<studentas>>::value)
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
template void failoSkaitymas<std::vector<studentas>>(std::ifstream &, std::vector<studentas> &);
template void failoSkaitymas<std::list<studentas>>(std::ifstream &, std::list<studentas> &);
template void failoSkaitymas<std::deque<studentas>>(std::ifstream &, std::deque<studentas> &);
template void failoSkaitymas<Vector<studentas>>(std::ifstream &, Vector<studentas> &);



void spausdinimas(Vector<studentas> &v)
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


bool yraint(string s)
{
    for(int i=0; i<s.size(); i++) if(isdigit(s[i])) return true;
    return false;
}

bool sortbyVardas(const studentas &a, const studentas &b)
{
    return (a.vardas() > b.vardas());
}
bool sortbyPavarde(const studentas &a, const studentas &b)
{
    return (a.pavarde() > b.pavarde());
}
bool sortbyGalutinis(const studentas &a, const studentas &b)
{
    return (a.galutinis() > b.galutinis());
}
bool sortbyMediana(const studentas &a, const studentas &b)
{
    return (a.mediana() > b.mediana());
}

void rusiavimas(Vector<studentas>& v)
{
    cout << "Pagal ka norite rusiuoti? 1 - vardas, 2 - pavarde, 3 - Galutinis vidurkis, 4 - Galutinis mediana, 5 - nerusiuoti\n";
    int variantas;
    while(!(cin>> variantas) || variantas < 1 || variantas > 5)
    {
        try
        {
            throw runtime_error("Netinkama ivestis\n");
        }
        catch(const runtime_error &e)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkama ivestis\n";
            cout << "1 - vardas, 2 - pavarde, 3 - Galutinis vidurkis, 4 - Galutinis mediana\n";
        }

    }
    if(variantas == 1) sort(v.begin(), v.end(), sortbyVardas);
    if(variantas == 2) sort(v.begin(), v.end(), sortbyPavarde);
    if(variantas == 3) sort(v.begin(), v.end(), sortbyGalutinis);
    if(variantas == 4) sort(v.begin(), v.end(), sortbyMediana);
    return;
}

void failoGeneravimas(int dydis, string pavadinimas)
{
    auto start = chrono::high_resolution_clock::now();
    stringstream buf;
    buf << left << setw(30) << "Vardas" << setw(30) << "Pavarde";
    for(int i=1; i<=10; i++)
    {
        buf << "ND" << setw(4) << i;
    }
    buf << "Egz.\n";
    for(int i=1; i<=dydis; i++)
    {
        buf <<  "Vardas"  << setw(24) << i << "Pavarde"  << setw(23) << i;
        for(int j=0; j<11; j++)
        {
            buf << setw(6) << rand()%10;
        }
        if(i!=dydis)
            buf << "\n";
    }
    ofstream fr(pavadinimas);
    fr << buf.rdbuf();
    fr.close();
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Sugeneruotas " << pavadinimas << " failas per: " << diff.count() << " ms\n";
}


bool compareByGalutinis(const double b, const studentas& a)
{
    return a.galutinis() < b;
}

bool compareByMediana(const double b, const studentas& a)
{
    return a.mediana() < b;
}


template <typename Container>
void spausdinimasFaila(Container &v, string pavadinimas)
{
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


template <typename Container>
void Skirstymas(Container &a, Container &b, int x)
{
    auto start = chrono::high_resolution_clock::now();

    typename Container::iterator vieta;
    if(x==1)
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(a.begin(), a.end(), 5.0, compareByMediana);

    if constexpr (is_same<Container, list<studentas>>::value)
    {
        b.splice(b.begin(), a, vieta, a.end());
    }
    else
    {
        b.insert(b.begin(), vieta, a.end());
        a.erase(vieta, a.end());
    }

    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Strategija4 Paskirstyti pirmunai ir vargsai per: " << diff.count() << " ms\n";
}


template <typename Container>
void laikoSkaiciavimasStrukturos(ifstream &fd)
{
    auto visasLaikas = chrono::high_resolution_clock::now();

    auto start = chrono::high_resolution_clock::now();
    Container pirmunai, vargsai;
    failoSkaitymas(fd, pirmunai);
    fd.close();
    auto end = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Failas perskaitytas per: " << diff.count() << " ms\n";


    auto rinkLaikas = chrono::high_resolution_clock::now();
    int x = 0;
    auto rinkLaikasPab = chrono::high_resolution_clock::now();
    auto rinkLaikasdiff = chrono::duration_cast<chrono::milliseconds>(rinkLaikasPab - rinkLaikas);


    start = chrono::high_resolution_clock::now();
    if constexpr (std::is_same<Container, std::list<studentas>>::value)
    {
        if(x==1)
            pirmunai.sort(sortbyGalutinis);
        else
            pirmunai.sort(sortbyMediana);
    }
    else
    {
        if(x==1)
            sort(pirmunai.begin(), pirmunai.end(), sortbyGalutinis);
        else
            sort(pirmunai.begin(), pirmunai.end(), sortbyMediana);
    }

    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Surikiuoti studentai per: " << diff.count() << " ms\n";


    Skirstymas(pirmunai, vargsai, x);

    start = chrono::high_resolution_clock::now();
    spausdinimasFaila(pirmunai, "pirmunai.txt");
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Isspausdintas pirmunu failas per: " << diff.count() << " ms\n";

    start = chrono::high_resolution_clock::now();
    spausdinimasFaila(vargsai, "vargsai.txt");
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Isspausdintas vargsu failas per: " << diff.count() << " ms\n";


    auto visasLaikasPab = chrono::high_resolution_clock::now();
    auto visasLaikasdiff = chrono::duration_cast<chrono::milliseconds>(visasLaikasPab - visasLaikas);
    cout << "Visas programos veikimo laikas: " << visasLaikasdiff.count() - rinkLaikasdiff.count() << " ms\n";
}

void uzd4(int dydis, string pavadinimas)
{
    cout << "\n" << pavadinimas.substr(0, pavadinimas.size()-4) << "\n";

	failoGeneravimas(dydis, pavadinimas);

    cout << "\n\nVector\n";
    ifstream fd(pavadinimas);
    laikoSkaiciavimasStrukturos<Vector<studentas>>(fd);
    fd.close();

    cout << "\n\nVECTOR2\n";
    fd.open(pavadinimas);
    laikoSkaiciavimasStrukturos<Vector<studentas>>(fd);
    fd.close();

    cout << "\n\nList\n";
    fd.open(pavadinimas);
    laikoSkaiciavimasStrukturos<list<studentas>>(fd);
    fd.close();

    cout << "\n\nDeque\n";
    fd.open(pavadinimas);
    laikoSkaiciavimasStrukturos<deque<studentas>>(fd);
    fd.close();


    return;
}

