#include "productreview.h"

ProductReview::ProductReview(unsigned int r,
                             const std::string &t,
                             const std::string &txt,
                             const std::string &id,
                             const std::string &cat) : Review(r, t, txt)
{
  setProductId(id);
  setCategory(cat);
}

ProductReview::~ProductReview()
{
  std::cout << "\nProductReview object is being deleted." << std::endl;
}

void ProductReview::displayDetails() const
{
  Review::displayDetails();
  std::cout << "Product ID: " << productId << "\n"
            << "Category: " << category << std::endl;
}

void ProductReview::setProductId(const std::string &id)
{
  productId = Review::validateAndTrim(id, MAX_PRODUCTID_LENGTH, "Product Id");
}

void ProductReview::setCategory(const std::string &cat)
{
  category = Review::validateAndTrim(cat, MAX_CATEGORY_LENGTH, "Product category");
}
