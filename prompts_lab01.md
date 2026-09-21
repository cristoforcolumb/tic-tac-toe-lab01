# Ajutorul folosit la proiect

Am folosit Codex, un asistent AI, pentru cod și explicații.
Mai jos sunt cererile principale și rezultatele lor.

## 1. Pregătirea jocului

Am trimis captura cu tema și am cerut:

> Pregătește proiectul și fișierele cerute

Jocul ales a fost:

> Tic-tac-toe (X și O)

A fost pregătit un joc pentru doi jucători, cu afișare în consolă.
Codul a fost împărțit în cele trei clase cerute: una pentru reguli,
una pentru afișare și una pentru citirea comenzilor.

## 2. O variantă mai simplă

La întrebarea despre nivelul de C++, am răspuns:

> Începător: tablouri, funcții și clase simple

Codul a fost simplificat. Tabla este acum un tabel `char[3][3]`.
Pentru verificarea câștigătorului sunt folosite bucle și condiții `if`.

## 3. Explicații mai ușor de înțeles

Am cerut și simplificarea textului. Un fragment din cerere:

> mai simplu pentru un utilizator incepator, cu termeni mai simpli si mai human

README-ul, pașii pentru GitHub și acest jurnal au fost rescrise mai scurt,
cu explicații pentru termenii folosiți. Codul jocului a rămas la fel.

## Ce problemă a apărut

La început, compilarea nu pornea corect, deși MinGW era instalat.
Fișierele `build.bat` și `test.bat` au fost corectate ca programele folosite
la compilare să găsească fișierele MinGW. Apoi compilarea a reușit.

## Ce a fost verificat

Asistentul a compilat jocul și a rulat testele. Au fost verificate
victoria lui X și a lui O, remiza, căsuțele ocupate, comenzile greșite
și ieșirea din joc. Testele au trecut.

Publicarea pe GitHub trebuie făcută separat, din contul meu.
