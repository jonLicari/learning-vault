#include "productreview.h"

ProductReview::ProductReview(unsigned int r,
                             const std::string &t,
                             const std::string &txt,
                             const std::string &id,
                             const std::string &cat,
                             bool verified) : Review(r, t, txt), isVerified(verified)
{
  setProductId(id);
  setCategory(cat);
}

ProductReview::~ProductReview()
{
  std::cout << "\nProductReview object is being deleted." << std::endl;
}

unsigned int ProductReview::getRating() const
{
  // Verified purchases get a small rating boost
  return isVerified ? std::min(Review::getRating() + 1, 5u) : Review::getRating();
}

void ProductReview::displayDetails() const
{
  if (category == "Featured")
  {
    // Special format for featured products
    std::cout << "FEATURED PRODUCT REVIEW\n"
              << "Product: " << productId << "\n"
              << "Category: " << category << "\n"
              << (isVerified ? "Verified purchase" : "") << "\n";
    Review::displayDetails(); // Use base class format for the rest
  }
  else
  {
    Review::displayDetails(); // Use base format
    std::cout << "Product ID: " << productId << std::endl;
  }
}

void ProductReview::setProductId(const std::string &id)
{
  productId = Review::validateAndTrim(id, MAX_PRODUCTID_LENGTH, "Product Id");
}

void ProductReview::setCategory(const std::string &cat)
{
  category = Review::validateAndTrim(cat, MAX_CATEGORY_LENGTH, "Product category");
}
