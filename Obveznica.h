#pragma once
#include "VrijednosniPapir.h"

namespace markot4 {
    class Obveznica : public VrijednosniPapir {
        
        public:
            double nominalnaCijena;
            Obveznica(string oznaka);
            Obveznica(string oznaka, double cijena, int kolicina, double nominalnaCijena);

            void postaviCijenu(double novaCijena);
            double dohvatiCijenu() const;
            double izracunajVrijednost() override;
            bool isDionica() override;
            bool isObveznica() override;
            ~Obveznica() override;
    };
}