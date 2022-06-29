#pragma once 
#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <vector>

class Warlock
{
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		
		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);
		void introduce() const;

		void learnSpell(ASpell *as) ;
		void forgetSpell(const std::string &name) ;
		void launchSpell(const std::string &name, const ATarget &at) ;

	private:
		Warlock(const Warlock &cpy);
		std::string  name;
		std::string  title;
		Warlock &operator = (const Warlock &op);
		std::vector <ASpell *> ar;
};
