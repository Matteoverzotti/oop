
Cerințe compune pentru toate temele și proiectele:

- folosirea coerentă și motivată a specificatorilor de acces (`private`, `protected`, `public`)
- folosirea coerentă și motivată a `const` și referință (`&`)
- teste
- să nu aveți memorie reziduală (memory leaks), în caz că faceți alocări dinamice


# Tema 1 - `vector` container

## Cerințe tema 1

Notă: Puteți prezenta clasa de `vector` pe care lucrăm la laborator având în vedere că acoperă toate cerințele, dar aceasta trebuie să fie completă și să îi adăugați voi o funcționalitate extra (la alegere) și teste pentru ea.

Tema 1 trebuie să conțină (și să arate că știți să folosiți):

- câmpuri + metode publice și private ✅
- constructori ✅
- destructori ✅
- supraîncărcare de operatori (inclusiv operatorii `>>` -- citire și `<<` -- afișare) ✅

# Tema 2 - clase pentru geometrie computațională

`Shape`, `Polygon`, `CurvedShape`, `Rectangle`, `Square`, `Triangle`, `Circle`, `Ellipse`

## Cerințe tema 2

Tema 2 trebuie să conțină (și să arate că știți să folosiți):

- moșteniri ✅
- funcții virtuale ✅
- excepții (și handling de excepții) ✅
- dynamic_cast sau static_cast => va trebui să folosiți pointeri ✅
- optional: puteți include moșteniri tip diamant aici în loc de tema 3
- **bonus points:** o clasă abstractă ✅

# Tema 3

Scopul ultimei teme este utilizarea unor noțiuni mai avansate de OOP (principii SOLID, design patterns) și a programării
generice.

### Cerințe tema 3

- minim o funcție șablon și o clasă șablon (template) ✅
  - modificați o clasă existentă care este ceva mai izolată de celelalte
  (să nu aveți foarte mult de modificat) și transformați-o în clasă template ✅
  - adăugați (minim) un atribut de tip `T` sau care depinde de `T` ✅
    - adăugați (minim) o funcție membru care să depindă de `T` (sau de alt parametru template); ✅
    - adăugați (minim) o funcție normală/liberă template; poate să fie `friend` ✅
- minim 2 design patterns (3 dacă aveți singleton sau ceva la fel de simplu și proiectul e simplu);
  - Singleton ✅ - `Logger`
  - Factory Method ✅ - `ShapeFactory`
  - Builder