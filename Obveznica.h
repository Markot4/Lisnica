#pragma once
#include "VrijednosniPapir.h"

namespace markot4 {
    class Obveznica : public VrijednosniPapir {
        private:
            double nominalnaCijena;

        public:
            Obveznica(std::string oznaka);
            Obveznica(std::string oznaka, double cijena, int kolicina, double nominalnaCijena);
            Obveznica(std::istream& from);

            void postaviNominalnuCijenu(double novaNominalnaCijena);
            double dohvatiNominalnuCijenu() const;
            void toStream(std::ostream& to) override;
            double izracunajVrijednost() override;
            bool isDionica() override;
            bool isObveznica() override;
            void ispisToStream(std::ostream& to) override;
            ~Obveznica() override;
    };
}