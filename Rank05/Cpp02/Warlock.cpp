#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title)
{
this->name = name;
this->title = title;
std::cout << this->name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const{ return(this->name);}
std::string const & Warlock::getTitle() const{return(this->title);}

void Warlock::setTitle(std::string const & title) {this->title = title;}
void Warlock::introduce() const
{
std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *as)
{
b.learnSpell(as);
}
void Warlock::forgetSpell(std::string const & name)
{
b.forgetSpell(name);
}

void Warlock::launchSpell(std::string const & name, ATarget const & at)
{
ASpell *t = b.createSpell(name);
if(t)
t->launch(at);
}


#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "BrickWall.hpp"
#include "TargetGenerator.hpp"
int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}
