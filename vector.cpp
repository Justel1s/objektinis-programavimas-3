#include <bits/stdc++.h>
#include "studentai.h"
using namespace std;

int main() {
    srand(time(nullptr));
    vector<studentas> D;

    test();
    int variantas;

    while (true) {
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus/pavardes, 4 - skaityti is failo, 5 - generuoti failus, 6 - baigti\n";
        if (!(cin >> variantas) || variantas < 1 || variantas > 6) {
            cout << "Netinkama ivestis\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (variantas == 5) {
            vector<int> sizes = {1000};
            for (int size : sizes) {
                paskutine(size, "studentai" + to_string(size) + ".txt");
            }
            continue;
        }
        if (variantas == 6) break;
        
        studentas s;

        if (variantas == 1 || variantas == 2) {
            vardo_skaitymas(s);
            if (variantas == 1) {
                pazymio_skaitymas(s);
            } else {
                generuoti_pazymius(rand() % 10, s);
                generuoti_egzamina(s);
            }
        } else if (variantas == 3) {
            generuoti_varda(s);
            generuoti_pazymius(rand() % 10, s);
            generuoti_egzamina(s);
        }
        balo_skaiciavimas(s);
        D.push_back(s);
    }
    rusiavimas(D);
    spausdinimas(D);
    return 0;
}
