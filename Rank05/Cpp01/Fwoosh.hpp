#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();

		virtual ASpell *clone() const;
};
