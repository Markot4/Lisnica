#pragma once
#include "VrijednosniPapir.h"

namespace markot4 {
    class Obveznica : public VrijednosniPapir {
        
        public:
            double nominalnaCijena;
            Obveznica(std::string oznaka);
            Obveznica(std::string oznaka, double cijena, int kolicina, double nominalnaCijena);
            Obveznica(std::istream& from);

            void toStream(std::ostream& to) override;
            void postaviCijenu(double novaCijena);
            double dohvatiCijenu() const;
            double izracunajVrijednost() override;
            bool isDionica() override;
            bool isObveznica() override;
            void ispisToStream(std::ostream& to) override;
            ~Obveznica() override;
    };
}