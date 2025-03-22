#include "Obveznica.h"
#include <iomanip> 

namespace markot4 {
    Obveznica::Obveznica(string oznaka) : VrijednosniPapir(oznaka), nominalnaCijena(100){}
    Obveznica::Obveznica(string oznaka, double cijena, int kolicina, double nominalnaCijena) : VrijednosniPapir(oznaka, kolicina, cijena), nominalnaCijena(nominalnaCijena) {}
    Obveznica::Obveznica(istream& from) {
        string line;
        from >> oznaka >> cijena >> kolicina >> nominalnaCijena;
        getline(from, line);
    }
    void Obveznica::postaviCijenu(double novaCijena) {
        VrijednosniPapir::postaviCijenu(novaCijena);
    }

    double Obveznica::dohvatiCijenu() const {
        return VrijednosniPapir::dohvatiCijenu();
    }

    double Obveznica::izracunajVrijednost() {
        return cijena * nominalnaCijena * kolicina / 100;
    }

    void Obveznica::toStream(ostream& to) {
        to << "obveznica " << oznaka << " " << fixed << setprecision(2) << cijena << " " << kolicina << " " << fixed << setprecision(2) << nominalnaCijena;
    }

    bool Obveznica::isObveznica() {
        return true;
    }

    bool Obveznica::isDionica() {
        return false;
    }

    Obveznica::~Obveznica() {

    }
}