#include "sociable.h"

void Sociable::addComment(const std::string &comment)
{
    comments.push_back(comment);
}

void Sociable::displaySocialStats() const
{
    std::cout << likes << " likes, "
              << shares << " shares, "
              << comments.size() << " comments" << std::endl;
}