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
        std::vector<ASpell *> arr_s;

        SpellBook(const SpellBook &other);
        SpellBook &operator = (const SpellBook &other);
};
