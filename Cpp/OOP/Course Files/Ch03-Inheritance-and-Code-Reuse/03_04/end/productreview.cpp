#include "productreview.h"

ProductReview::ProductReview(unsigned int r,
                             const std::string &t,
                             const std::string &txt,
                             const std::string &id,
                             const std::string &cat) : Review(r, t, txt)
{
  // setRating(r);
  // setTitle(t);
  // setText(txt);
  setProductId(id);
  setCategory(cat);
}

ProductReview::~ProductReview()
{
  std::cout << "\nProductReview object is being deleted." << std::endl;
}

// Extends the base behavior
/*void ProductReview::displayDetails() const
{
  // std::cout << "Posted on: " << timestamp << std::endl; // Error: ambiguous!
  //std::cout << "Review posted: " << Review::timestamp << "\n"
  //          << "Last social activity: " << Sociable::timestamp << std::endl;
  std::cout << "Review posted: " << Review::timestamp << "\n"
            << "Last social activity: " << Sociable::timestamp << std::endl;

  Review::displayDetails();
  std::cout << "Product ID: " << productId << "\n"
            << "Category: " << category << std::endl;
}*/

// Compact version - completely replaces base behavior
/*void ProductReview::displayDetails() const {
    // Completely different format, ignoring base class version
    std::cout << "PRODUCT REVIEW\n"
              << "==============\n"
              << productId << " (" << category << ")\n"
              << "Rating: " << getRating() << "/5\n"
              << getText() << std::endl;
}*/

void ProductReview::displayDetails() const 
{
    if (category == "Featured") 
    {
        // Special format for featured products
        std::cout << "FEATURED PRODUCT REVIEW\n"
                  << "Product: " << productId << "\n"
                  << "Category: " << category << "\n";
        Review::displayDetails();  // Use base class format for the rest
    } 
    else 
    {
        Review::displayDetails();  // Use base format
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
