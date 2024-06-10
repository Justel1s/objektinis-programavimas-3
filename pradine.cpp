#include "studentai.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    Vector<studentas> v;
    while(true)
    {
        int variantas;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti is failo, 5 - baigti darba, 6 - generuoti failus\n";

        while(!(cin>> variantas) || variantas < 1 || variantas > 6)
        {
			try{
				throw runtime_error("Netinkamas ivestis\n");
			}
			catch (const runtime_error &e){
			    cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << e.what();
				cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti is failo, 5 - baigti darba, 6 - generuoti failus\n";
			}
        }

        studentas s;

        if(variantas == 1)
        {
            vardoSkaitymas(s);
            pazymiuSkaitymas(s);
        }
        if(variantas == 2)
        {
            vardoSkaitymas(s);
            generuoti_pazymius(rand()%10, s);
            generuoti_egzamina(s);
        }
        if(variantas == 3)
        {
            generuoti_varda(s);
            generuoti_pazymius(rand()%10, s);
            generuoti_egzamina(s);
        }
        if(variantas == 4)
        {
            do{
                try{
                    cout << "Koki faila norite skaityti?\n";
                    string failas;
                    cin >> failas;
                    ifstream fd(failas);
                    if(!fd.good()) throw runtime_error("Netinkama ivestis");
                    failoSkaitymas(fd, v);
                    fd.close();
                    break;
                }
                catch(const std::exception& e){
                    cout << "Netinkama ivestis. Failas neegzistuoja. \n";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            }
            while(true);
        }
        if(variantas == 5) break;
		if(variantas == 6){
			uzd4(1000, "studentai1000.txt");
			uzd4(10000, "studentai10000.txt");
			uzd4(100000, "studentai100000.txt");
			uzd4(1000000, "studentai1000000.txt");
			uzd4(10000000, "studentai10000000.txt");
			continue;
		}
        baloSkaiciavimas(s);
        v.push_back(s);
    }
    rusiavimas(v);
    spausdinimas(v);

    return 0;
}
