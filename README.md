# Apie programą

Ši programa yra skirta darbui su studentų duomenimis: nuskaitymui, apdorojimui, rūšiavimui, rikiavimui bei išvedimui atgal į failą.

Ši programa leidžia vartotojui:
1. Įvesti visus studentų duomenis (vardą, pavardę, namų darbų bei egzaminų pažymius),
2. Generuoti studentų pažymius,
3. Generuoti visus studentų duomenis (vardą, pavardę, namų darbų bei egzaminų pažymius),
4. Nuskaityti duomenis apie studentus iš failo
5. Generuoti naujus failus su studentų duomenimis
6. Testuoti failų generavimą,
7. Testuoti kaip greitai programa veikia apdorojan skirtingo dydžio duomenis
8. Testuoti kaip greitai programa veikia apdorojan skirtingo dydžio duomenis su skirtingais konteineriais (vector, list, deque).

## Paleidimo instrukcija 

Jūsų kompiuteryje turi būti atsiustas `make` bei terminalas, kuris jį palaiko;

Atsisiuntus visus failus, terminale reikia nueiti į failų lokaciją, o tada terminale jau galima rašyti `make`.

Kai failai bus sukompiliuoti į terminalą įveskite `./programa`.

## Testavimo sistema
Windows 11, Ryzen 5 5625U, 16 GB RAM, SSD.

## Testavimų rezultatai

Strategijos: 
1. Studentų skirstymas į du naujus konteinerius pagal jų vidurkį.
2. Studentų, kurių vidurkis mažesnis nei 5 perkėlimas į kitą konteinerį ir pašalinimas iš pradinio. 
3. Studentų, kurių vidurkis mažesnis nei 5 perkėlimas į kitą konteinerį ir pašalinimas iš pradinio, naudojant kitas funkcijas. 

Laikas matuotas sekundėmis (s)

| Konteineris | Strategija | 1k įrašų | 10k įrašų | 100k įrašų | 1M įrašų | 10M įrašų |
|---|---|---|---|---|---|---|
| Vector | 1 | 0,0006 | 0,005 | 0,04 | 0,6 | 10,7 | 
| Vector | 2 | 0,0002 | 0,002 | 0,03 | 0,3 | 10,6 | 
| Vector | 3 | 0,0003 | 0,003 | 0,03 | 0,4 | 6,4 | 
| List | 1 | 0,0005 | 0,004 | 0,04 | 0,4 | 15,7 | 
| List | 2 | 0,0004 | 0,004 | 0,06 | 0,6 | 15,4 | 
| List | 3 | 0,0002 | 0,002 | 0,04 | 0,4 | 10,5 | 
| Deque | 1 | 0,0004 | 0,005 | 0,06 | 0,6 | 12,8 | 
| Deque | 2 | 0,0006 | 0,005 | 0,08 | 0,5 | 17,1 | 
| Deque | 3 | 0,0004 | 0,004 | 0,07 | 0,5 | 10,4 | 

<img width="271" height="266" alt="image" src="https://github.com/user-attachments/assets/e79d7ea3-2182-4a14-8887-094ada6c1057" />
