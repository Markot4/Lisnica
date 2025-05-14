// Lisnica.cpp : Ovaj fajl sadržava 'main' funkciju. Izvršavanje programa počinje i završava tamo.
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
        std::cerr << "Pogreška pri postavljanju kodne stranice izlaza konzole: " << GetLastError() << std::endl;
        // return 1; // Opcionalno: exit ako postavka neuspije, ionak output možda dalje parcionalno radi
    }

    std::string filename = "lisnica.dat";
    try {
        try {
            std::ifstream inputFile(filename);
            if (!inputFile.is_open()) {
                std::cout << "lisnica.dat nije pronađena, biti će stvorena" << std::endl;
                LisnicaClass l;
                std::ofstream outputFile(filename);
                l.toStream(outputFile);
                outputFile.close();
            }
        }
        catch (...) {
            std::cerr << "Greška pri stvaranju lisnica.dat datoteke";
            return - 1;
        }

        std::ifstream inputFile(filename);
        if (! inputFile.is_open()) {
            std::cerr << "Greška pri otvaranju lisnica.dat datoteke";
            return - 1;
        }
        LisnicaClass l(inputFile);
        inputFile.close();
        
        LisnicaCommand command(argc, argv, &l);
        command.process();

        try {
            std::ofstream outputFile(filename);
            l.toStream(outputFile);
            outputFile.close();
        } catch (...) {
            std::cerr << "Greška pri spremanju lisnice" << std::endl;
            return -1;
        }
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}