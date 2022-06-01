#pragma once
#include <string>
#include <iostream>

class Warlock
{
    public:
    Warlock(const std::string &name, const std::string &title);
    ~Warlock();

    const std::string &getName() const;
    const std::string &getTitle() const;

    void setTitle(const std::string &title);
    void introduce() const;

    private:
    std::string name;
    std::string title;

    Warlock();
    Warlock(Warlock const &other);
    Warlock &operator = (const Warlock &other);
};