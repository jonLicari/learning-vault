#ifndef RESTAURANT_REVIEW_H
#define RESTAURANT_REVIEW_H

#include <iostream>
#include "review.h"

class RestaurantReview : public Review
{
public:
  RestaurantReview(unsigned int r,
                   const std::string &t,
                   const std::string &txt,
                   const std::string &type,
                   bool delivery,
                   unsigned int service);

  ~RestaurantReview();
  unsigned int getRating() const;
  void displayDetails() const;

  unsigned int getServiceRating() const { return serviceRating; }
  std::string getCuisine() const { return cuisine; }
  bool getHasDelivery() const { return hasDelivery; }

  void setCuisine(const std::string &type);
  void setHasDelivery(bool delivery);
  void setServiceRating(unsigned int service);

private:
  static const unsigned int MAX_TEXT_LENGTH = 1024;
  static const unsigned int MAX_CUISINE_LENGTH = 128;
  static const unsigned int MIN_SERVICE_RATING = 1;
  static const unsigned int MAX_SERVICE_RATING = 5;

  std::string cuisine;
  bool hasDelivery;
  unsigned int serviceRating;
};

#endif