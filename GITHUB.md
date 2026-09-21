# Cum pui proiectul pe GitHub

Git păstrează versiunile fișierelor. GitHub este site-ul unde poți încărca
proiectul. Un „repository” este locul în care stau fișierele proiectului
și istoricul schimbărilor.

Ai nevoie de un cont GitHub și de Git instalat pe calculator.

## 1. Creează un proiect pe GitHub

Intră în cont și creează un repository nou, numit `tic-tac-toe-lab01`.
Lasă-l gol: nu adăuga automat README sau alte fișiere, fiindcă acestea
sunt deja în arhivă. Alege vizibilitatea cerută de profesor.

## 2. Copiază proiectul gol pe calculator

Acest pas se numește „clonare”. Deschide PowerShell în folderul în care
vrei să păstrezi proiectul și scrie comenzile de mai jos.
Înlocuiește `UTILIZATOR` cu numele contului tău GitHub.

```powershell
git clone https://github.com/UTILIZATOR/tic-tac-toe-lab01.git
cd tic-tac-toe-lab01
```

Dacă apare mesajul că proiectul este gol, este normal.

## 3. Adaugă fișierele jocului

Dezarhivează `tic-tac-toe-simplu.zip`. Din folderul extras, copiază toate
fișierele și subfolderele în folderul creat la pasul 2.

Fișierul `README.md` trebuie să fie direct în folderul clonat, lângă
`run.bat` și folderele `include` și `src`. Nu copia încă o dată folderul
mare în interiorul lui.

Deschide `run.bat` ca să vezi dacă jocul pornește.

## 4. Verifică numele folosit în Git

În aceeași fereastră PowerShell, scrie:

```powershell
git config user.name
git config user.email
```

Dacă nu apare nimic sau datele nu sunt ale tale, setează numele și
adresa ta. Înlocuiește exemplele de mai jos cu datele reale:

```powershell
git config user.name "Numele tau"
git config user.email "adresa-ta@example.com"
```

## 5. Salvează și trimite proiectul

Rulează comenzile în ordine:

```powershell
git add .
git commit -m "Adauga jocul X si O"
git branch -M main
git push -u origin main
```

`add` pregătește fișierele. `commit` salvează o versiune a lor.
`main` este numele ramurii principale, iar `push` trimite fișierele pe GitHub.
Dacă ți se cere să te autentifici, urmează pașii afișați.

## 6. Verifică rezultatul

Deschide pagina proiectului pe GitHub. Ar trebui să vezi `README.md`,
`prompts_lab01.md`, cele trei fișiere `.hpp` din `include` și codul din `src`.

Trimite profesorului linkul proiectului. Dacă proiectul este privat,
profesorul trebuie să aibă acces la el.
