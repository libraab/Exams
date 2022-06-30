#include "ATarget.hpp"

ATarget::ATarget(const std::string &type){this->type = type;}
ATarget::~ATarget() {}
const std::string &ATarget::getType() const{return(this->type);}
void ATarget::getHitBySpell(const ASpell &as)const
{std::cout << this->type << " has been " << as.getEffects() << "!" << std::endl;}
ATarget &ATarget::operator = (const ATarget &op)
{
    if(&op != this)
        this->type = op.type;
    return (*this);
}
ATarget::ATarget(const ATarget &cpy): type(cpy.type) {}
