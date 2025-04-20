# Objektno Programiranje seminar: Lisnica

Lisnica je command line program koji sluzi za jednostavno vodjenje evidencije o osobnoj lisnici (portfelju)
dionica i obveznica. Lisnica treba omoguciti:

- dodavanje vrijednosnog papira u lisnicu
- izbacivanje vrijednosnog papira iz lisnice
- promjenu kolicine nekog vrijednosnog papira
- promjenu cijene nekog vrijednosnog papira
- promjenu cijene svih vrijednosnih papira
- izracun vrijednosti pojedinog vrijednosnog papira
- izracun vrijednosti svih dionica u lisnici
- izracun vrijednosti svih obveznica u lisnici
- izracun vrijednosti cijele lisnice
- ispis sadržaja cijele lisnice

Podatci o lisnici trebaju biti pohranjeni u lokalnoj datoteci.

## Dodavanje vrijednosnog papira u lisnicu

za dodavanje vrijednosnog papira koristiti ce se jedna od slijedecih naredbi:

```
lisnica dodaj dionica PLV-R-A 20 107.30
lisnica dodaj obveznica RH-MF007 100 95.00 1000.00
```

Pri dodavanju obveznice potrebno je osim imena dionice specificirati i nominalnu
vrijednost na dvije decimale (u primjeru 1000.00)

## Izbacivanje vrijednosnog papira iz lisnice

za izacivanje vrijednosnog papira ce se koristiti slijedeća naredba:

```
lisnica izbaci PLV-R-A
```

## Promjena kolicine nekog vrijednosnog papira

za promjenu kolicine nekog vrijednosnog papira treba jedna od slijedecih naredbi:

```
lisnica kolicina PLV-R-A 150
lisnica kolicina PLV-R-A +10
lisnica kolicina RH-MF007 -17
```

Prva naredba postavlja kolicinu na 150, druga dodaje 10 na postojecu kolicinu, a
treca oduzima 17 od postojece kolicine.

## Promjena cijene nekog vrijednosnog papira

za promjenu cijene nekog vrijednosnog papira treba jedna od slijedećih naredbi:

```
lisnica cijena PLV-R-A 120.34
lisnica cijena RH-MF007 97.81
```

cijena za dionice se izrazava u eurima, na dvije decimale
cijena za obveznice se izrazava u postotku od nominalne vrijednosti na dvije decimale

## Promjena cijena svih vrijednosnih papira

za promjenu cijene svih vrijednosnih papira koristit će se ova naredba:

```
lisnica cijena --datoteka <imedatoteke.txt>
```

cijene ce biti ucitane iz datoteke cije je ime specificirano, te ce se promijeniti cijene
svih vrijednosnih papira koje se nalaze u toj datoteci, a za ostale ce ostati nepromijenjene.

## Izracun vrijednosti pojedinog vrijednosnog papira

za izracun vrijednosti pojedinog vrijednosnog papira koristit će se ova naredba:

```
lisnica vrijednost PLV-R-A
Vrijednost PLV-R-A je 1520.73 Eur
```

## Izracun vrijednosti svih dionica u lisnici

za izracun vrijednosti svih dionica u lisnici koristit ćemo ovu naredbu:

```
lisnica vrijednost dionice
Ukupna vrijednost svih dionica u lisnici je 15372.16 Eur
```

## Izracun vrijednosti svih obveznica u lisnici

za izracun vrijednosti svih obveznica u lisnici koristit ćemo ovu naredbu:

```
lisnica vrijednost obveznice
Ukupna vrijednost svih obveznica je 19294.56 Eur
```

## Izracun vrijednosti cijele lisnice

za izracun vrijednosti cijele lisnice koristit ćemo ovu naredbu:

```
lisnica vrijednost
Ukupna vrijednost lisnice je 34666.72 Eur
```

## Ispis sadržaja cijele lisnice

```
lisnica sadrzaj

```
