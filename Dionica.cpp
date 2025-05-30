﻿#include "Dionica.h"
#include <sstream>
#include <iomanip> 

namespace markot4 {

    Dionica::Dionica(std::string oznaka) : VrijednosniPapir(oznaka) {}
    Dionica::Dionica(std::string oznaka, int kolicina, double cijena) : VrijednosniPapir(oznaka, kolicina, cijena) {}
    Dionica::Dionica(std::istream& from) {
        std::string line;
        double cijena;
        int kolicina;
        from >> this->getOznaka() >> cijena >> kolicina;
        postaviCijenu(cijena);
        postaviKolicinu(kolicina);
        getline(from, line);
    }

    void Dionica::postaviCijenu(double novaCijena) {
        VrijednosniPapir::postaviCijenu(novaCijena);
    }

    double Dionica::dohvatiCijenu() const {
        return VrijednosniPapir::dohvatiCijenu();
    }

    double Dionica::izracunajVrijednost() {
        return dohvatiCijenu() * dohvatiKolicinu();
    }

    void Dionica::toStream(std::ostream& to) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << dohvatiCijenu();
        std::string formatirana_cijena = oss.str();

        to << "dionica " << getOznaka() << " " << formatirana_cijena << " " << dohvatiKolicinu();
    }

    bool Dionica::isObveznica() {
        return false;
    }

    bool Dionica::isDionica() {
        return true;
    }

    void Dionica::ispisToStream(std::ostream& to) {

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << dohvatiCijenu();
        std::string formatirana_cijena = oss.str();

        to << getOznaka() << " " << formatirana_cijena << " " << dohvatiKolicinu();
    }

    Dionica::~Dionica() {

    }


}