#include "VrijednosniPapir.h"

namespace markot4 {

    class Dionica : public VrijednosniPapir {

        public:
            Dionica(string oznaka);
            Dionica(string oznaka, int kolicina, double cijena);
            Dionica(istream& from);

            void postaviCijenu(double novaCijena);
            double dohvatiCijenu() const;
            double izracunajVrijednost() override;
            void toStream(ostream& to) override;
            bool isDionica() override;
            bool isObveznica() override;
            ~Dionica() override;
    };
}