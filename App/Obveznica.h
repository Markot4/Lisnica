#pragma once
#include "VrijednosniPapir.h"

namespace markot4 {
    class Obveznica : public VrijednosniPapir {
        
        public:
            Obveznica(string oznaka);
            Obveznica(string oznaka, double cijena);

            void postaviCijenu(double novaCijena);
            double dohvatiCijenu() const;
            double izracunajVrijednost();
    };
}