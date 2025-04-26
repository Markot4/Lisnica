# Objektno Programiranje seminar: Lisnica

Lisnica je command line program koji služi za jednostavno vođenje evidencije o osobnoj lisnici (portfelju)
dionica i obveznica. Lisnica treba omogućiti:

- dodavanje vrijednosnog papira u lisnicu
- izbacivanje vrijednosnog papira iz lisnice
- promjenu količine nekog vrijednosnog papira
- promjenu cijene nekog vrijednosnog papira
- promjenu cijene svih vrijednosnih papira
- izračun vrijednosti pojedinog vrijednosnog papira
- izračun vrijednosti svih dionica u lisnici
- izračun vrijednosti svih obveznica u lisnici
- izračun vrijednosti cijele lisnice
- ispis sadržaja cijele lisnice

Podatci o lisnici trebaju biti pohranjeni u lokalnoj datoteci.

## Dodavanje vrijednosnog papira u lisnicu

za dodavanje vrijednosnog papira koristiti će se jedna od slijedećih naredbi:

```
lisnica dodaj dionica PLV-R-A 20 107.30
lisnica dodaj obveznica RH-MF007 100 95.00 1000.00
```

Pri dodavanju obveznice potrebno je osim imena dionice specificirati i nominalnu
vrijednost na dvije decimale (u primjeru 1000.00)

## Izbacivanje vrijednosnog papira iz lisnice

za izacivanje vrijednosnog papira će se koristiti slijedeća naredba:

```
lisnica izbaci PLV-R-A
```

## Promjena količine nekog vrijednosnog papira

za promjenu količine nekog vrijednosnog papira treba jedna od slijedećih naredbi:

```
lisnica kolicina PLV-R-A 150
lisnica kolicina PLV-R-A +10
lisnica kolicina RH-MF007 -17
```

Prva naredba postavlja količinu na 150, druga dodaje 10 na postojeću količinu, a
treća oduzima 17 od postojeće količine.

## Promjena cijene nekog vrijednosnog papira

za promjenu cijene nekog vrijednosnog papira treba jedna od slijedećih naredbi:

```
lisnica cijena PLV-R-A 120.34
lisnica cijena RH-MF007 97.81
```

cijena za dionice se izražava u eurima, na dvije decimale
cijena za obveznice se izražava u postotku od nominalne vrijednosti na dvije decimale

## Promjena cijena svih vrijednosnih papira

za promjenu cijene svih vrijednosnih papira koristit će se ova naredba:

```
lisnica cijena --datoteka <imedatoteke.txt>
```

cijene će biti učitane iz datoteke čije je ime specificirano, te će se promijeniti cijene
svih vrijednosnih papira koje se nalaze u toj datoteci, a za ostale će ostati nepromijenjene.

## Izračun vrijednosti pojedinog vrijednosnog papira

za izračun vrijednosti pojedinog vrijednosnog papira koristit će se ova naredba:

```
lisnica vrijednost PLV-R-A
Vrijednost PLV-R-A je 1520.73 Eur
```

## Izračun vrijednosti svih dionica u lisnici

za izračun vrijednosti svih dionica u lisnici koristit ćemo ovu naredbu:

```
lisnica vrijednost dionice
Ukupna vrijednost svih dionica u lisnici je 15372.16 Eur
```

## Izračun vrijednosti svih obveznica u lisnici

za izračun vrijednosti svih obveznica u lisnici koristit ćemo ovu naredbu:

```
lisnica vrijednost obveznice
Ukupna vrijednost svih obveznica je 19294.56 Eur
```

## Izračun vrijednosti cijele lisnice

za izračun vrijednosti cijele lisnice koristit ćemo ovu naredbu:

```
lisnica vrijednost
Ukupna vrijednost lisnice je 34666.72 Eur
```

## Ispis sadržaja cijele lisnice

```
lisnica sadrzaj

```
