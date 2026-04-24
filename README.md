## Class 
<img width="470" height="243" alt="image" src="https://github.com/user-attachments/assets/aded8f90-b106-4260-ad94-29de478fbcd7" />


## Programos aprašymas
Ši programa turi galimybę nuskaityti duomenis įvestus vartotojo arba nuskaityti tiesiai iš failo bei generuoti savo duomenis.  Programoje yra realizuoti visi Rule of five operatoriai: copy constructor, move constructor, copy assignment, move assignment, destructor. Taip pat realizuoti ir įvesties bei išvesties operatoriai. Šioje programos versijoje programa jau naudoja klasę - **Žmogus** ir jos išvestinę klasę - **Studentas**.

## O1
| Konteineris | Strategija | 100k įrašų | 1M įrašų | exe failo dydis |
|---|---|---|---|---|
| Vector | 1 | 0,04 | 0,3 | 294 KB |
| Vector | 2 | 0,05 | 0,4 | 294 KB |
| Vector | 3 | 0,03 | 0,3 | 294 KB |

## O2

| Konteineris | Strategija | 100k įrašų | 1M įrašų | exe failo dydis |
|---|---|---|---|---|
| Vector | 1 | 0,03 | 0,3 | 280 KB |
| Vector | 2 | 0,03 | 0,3 | 280 KB |
| Vector | 3 | 0,03 | 0,2 | 280 KB |

## O3

| Konteineris | Strategija | 100k įrašų | 1M įrašų | exe failo dydis |
|---|---|---|---|---|
| Vector | 1 | 0,04 | 0,5 | 289 KB |
| Vector | 2 | 0,05 | 0,5 | 289 KB |
| Vector | 3 | 0,03 | 0,4 | 289 KB |

