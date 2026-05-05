## Class 
<img width="499" height="244" alt="Screenshot 2026-04-03 134651" src="https://github.com/user-attachments/assets/24e966e0-4ed9-48aa-b65d-6ee4353b4df7" />

## Struct
<img width="795" height="303" alt="image" src="https://github.com/user-attachments/assets/bcca31cf-f6d3-458c-bb1f-0adc5e251de6" />

Programa naudojant class veikia truputį lėčiau nei su struct. 

## O1
| Konteineris | Strategija | 100k įrašų | 1M įrašų | exe failo dydis |
|---|---|---|---|---|
| Vector | 1 | 0,06 | 0,7 | 291 KB |
| Vector | 2 | 0,04 | 0,4 | 291 KB |
| Vector | 3 | 0,03 | 0,4 | 291 KB |

## O2

| Konteineris | Strategija | 100k įrašų | 1M įrašų | exe failo dydis |
|---|---|---|---|---|
| Vector | 1 | 0,07 | 0,8 | 275 KB |
| Vector | 2 | 0,06 | 0,4 | 275 KB |
| Vector | 3 | 0,04 | 0,3 | 275 KB |

## O3

| Konteineris | Strategija | 100k įrašų | 1M įrašų | exe failo dydis |
|---|---|---|---|---|
| Vector | 1 | 0,03 | 0,5 | 277 KB |
| Vector | 2 | 0,02 | 0,2 | 277 KB |
| Vector | 3 | 0,02 | 0,2 | 277 KB |

Programa geriausiai dirba su O3 flagu.
