#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();

		virtual ATarget *clone() const;
};
