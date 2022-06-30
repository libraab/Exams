#include "Warlock.hpp"
Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day." << std::endl; 
}

const std::string &Warlock::getName() const { return (this->name) ;}
const std::string &Warlock::getTitle() const { return (this->title) ;}
void Warlock::setTitle(const std::string &title) { this->title = title;}
void Warlock::introduce() const {std::cout << this->name << ": I am " << this->name << ", "  << this->title << "!" << std::endl;}
Warlock::~Warlock()
{
	std::vector <ASpell *>::iterator it_b = this->ar.begin();
	std::vector <ASpell *>::iterator it_e = this->ar.end();

	std::cout << this->name << ": My job here is done!" << std::endl;
	while(it_b != it_e)
	{
		delete(*it_b);
		it_b++;
	}
	this->ar.clear();
}

void Warlock::learnSpell(ASpell *as)
{
	std::vector <ASpell *>::iterator it_b = this->ar.begin();
	std::vector <ASpell *>::iterator it_e = this->ar.end();

	while(it_b != it_e)
	{
		if((*it_b)->getName() == as->getName())
			return;
		it_b++;
	}
	this->ar.push_back(as->clone());
}

void Warlock::forgetSpell(const std::string &name) 
{
	std::vector <ASpell *>::iterator it_b = this->ar.begin();
	std::vector <ASpell *>::iterator it_e = this->ar.end();

	while(it_b != it_e)
	{
		if((*it_b)->getName() == name)
		{
			delete(*it_b);
			this->ar.erase(it_b);
			return;
		}
		it_b++;
	}
}

void Warlock::launchSpell(const std::string &name, const ATarget &at)
{
	std::vector <ASpell *>::iterator it_b = this->ar.begin();
	std::vector <ASpell *>::iterator it_e = this->ar.end();
	
	while(it_b != it_e)
	{
		if((*it_b)->getName() == name)
		{
			(*it_b)->launch(at);
			return;
		}
		it_b++;
	}
}
