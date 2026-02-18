#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>

class Review
{
public:
  Review(unsigned int r, const std::string &t, const std::string &txt);
  ~Review();

  void displayDetails() const;

private:
  unsigned int rating;
  std::string title;
  std::string text;
};

#endif