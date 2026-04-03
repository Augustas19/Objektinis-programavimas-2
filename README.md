## Class 
<img width="499" height="244" alt="Screenshot 2026-04-03 134651" src="https://github.com/user-attachments/assets/24e966e0-4ed9-48aa-b65d-6ee4353b4df7" />

## Struct
<img width="795" height="303" alt="image" src="https://github.com/user-attachments/assets/bcca31cf-f6d3-458c-bb1f-0adc5e251de6" />

Programa naudojant class veikia truputį lėčiau nei su struct. 

## O1
| Konteineris | Strategija | 100k įrašų | 1M įrašų |
|---|---|---|---|
| Vector | 1 | 0,06 | 0,7 |
| Vector | 2 | 0,04 | 0,4 | 
| Vector | 3 | 0,03 | 0,4 | 

## O2

| Konteineris | Strategija | 100k įrašų | 1M įrašų |
|---|---|---|---|
| Vector | 1 | 0,07 | 0,8 |
| Vector | 2 | 0,06 | 0,4 | 
| Vector | 3 | 0,04 | 0,3 | 

## O3

| Konteineris | Strategija | 100k įrašų | 1M įrašų |
|---|---|---|---|
| Vector | 1 | 0,03 | 0,5 |
| Vector | 2 | 0,02 | 0,2 | 
| Vector | 3 | 0,02 | 0,2 | 

Programa geriausiai dirba su O3 flagu.
