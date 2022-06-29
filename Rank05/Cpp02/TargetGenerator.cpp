#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator()
{
	std::vector<ATarget *>::iterator it_b = this->ar.begin();
	std::vector< ATarget *>::iterator it_e = this->ar.end();
	while(it_b != it_e)
	{
		delete (*it_b);
		it_b++;
	}
	this->ar.clear();
}

void TargetGenerator::learnTargetType(ATarget *at)
{
	std::vector<ATarget *>::iterator it_b = this->ar.begin();
	std::vector< ATarget *>::iterator it_e = this->ar.end();
	if(at)
	{
		while(it_b != it_e)
		{
			if((*it_b)->getType() == at->getType())
				return;
			it_b++;
		}
		this->ar.push_back(at->clone());
	}
}
void TargetGenerator::forgetTargetType(const std::string &name)
{
	std::vector<ATarget *>::iterator it_b = this->ar.begin();
	std::vector<ATarget *>::iterator it_e = this->ar.end();
	while(it_b != it_e)
	{
		if((*it_b)->getType() == name)
		{
			delete (*it_b);
			this->ar.erase(it_b);
			return;
		}
		it_b++;
	}
}

ATarget *TargetGenerator::createTarget(const std::string &name)
{
	std::vector<ATarget *>::iterator it_b = this->ar.begin();
	std::vector<ATarget *>::iterator it_e = this->ar.end();
	while(it_b != it_e)
	{
		if((*it_b)->getType() == name)
			return(*it_b);
		it_b++;
	}
	return(NULL);
}

