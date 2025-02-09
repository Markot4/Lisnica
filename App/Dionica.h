#include "VrijednosniPapir.h"

namespace markot4 {

    class Dionica : public VrijednosniPapir {

        public:
            Dionica(string oznaka);
            Dionica(string oznaka, double cijena);

            void postaviCijenu(double novaCijena);
            double dohvatiCijenu() const;
            double izracunajVrijednost();
    };
}