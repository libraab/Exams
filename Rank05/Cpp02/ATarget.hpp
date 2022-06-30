#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;
class ATarget
{
	public:
		ATarget(const std::string &type);
		virtual ~ATarget();
		const std::string &getType() const;
		void getHitBySpell(const ASpell &as)const;
		ATarget &operator = (const ATarget &op);
		ATarget(const ATarget &cpy);

		virtual ATarget *clone() const = 0;

	private:
		std::string  type;
};
