#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    public:
        ASpell();
        ASpell(const std::string &name, const std::string &effects);
        ASpell(const ASpell &other);
        virtual ~ASpell();

        const std::string &getName() const;
        const std::string &getEffects() const;

        virtual ASpell *clone() const = 0;

        void launch(const ATarget &at);
        ASpell &operator = (const ASpell &other);

    protected:
        std::string name;
        std::string effects;
};

