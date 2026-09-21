# X și O

Proiect pentru laboratorul 1: Crearea unui proiect. Lucrul cu Git.

Este jocul X și O, scris în C++. Se joacă în doi, la același calculator.

## Cum se joacă

X începe. Alegi o căsuță liberă, scrii numărul ei și apeși Enter.
După aceea mută celălalt jucător.

```text
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

Câștigă cel care pune trei simboluri pe un rând, pe o coloană sau pe o
diagonală. Dacă tabla se umple fără un câștigător, este remiză.

Dacă alegi o căsuță ocupată sau scrii ceva greșit, poți încerca din nou.
Pentru ieșire, scrie `q` și apasă Enter.

## Cum sunt păstrate datele

Tabla este o matrice, adică un tabel cu 3 rânduri și 3 coloane.
Datele de mai jos se află în clasa `GameEngine`:

| Variabilă | Tip | La ce folosește |
| --- | --- | --- |
| `board` | `char[3][3]` | Păstrează tabla. În fiecare loc poate fi X, O sau un spațiu pentru o căsuță liberă. |
| `currentPlayer` | `char` | Arată cine trebuie să mute: X sau O. |
| `winner` | `char` | Păstrează simbolul câștigătorului. Este spațiu dacă nu a câștigat nimeni. |
| `moveCount` | `int` | Numără mutările făcute, de la 0 la 9. |

`char` păstrează un caracter, iar `int` păstrează un număr întreg.

## Ce fac fișierele

- `GameEngine.hpp`: clasa care ține tabla și verifică regulile.
- `Renderer.hpp`: clasa care afișează tabla și rezultatul.
- `Listener.hpp`: clasa care citește ce scrie jucătorul.

Aceste fișiere sunt în folderul `include`. Codul funcțiilor lor este în
fișierele `.cpp` din folderul `src`. Fișierul `main.cpp` pornește jocul și
leagă cele trei clase.

De exemplu, dacă scrii 5, programul verifică locul din mijloc. Dacă este
liber, pune simbolul tău acolo. Apoi verifică dacă ai câștigat și, dacă
partida continuă, îi dă rândul celuilalt jucător.

## Cum pornești jocul

Pe Windows, după dezarhivare, deschide `run.bat` prin dublu clic.
Este necesar MinGW/g++, programul care transformă codul C++ într-un joc
care poate fi pornit. Fișierul `run.bat` îl caută automat și pornește jocul.

O partidă de probă: introdu `1`, `4`, `2`, `5`, `3`, fiecare pe o linie.
X va câștiga pe primul rând.

Pentru o partidă nouă, deschide din nou `run.bat`.

## Alte fișiere

- `GITHUB.md`: pașii pentru a pune proiectul pe GitHub.
- `prompts_lab01.md`: ce ajutor AI a fost folosit, conform punctului 9 din temă.
- `test.bat` și folderul `tests`: verificări automate pentru regulile jocului.
- `CMakeLists.txt`: o altă metodă de compilare; nu este necesară pentru pornirea cu `run.bat`.
