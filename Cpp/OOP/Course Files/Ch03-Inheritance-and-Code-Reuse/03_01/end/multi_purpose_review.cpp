#include "multi_purpose_review.h"

MultiPurposeReview::MultiPurposeReview(unsigned int r,
                                       const std::string &t,
                                       const std::string &txt,
                                       const std::string &id,
                                       const std::string &cat,
                                       const std::string &type,
                                       bool delivery)
{
  setRating(r);
  setTitle(t);
  setText(txt);
  setProductId(id);
  setCategory(cat);
  setCuisine(type);
  setHasDelivery(delivery);
}

MultiPurposeReview::~MultiPurposeReview()
{
  std::cout << "\nMultiPurposeReview object is being deleted." << std::endl;
}

void MultiPurposeReview::displayDetails() const
{
  std::cout << "Rating: " << rating << "/5\n"
            << "Title: " << title << "\n"
            << "Text: " << text << "\n"
            << "Product ID: " << productId << "\n"
            << "Category: " << category << "\n"
            << "Cuisine: " << cuisine << "\n"
            << "Has Delivery: " << (hasDelivery ? "Yes" : "No") << std::endl;
  ;
}

void MultiPurposeReview::setRating(unsigned int r)
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

void MultiPurposeReview::setTitle(const std::string &t)
{
  title = validateAndTrim(t, MAX_TITLE_LENGTH, "Title");
}

void MultiPurposeReview::setText(const std::string &txt)
{
  text = validateAndTrim(txt, MAX_TEXT_LENGTH, "Review text");
}

void MultiPurposeReview::setProductId(const std::string &id)
{
  productId = validateAndTrim(id, MAX_PRODUCTID_LENGTH, "Product Id");
}

void MultiPurposeReview::setCategory(const std::string &cat)
{
  category = validateAndTrim(cat, MAX_CATEGORY_LENGTH, "Product category");
}

void MultiPurposeReview::setCuisine(const std::string &type)
{
  cuisine = validateAndTrim(type, MAX_CUISINE_LENGTH, "Cuisine");
}

void MultiPurposeReview::setHasDelivery(bool delivery)
{
  hasDelivery = delivery;
}

std::string MultiPurposeReview::validateAndTrim(const std::string &str,
                                                unsigned int maxLength,
                                                const std::string &fieldName) const
{
  if (str.empty())
  {
    throw std::invalid_argument(fieldName + " cannot be empty");
  }
  return str.length() > maxLength ? str.substr(0, maxLength) : str;
}