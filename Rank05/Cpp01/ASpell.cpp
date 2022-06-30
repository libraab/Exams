#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects)
{
	this->name = name;
	this->effects = effects;
}
ASpell::~ASpell() {}
const std::string &ASpell::getName() const {return(this->name);}
const std::string &ASpell::getEffects() const {return(this->effects);}
void ASpell::launch(const ATarget &at) const{at.getHitBySpell(*this);}
ASpell &ASpell::operator = (const ASpell &op)
{
	if(&op != this)
	{
		this->name = op.name;
		this->effects = op.effects;
	}
	return (*this);
}
ASpell::ASpell(const ASpell &cpy): name(cpy.name), effects(cpy.effects) {}
