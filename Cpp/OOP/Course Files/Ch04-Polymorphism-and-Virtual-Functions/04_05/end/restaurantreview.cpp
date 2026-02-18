#include "restaurantreview.h"
#include <cmath>

RestaurantReview::RestaurantReview(unsigned int r,
                                   const std::string &t,
                                   const std::string &txt,
                                   const std::string &type,
                                   bool delivery,
                                   unsigned int service) : Review(r, t, txt), serviceRating(service)
{
  setCuisine(type);
  setHasDelivery(delivery);
}

RestaurantReview::~RestaurantReview()
{
  std::cout << "\nRestaurantReview object is being deleted." << std::endl;
}

unsigned int RestaurantReview::getRating() const
{
  // Overall rating is average of food and service
  return (Review::getRating() + serviceRating) / 2;
}

void RestaurantReview::displayDetails() const
{
  Review::displayDetails();
  std::cout << "Cuisine: " << cuisine << "\n"
            << "Has Delivery: " << (hasDelivery ? "Yes" : "No") << "\n"
            << "Service rating: " << serviceRating << std::endl;
}

float RestaurantReview::analyzeSentiment() const
{
  float textSentiment = (float)rand() / RAND_MAX; // Random value between 0 and 1
  // Restaurant reviews focus more on text sentiment
  float sentiment = (textSentiment * 0.7f) + ((getRating() / 5.0f) * 0.3f);
  return roundf(sentiment * 100) / 100;
}

void RestaurantReview::setCuisine(const std::string &type)
{
  cuisine = Review::validateAndTrim(type, MAX_CUISINE_LENGTH, "Cuisine");
}

void RestaurantReview::setHasDelivery(bool delivery)
{
  hasDelivery = delivery;
}

void RestaurantReview::setServiceRating(unsigned int service)
{
  if (service < MIN_SERVICE_RATING || service > MAX_SERVICE_RATING)
  {
    throw std::invalid_argument("Rating must be between 1 and 5");
  }
  else
  {
    serviceRating = service;
  }
}