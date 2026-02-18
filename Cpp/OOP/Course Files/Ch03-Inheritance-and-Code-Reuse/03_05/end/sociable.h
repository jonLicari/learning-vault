#ifndef SOCIABLE_H
#define SOCIABLE_H

#include <iostream>
#include <vector>

class Sociable
{
public:
    void like() { ++likes; }
    void share() { ++shares; }

    void addComment(const std::string &comment);
    void displaySocialStats() const;

protected:
    unsigned int likes = 0;
    unsigned int shares = 0;
    std::vector<std::string> comments;
};

#endif