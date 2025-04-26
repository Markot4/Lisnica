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
using namespace std;

int main(int argc, const char* argv[]) {

    if (!SetConsoleOutputCP(CP_UTF8)) {
        std::cerr << "Error setting console output code page: " << GetLastError() << std::endl;
        // return 1; // Optional: exit if setting fails, though output might still partially work
    }

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
    return 0;
}