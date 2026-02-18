#include "restaurantreview.h"

RestaurantReview::RestaurantReview(unsigned int r,
                                   const std::string &t,
                                   const std::string &txt,
                                   const std::string &type,
                                   bool delivery)
{
  setRating(r);
  setTitle(t);
  setText(txt);
  setCuisine(type);
  setHasDelivery(delivery);
}

RestaurantReview::~RestaurantReview()
{
  std::cout << "\nRestaurantReview object is being deleted." << std::endl;
}

void RestaurantReview::displayDetails() const
{
  std::cout << "\nRestaurant Rating: " << rating << "/5\n"
            << "Title: " << title << "\n"
            << "Text: " << text << "\n"
            << "Cuisine: " << cuisine << "\n"
            << "Has Delivery: " << (hasDelivery ? "Yes" : "No") << std::endl;
}

void RestaurantReview::setRating(unsigned int r)
{
  if (r < MIN_RATING || r > MAX_RATING)
  {
    throw std::invalid_argument("Rating must be between 1 and 5");
  }
  else
  {
    rating = r;
  }
}

void RestaurantReview::setTitle(const std::string &t)
{
  title = validateAndTrim(t, MAX_TITLE_LENGTH, "Title");
}

void RestaurantReview::setText(const std::string &txt)
{
  text = validateAndTrim(txt, MAX_TEXT_LENGTH, "Review text");
}

void RestaurantReview::setCuisine(const std::string &type)
{
  cuisine = validateAndTrim(type, MAX_CUISINE_LENGTH, "Cuisine");
}

void RestaurantReview::setHasDelivery(bool delivery)
{
  hasDelivery = delivery;
}

std::string RestaurantReview::validateAndTrim(const std::string &str,
                                              unsigned int maxLength,
                                              const std::string &fieldName) const
{
  if (str.empty())
  {
    throw std::invalid_argument(fieldName + " cannot be empty");
  }
  return str.length() > maxLength ? str.substr(0, maxLength) : str;
}