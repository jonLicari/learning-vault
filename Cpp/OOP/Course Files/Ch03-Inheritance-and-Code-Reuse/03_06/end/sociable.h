#ifndef SOCIABLE_H
#define SOCIABLE_H

#include <iostream>
#include <vector>
#include <ctime>

class Sociable
{
public:
    Sociable() : timestamp(std::time(nullptr)) {}

    void like() { ++likes; }
    void share() { ++shares; }

    void addComment(const std::string &comment);
    void displaySocialStats() const;

    std::time_t getTimestamp() const { return timestamp; }

protected:
    unsigned int likes = 0;
    unsigned int shares = 0;
    std::vector<std::string> comments;
    std::time_t timestamp;
};

#endif