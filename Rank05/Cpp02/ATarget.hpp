#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;
class ATarget
{
    public:
        ATarget();
        ATarget(const std::string &type);
        ATarget(const ATarget &other);
        virtual ~ATarget();

        const std::string &getType() const;

        void getHitBySpell(const ASpell &as) const;

        virtual ATarget *clone() const = 0;
        ATarget & operator = (const ATarget &other);

    private:
        std::string type;
};
