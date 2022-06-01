#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

//-----------------------------------------------------------------------------
  Warlock::Warlock(std::string const & name, std::string const & title)
  {
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day." << std::endl;
  }
//-----------------------------------------------------------------------------
  Warlock::~Warlock()
  {
    std::cout << this->name << ": My job here is done!" << std::endl;
    std::vector<ASpell *>::iterator it_b = this->arr.begin();
    std::vector< ASpell *>::iterator it_e = this->arr.end();
    while(it_b != it_e)
    {
      delete (*it_b);
      ++it_b;
    }
    this->arr.clear();
  }
//-----------------------------------------------------------------------------
  const std::string &Warlock::getName() const   {return(this->name);}
  const std::string &Warlock::getTitle() const  {return(this->title);}
//-----------------------------------------------------------------------------
  void Warlock::setTitle(std::string const & title) {this->title = title;}
//-----------------------------------------------------------------------------
  void Warlock::introduce() const
  {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
  }
//-----------------------------------------------------------------------------
  void Warlock::learnSpell(ASpell *as)
  {
    std::vector<ASpell *>::iterator it_b = this->arr.begin();
    std::vector< ASpell *>::iterator it_e = this->arr.end();

    if(as)
    {
      while(it_b != it_e)
      {
        if((*it_b)->getName() == as->getName())
          return;
        ++it_b;
      }
      this->arr.push_back(as->clone());
    }
  }
//-----------------------------------------------------------------------------
  void Warlock::forgetSpell(std::string const & name)
  {
    std::vector<ASpell *>::iterator it_b = this->arr.begin();
    std::vector< ASpell *>::iterator it_e = this->arr.end();

    while(it_b != it_e)
    {
      if((*it_b)->getName() == name)
      {
        delete (*it_b);
        this->arr.erase(it_b);
        return;
      }
      ++it_b;
    }
  }
//-----------------------------------------------------------------------------
  void Warlock::launchSpell(const std::string &name, const ATarget &at)
  {
    std::vector<ASpell *>::iterator it_b = this->arr.begin();
    std::vector< ASpell *>::iterator it_e = this->arr.end();

    while(it_b != it_e)
    {
      if((*it_b)->getName() == name)
      {
        (*it_b)->launch(at);
        return;
      }
      ++it_b;
    }
  }

//---------------------------------------------
int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
