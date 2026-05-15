
## Funkcijos 
 
1. `Push_back` Prideda elementą į vektoriaus pabaigą. Jei vidinis masyvas pilnas, automatiškai padidinama talpa (reserve).
2. `operator==` Palygina du vektorius. Grąžina true, jei jų dydžiai ir visi elementai sutampa.
3. `erase` Pašalina elementą iš nurodytos pozicijos ir perstumia likusius elementus į kairę.
4. `reserve` Padidina talpą, jei new_cap yra didesnė nei dabartinė.
5. `resize` Pakeičia vektoriaus dydį. Jei naujas dydis didesnis nei dabartinė talpa, atliekamas reallocate

<img width="495" height="380" alt="image" src="https://github.com/user-attachments/assets/243f9267-b694-4414-a1a4-39f89ef996ce" />

## Vector 
Išmatuotas failų rūšiavimas (s).
| 100k įrašų | 1M įrašų | 10M įrašų |
|---|---|---|
| 0,03 | 0,3 | 16,8 |
| 0,04 | 0,5 | 15,5 |
| 0,03 | 0,4 | 12,7 |

## std::vector
| 100k įrašų | 1M įrašų | 10M įrašų |
|---|---|---|
| 0,02 | 0,2 | 11,8 |
| 0,03 | 0,3 | 9,3 |
| 0,03 | 0,3 | 5,5 |


## Vector klasės ir std::vector greičio palyginimas
<img width="422" height="221" alt="Screenshot 2026-05-15 180453" src="https://github.com/user-attachments/assets/71f8226a-6508-40cb-bfa8-d45d8d3d1bf8" />

Laikai stipriai nesiskiria tarp šių konteinerių. Didesnį skirtumą galima įžvelgi su 100M elementų.
