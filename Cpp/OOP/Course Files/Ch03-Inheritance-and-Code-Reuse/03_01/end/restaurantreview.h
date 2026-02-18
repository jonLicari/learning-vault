#ifndef RESTAURANT_REVIEW_H
#define RESTAURANT_REVIEW_H

#include <iostream>

class RestaurantReview
{
public:
  RestaurantReview(unsigned int r,
                   const std::string &t,
                   const std::string &txt,
                   const std::string &type,
                   bool delivery);

  ~RestaurantReview();
  void displayDetails() const;

  unsigned int getRating() const { return rating; }
  std::string getTitle() const { return title; }
  std::string getText() const { return text; }
  std::string getCuisine() const { return cuisine; }
  bool getHasDelivery() const { return hasDelivery; }

  void setRating(unsigned int r);
  void setTitle(const std::string &t);
  void setText(const std::string &txt);
  void setCuisine(const std::string &type);
  void setHasDelivery(bool delivery);

private:
  static const unsigned int MIN_RATING = 1;
  static const unsigned int MAX_RATING = 5;
  static const unsigned int MAX_TITLE_LENGTH = 128;
  static const unsigned int MAX_TEXT_LENGTH = 1024;
  static const unsigned int MAX_CUISINE_LENGTH = 128;

  std::string validateAndTrim(const std::string &str,
                              unsigned int maxLength,
                              const std::string &fieldName) const;

  unsigned int rating;
  std::string title;
  std::string text;

  // Restaurant-specific members
  std::string cuisine;
  bool hasDelivery;
};

#endif