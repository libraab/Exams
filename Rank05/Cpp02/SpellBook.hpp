#pragma once
#include "ASpell.hpp"
#include <iostream>
#include <vector>

class SpellBook
{

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *as);
        void forgetSpell(const std::string &name);
        ASpell *createSpell(const std::string &name);

    private:
        std::vector<ASpell *> ar;

        SpellBook(const SpellBook &cpy);
        SpellBook &operator = (const SpellBook &op);
};
