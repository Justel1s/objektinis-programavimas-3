# ObjektinisProgramavimas v3.0

Programa skirta skaičiuoti galutinį balą pagal įvestus duomenis ar duomenų failus.

## Funkcionalumas

- Įvedimo langas, kuriame vartotojas įveda studento vardą, pavardę, namų darbų pažymius ir egzamino rezultatą.
- Galutinio balo skaičiavimas pagal vidurkį ar medianą.
- Išvedimo langas, kuriame pateikiami studentų galutiniai balai.

## Releasų istorija

- V.pradine: Sukurta preliminari programa, kurioje vartotojui įvedus studentų kiekį ir studentų duomenis (vardą, pavardę, pažymius) apskaičiuoja ir atspausdina studento duomenis su galutiniu rezultatu ir mediana.
- V0.1: Programa papildyta taip, kad iš anksto nėra žinomas nei namų darbų kiekis, nei mokinių. Pridėta galimybė, jog mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai. Programa suskirstyta į du failus: Masyvai.cpp ir Vektoriai.cpp. Masyvai.cpp faile duomenys yra saugomi C masyve, o Vektoriai.cpp faile std::vector konteineryje. Sukurtas meniu.
- V0.2: Pridėta galimybė nuskaityti duomenis iš failo ir patobulintas atspausdinimo metodas.
- V0.3: Struktūros perkeltos į atraštinius failus, o funkcijos į atskirą funkcijų failą. Pridėtas išimčių valdymas.
- V0.4: Sukurta failų generatoriaus funkcija. Studentai surūšiuojami į dvi kategorijas pagal pažymius ir išvedami į du naujus failus. Atlikta programos veikimo greičio analizė.
- V1.0: Atliktas konteinerių testavimas su vector, list ir deque konteineriais. Atliktas konteinerių skaidymo į dvi dalis testavimas. 	
- V1.1: Imlementuotos klasės, atliktas programos veikimo greičio testavimas
- V1.2: Klasė implementuota pagal rule of 5 taisyklę, perdengti operatoriai.
- V1.5: Sukurta abstrakti žmogaus klasė iš kurios kuriama išvestinė žmogaus klasė. Klasė implementuota pagal rule of 5 taisyklę, perdengti operatoriai.
- V2.0: Sukurta dokumentacija naudojant doxygen ir sukurti unit testai
- V3.0: Sukurta nauja Vector konteinerio realizacija, kurti testai, dokumentacija, pkg failas.

## Testavimo sistemos parametrai

MACBOOK AIR M1 8GB

## Vector realizacijų testavimo laikai (5 kartų vidurkis)

#### Vector
|  |Konteinerio užpildymo laikas| 
| :--- | ---- | 
| (int)10000 | 0 ms |
| (int)100000 | 2000 ms |
| (int)1000000 | 35400 ms | 
| (int)10000000 | 342203 ms |
| (int)100000000 | 3394862 ms |


#### Vector 2 (Mano realizacija)
|  |Konteinerio užpildymo laikas| 
| :--- | ---- | 
| (int)10000 | 2000 ms |
| (int)100000 | 0 ms |
| (int)1000000 | 32801 ms | 
| (int)10000000 | 348807 ms |
| (int)100000000 | 3356863 ms |

#### Resize skaičius

|  |std::vector| Vector|
| :--- | ---- | ---- | 
| (int)100000000 | 27 | 27 |


## Programos testavimo laikai (5 kartų vidurkis)

      
#### Vector
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai100000 | 582 ms | 80 ms | 20 ms | 1184 ms |
| studentai1000000 | 5764 ms | 1024 ms | 310 ms | 11596 ms |
| studentai10000000 | 67899 ms | 32012 ms | 9921 ms | 80432 ms |

#### Vector 2 (Mano realizacija)
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai100000 | 562 ms | 80 ms | 30 ms | 1180 ms |
| studentai1000000 | 5672 ms | 1056 ms | 330 ms | 11594 ms |
| studentai10000000 | 67890 ms | 32010 ms | 8951 ms | 79401 ms |

