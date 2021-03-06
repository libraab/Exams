#pragma once
#include <iostream>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *as);
		void forgetTargetType(std::string const &name);
		ATarget *createTarget(std::string const &name);

	private:
		std::vector<ATarget *> ar;
		TargetGenerator(TargetGenerator const &cpy);
		TargetGenerator &operator = (TargetGenerator const &op);
};
