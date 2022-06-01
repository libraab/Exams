#pragma once

#include <iostream>
#include <vector>
#include "ATarget.hpp"
class TargetGenerator
{
private:
std::vector<ATarget *> arr_t;

TargetGenerator(TargetGenerator const & other);
TargetGenerator & operator=(TargetGenerator const & other);

public:
TargetGenerator();
~TargetGenerator();

void learnTargetType(ATarget *as);
void forgetTargetType(std::string const &name);
ATarget *createTarget(std::string const &name);
};
