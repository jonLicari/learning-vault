#include "restaurantreview.h"

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