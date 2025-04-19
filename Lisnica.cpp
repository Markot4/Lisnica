// Lisnica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LisnicaClass.h"
#include "Dionica.h"
#include "Obveznica.h"
#include "LisnicaCommand.h"
#include <string>
#include "fstream"


using namespace markot4;
using namespace std;

int main(int argc, const char* argv[]) {

    string filename = "lisnica.dat";
    try {
        LisnicaClass* l;
        try {
            ifstream inputFile(filename);
            if (inputFile.is_open()) {
                l = new LisnicaClass(inputFile);
            }
            else {
                cout << "lisnica.dat nije pronadjena, biti ce stvorena" << endl;
                l = new LisnicaClass();
            }
            inputFile.close();
        } catch (...) {
            cerr << "Greska pri ucitavanju lisnice" << endl;
            return -1;
        }

        LisnicaCommand command(argc, argv, l);
        command.process();
        
        ofstream outputFile(filename);
        l->toStream(outputFile);
        outputFile.close();

        return 0;
    }
    catch (const exception& e){
        cerr << e.what() << endl;
        return -1;
    }
/*
    LisnicaClass lisnica;
    string naredba = argv[1];
    // Ucitati podatke iz datoteke u lisnicu i na kraju ako je bilo promjena zapisati ih ponovo u datoteku
    if (naredba == "dodaj" && argc >= 4) {
        string tip = argv[2];
        string oznaka = argv[3];
        if (tip == "dionica") {
            lisnica.dodajVrijednosniPapir(Dionica(oznaka));
        }
        else if (tip == "obveznica" && argc == 5) {
            double cijena = stod(argv[4]);
            double nominalnaCijena = stod(argv[5]);
            lisnica.dodajVrijednosniPapir(Obveznica(oznaka, cijena, nominalnaCijena));
        }
        else {
            cout << "Neispravan unos za dodavanje!" << endl;
        }
    }
    else if (naredba == "izbaci" && argc == 3) {
        lisnica.izbaciVrijednosniPapir(argv[2]);
    }
    else if (naredba == "kolicina" && argc == 4) {
        string oznaka = argv[2];
        int promjena = stoi(argv[3]);
        lisnica.promjenaKolicine(promjena, oznaka);
    }
    else if (naredba == "cijena" && argc == 4) {
        string oznaka = argv[2];
        double novaCijena = stod(argv[3]);
        lisnica.promjenaCijene(novaCijena, oznaka);
    }
    else if (naredba == "cijena" && argc == 4 && string(argv[2]) == "--datoteka") { //ima vise posla
    }
    else if (naredba == "vrijednost" && argc == 3) {
        string oznaka = argv[2];
        cout << "Vrijednost " << oznaka << " je " << lisnica.vrijPoVrijPapir(oznaka) << " EUR" << endl;
    }
    else if (naredba == "vrijednost" && argc == 3 && string(argv[2]) == "dionice") {
        cout << "Ukupna vrijednost svih dionica je " << lisnica.sveDionice() << " EUR" << endl;
    }
    else if (naredba == "vrijednost" && argc == 3 && string(argv[2]) == "obveznice") {
        cout << "Ukupna vrijednost svih obveznica je " << lisnica.sveObveznice() << " EUR" << endl;
    }
    else if (naredba == "vrijednost" && argc == 2) {
        cout << "Ukupna vrijednost lisnice je " << lisnica.vrijednostCijeleLisnice() << " EUR" << endl;
    }
    else if (naredba == "sadrzaj" && argc == 2) {
        lisnica.sadrzajCijeleLisnice();
    }
    else {
        cout << "Nepoznata naredba!" << endl;
    }
    */
    return 0;
}