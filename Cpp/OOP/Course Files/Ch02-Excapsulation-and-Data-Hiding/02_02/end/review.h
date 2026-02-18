#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>

class Review
{
public:
  Review(unsigned int r, const std::string &t, const std::string &txt);
  ~Review();

  void displayDetails() const;

  unsigned int getRating() const { return rating; }
  std::string getTitle() const { return title; }
  std::string getText() const { return text; }

  void setRating(unsigned int r);
  void setTitle(const std::string &t);
  void setText(const std::string &txt);

private:
  unsigned int rating;
  std::string title;
  std::string text;
};

#endif