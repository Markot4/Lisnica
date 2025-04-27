// Lisnica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>

#include <iostream>
#include "LisnicaClass.h"
#include "Dionica.h"
#include "Obveznica.h"
#include "LisnicaCommand.h"
#include <string>
#include "fstream"


using namespace markot4;

int main(int argc, const char* argv[]) {

    if (!SetConsoleOutputCP(CP_UTF8)) {
        std::cerr << "Error setting console output code page: " << GetLastError() << std::endl;
        // return 1; // Opcionalno: exit ako postavka neuspije, ionak output mozda dalje parcionalno radi
    }

    string filename = "lisnica.dat";
    try {
        try {
            ifstream inputFile(filename);
            if (!inputFile.is_open()) {
                cout << "lisnica.dat nije pronađena, biti će stvorena" << endl;
                LisnicaClass l;
                ofstream outputFile(filename);
                l.toStream(outputFile);
                outputFile.close();
            }
        }
        catch (...) {
            cerr << "Greška pri stvaranju lisnica.dat datoteke";
            return - 1;
        }

        ifstream inputFile(filename);
        if (! inputFile.is_open()) {
            cerr << "Greška pri otvaranju lisnica.dat datoteke";
            return - 1;
        }
        LisnicaClass l(inputFile);
        inputFile.close();
        
        LisnicaCommand command(argc, argv, &l);
        command.process();

        try {
            ofstream outputFile(filename);
            l.toStream(outputFile);
            outputFile.close();
        } catch (...) {
            cerr << "Greška pri spremanju lisnice" << endl;
            return -1;
        }
    }
    catch (const exception& e){
        cerr << e.what() << endl;
        return -1;
    }
    return 0;
}