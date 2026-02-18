#include "restaurantreview.h"

RestaurantReview::RestaurantReview(unsigned int r,
                                   const std::string &t,
                                   const std::string &txt,
                                   const std::string &type,
                                   bool delivery) : Review(r, t, txt)
{
  setCuisine(type);
  setHasDelivery(delivery);
}

RestaurantReview::~RestaurantReview()
{
  std::cout << "\nRestaurantReview object is being deleted." << std::endl;
}

void RestaurantReview::displayDetails() const
{
  Review::displayDetails();
  std::cout << "Cuisine: " << cuisine << "\n"
            << "Has Delivery: " << (hasDelivery ? "Yes" : "No") << std::endl;
}

void RestaurantReview::setCuisine(const std::string &type)
{
  cuisine = Review::validateAndTrim(type, MAX_CUISINE_LENGTH, "Cuisine");
}

void RestaurantReview::setHasDelivery(bool delivery)
{
  hasDelivery = delivery;
}
