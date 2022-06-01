#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook()
{
std::vector<ASpell *>::iterator it_b = this->arr_s.begin();
std::vector< ASpell *>::iterator it_e = this->arr_s.end();
while(it_b != it_e)
{
delete (*it_b);
++it_b;
}
this->arr_s.clear();
}

void SpellBook::learnSpell(ASpell *as)
{
std::vector<ASpell *>::iterator it_b = this->arr_s.begin();
std::vector< ASpell *>::iterator it_e = this->arr_s.end();
if(as){
while(it_b != it_e)
{
if((*it_b)->getName() == as->getName())
return;
++it_b;
}
this->arr_s.push_back(as->clone());
}}
void SpellBook::forgetSpell(std::string const & name)
{
std::vector<ASpell *>::iterator it_b = this->arr_s.begin();
std::vector< ASpell *>::iterator it_e = this->arr_s.end();
while(it_b != it_e)
{
if((*it_b)->getName() == name)
{
delete (*it_b);
this->arr_s.erase(it_b);
return;
}
++it_b;
}

}

ASpell *SpellBook::createSpell(std::string const & name)
{
std::vector<ASpell *>::iterator it_b = this->arr_s.begin();
std::vector< ASpell *>::iterator it_e = this->arr_s.end();
while(it_b != it_e)
{
if((*it_b)->getName() == name)
return(*it_b);
++it_b;
}
return(NULL);
}
