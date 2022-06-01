#pragma once
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <iostream>
#include <string>
#include <vector>

class Warlock
{
    public:
        Warlock(std::string const & name, std::string const & title);
        ~Warlock();

        const std::string &getName() const;
        const std::string &getTitle() const;

        void setTitle(const std::string &title);
        void introduce() const;

        void learnSpell(ASpell *as);
        void forgetSpell(const std::string &name);
        void launchSpell(const std::string &name, const ATarget &at);

    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(const Warlock &other);
        Warlock &operator = (const Warlock &other);
        std::vector<ASpell *> arr;
    
};
