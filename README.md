# ObjektinisProgramavimas v2.0

Programa skirta skaičiuoti galutinį balą pagal įvestus duomenis ar duomenų failus.

## Funkcionalumas

- Įvedimo langas, kuriame vartotojas įveda studento vardą, pavardę, namų darbų pažymius ir egzamino rezultatą.
- Galutinio balo skaičiavimas pagal vidurkį ar medianą.
- Išvedimo langas, kuriame pateikiami studentų galutiniai balai.

## Releasų istorija

- **V.pradine**: Sukurta preliminari programa, kurioje vartotojui įvedus studentų kiekį ir studentų duomenis (vardą, pavardę, pažymius) apskaičiuoja ir atspausdina studento duomenis su galutiniu rezultatu ir mediana. 
- **V0.1**: Programa papildyta taip, kad iš anksto nėra žinomas nei namų darbų kiekis, nei mokinių. Pridėta galimybė, jog mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai.
- **V0.2**: Pridėta galimybė nuskaityti duomenis iš failo ir patobulintas atspausdinimo metodas.
- **V0.3**: Struktūros perkeltos į atraštinius failus, o funkcijos į atskirą funkcijų failą. Pridėtas išimčių valdymas.
- **V0.4**: Sukurta failų generatoriaus funkcija. Studentai surūšiuojami į dvi kategorijas pagal pažymius ir išvedami į du naujus failus. Atlikta programos veikimo greičio analizė.
- **V1.0**: Atliktas konteinerių testavimas su vector, list ir deque konteineriais. Atliktas konteinerių skaidymo į dvi dalis testavimas. 
- **V1.1**: Į kodą integruotos klasės.
- **V1.2**: Klasė implementuota pagal rule of 5 taisyklę, perdengti operatoriai.
- **V1.5**: Sukurta abstrakti žmogaus klasė iš kurios kuriama išvestinė žmogaus klasė. Klasė implementuota pagal rule of 5 taisyklę, perdengti operatoriai.
- **V2.0**: Sukurta dokumentacija naudojant doxygen ir sukurti unit testai

## Perdengtų operatorių veikimo principas

Duomenų įvestis gali būti vykdoma rankiniu būdu, automatiniu būdu arba iš failo, o išvestis gali būti vykdoma į ekraną arba į failą.
Mano programoje tai įvykdoma perdengtais operatoriais << ir >> 
Norint išspausdiniti į ekraną naudojame "cout <<" o išspausdinti į failą  "ofstream <<"
Analogiškai perskaityti rankiniu būdu "cin >>" o automatiniu iš failo "ifstream >>"

## Testavimo sistemos parametrai

CPU: 5th Gen Intel(R) Core(TM) i5-8365U 1.60GHz
RAM: 16GB - DDR4 - 2666MHz
HDD: SSD - 236GB

## Programos testavimo laikai (5 kartų vidurkis)

#### Vector
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 20 ms | 0 ms | 0 ms | 50 ms |
| studentai10000 | 110 ms | 30 ms | 0 ms | 190 ms |
| studentai100000 | 1064 ms | 432 ms | 40 ms | 2236 ms |
| studentai1000000 | 10889 ms | 5516 ms | 432 ms | 21202 ms |
| studentai10000000 | 162431 ms | 72118 ms | 13353 ms | 320132 ms |

#### List
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 10 ms | 0 ms | 0 ms | 40 ms |
| studentai10000 | 100 ms | 20 ms | 0 ms | 170 ms |
| studentai100000 | 1074 ms | 182 ms | 42 ms | 1769 ms |
| studentai1000000 | 10553 ms | 2468 ms | 375 ms | 18227 ms |
| studentai10000000 | 130665 ms | 35536 ms | 3900 ms | 224437 ms |

#### Deque
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 18 ms | 3 ms | 1 ms | 32 ms |
| studentai10000 | 100 ms | 40 ms | 2 ms | 190 ms |
| studentai100000 | 1046 ms | 530 ms | 45 ms | 2062 ms |
| studentai1000000 | 10344 ms | 6709 ms | 496 ms | 22012 ms |
| studentai10000000 | 118809 ms | 83116 ms | 8002 ms | 293108 ms |


## Programos diegimas ir paleidimas

Būtina turėti MinGW ir make instaliuotą kompiuteryje. 
Norint įdiegti ir paleisti programą naudojant Make, atlikite šiuos veiksmus:

1. Atsisiųskite programos šaltinio kodą iš repozitorijos.
2. Naviguokite į atsisiųstą programos aplanką naudodami terminalą.
3. Įvykdykite komandą make.
4. Paleiskite programą terminale naudodami komandą ./1uzd (Linux) arba 1uzd.exe (Windows) 

## Kaip naudotis

1. Paleisti programą.
2. Sekti ekrane esamus nurodymus.
3. Gauti studentų galutinius balus.
