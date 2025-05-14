#include "VrijednosniPapir.h"

namespace markot4 {

    class Dionica : public VrijednosniPapir {

        public:
            Dionica(std::string oznaka);
            Dionica(std::string oznaka, int kolicina, double cijena);
            Dionica(std::istream& from);

            void postaviCijenu(double novaCijena);
            double dohvatiCijenu() const;
            double izracunajVrijednost() override;
            void toStream(std::ostream& to) override;
            bool isDionica() override;
            bool isObveznica() override;
            void ispisToStream(std::ostream& to) override;
            ~Dionica() override;
    };
}