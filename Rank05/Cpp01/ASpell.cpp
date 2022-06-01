#include "ASpell.hpp"

    ASpell::ASpell() : name(), effects(){}
//----------------------------------------------------------------
    ASpell::ASpell(const std::string &name, const std::string &effects)
    {
        this->name = name;
        this->effects = effects;
    }
//----------------------------------------------------------------
    ASpell::ASpell(const ASpell &other): name(other.name), effects(other.effects){}
//----------------------------------------------------------------
    ASpell::~ASpell(){}
//----------------------------------------------------------------
    const std::string &ASpell::getName() const      {return(this->name);}
    const std::string &ASpell::getEffects() const   {return(this->effects);}
//----------------------------------------------------------------
    void ASpell::launch(const ATarget &at)
    {
        at.getHitBySpell(*this);
    }
//----------------------------------------------------------------
    ASpell &ASpell::operator = (const ASpell &other)
    {
        if(&other != this)
        {
            this->name = other.name;
            this->effects = other.effects;
        }
        return (*this);
    }