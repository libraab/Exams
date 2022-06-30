#pragma once 
#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;
class ASpell
{
	public:
		ASpell(const std::string &name, const std::string &effects);
		virtual ~ASpell();
		const std::string &getName() const;
		const std::string &getEffects() const ;
		void launch(const ATarget &at) const;
		ASpell &operator = (const ASpell &op);
		ASpell(const ASpell &cpy);

		virtual ASpell *clone() const = 0;
		
	protected:
		std::string  name;
		std::string  effects;
};
