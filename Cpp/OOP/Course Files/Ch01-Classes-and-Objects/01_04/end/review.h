#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>

class Review
{
public:
  void displayDetails() const;

private:
  unsigned int rating;
  std::string title;
  std::string text;
};

#endif