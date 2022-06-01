#include "ATarget.hpp"

ATarget::ATarget() : type(){}
ATarget::ATarget(std::string const &type)
{
this->type = type;
}
ATarget::ATarget(ATarget const &other): type(other.type){}
ATarget & ATarget::operator=(ATarget const & other)
{
if(&other != this)
{
this->type = other.type;
}
return(*this);
}

ATarget::~ATarget(){}

std::string const & ATarget::getType() const{return(this->type);}

void ATarget::getHitBySpell(ASpell const & as) const
{
std::cout << this->type << " has been " << as.getEffects() << "!" << std::endl;
}


