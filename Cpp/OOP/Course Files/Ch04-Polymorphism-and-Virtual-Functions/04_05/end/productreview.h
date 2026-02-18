#ifndef PRODUCT_REVIEW_H
#define PRODUCT_REVIEW_H

#include <iostream>
#include "review.h"

class ProductReview : public Review
{
public:
  ProductReview(unsigned int r,
                const std::string &t,
                const std::string &txt,
                const std::string &id,
                const std::string &cat,
                bool verified);

  ~ProductReview();

  unsigned int getRating() const override;
  void displayDetails() const override;

  float analyzeSentiment() const override;

  std::string getProductId() const { return productId; }
  std::string getCategory() const { return category; }

  void setProductId(const std::string &id);
  void setCategory(const std::string &cat);

private:
  static const unsigned int MAX_PRODUCTID_LENGTH = 64;
  static const unsigned int MAX_CATEGORY_LENGTH = 512;

  std::string productId;
  std::string category;
  bool isVerified;
};

#endif