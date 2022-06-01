#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator()
{
std::vector<ATarget *>::iterator it_b = this->arr_t.begin();
std::vector< ATarget *>::iterator it_e = this->arr_t.end();
while(it_b != it_e)
{
delete (*it_b);
++it_b;
}
this->arr_t.clear();
}

void TargetGenerator::learnTargetType(ATarget *at)
{
std::vector<ATarget *>::iterator it_b = this->arr_t.begin();
std::vector< ATarget *>::iterator it_e = this->arr_t.end();
if(at){
while(it_b != it_e)
{
if((*it_b)->getType() == at->getType())
return;
++it_b;
}
this->arr_t.push_back(at->clone());
}}
void TargetGenerator::forgetTargetType(std::string const & name)
{
std::vector<ATarget *>::iterator it_b = this->arr_t.begin();
std::vector< ATarget *>::iterator it_e = this->arr_t.end();
while(it_b != it_e)
{
if((*it_b)->getType() == name)
{
delete (*it_b);
this->arr_t.erase(it_b);
return;
}
++it_b;
}

}

ATarget * TargetGenerator::createTarget(std::string const & name)
{
std::vector<ATarget *>::iterator it_b = this->arr_t.begin();
std::vector< ATarget *>::iterator it_e = this->arr_t.end();
while(it_b != it_e)
{
if((*it_b)->getType() == name)
return(*it_b);
++it_b;
}
return(NULL);
}

