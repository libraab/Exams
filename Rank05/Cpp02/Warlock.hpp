#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
class Warlock
{
private:
std::string name;
std::string title;

Warlock();
Warlock(Warlock const & other);
Warlock & operator=(Warlock const & other);
SpellBook b;
public:
Warlock(std::string const & name, std::string const & title);
~Warlock();

std::string const & getName() const;
std::string const & getTitle() const;

void setTitle(std::string const & title);
void introduce() const;

void learnSpell(ASpell *as);
void forgetSpell(std::string const & name);
void launchSpell(std::string const & name, ATarget const & at);
};
