#ifndef PRODUCT_REVIEW_H
#define PRODUCT_REVIEW_H

#include <iostream>

class ProductReview
{
public:
  ProductReview(unsigned int r,
                const std::string &t,
                const std::string &txt,
                const std::string &id,
                const std::string &cat);

  ~ProductReview();
  void displayDetails() const;

  unsigned int getRating() const { return rating; }
  std::string getTitle() const { return title; }
  std::string getText() const { return text; }
  std::string getProductId() const { return productId; }
  std::string getCategory() const { return category; }

  void setRating(unsigned int r);
  void setTitle(const std::string &t);
  void setText(const std::string &txt);
  void setProductId(const std::string &id);
  void setCategory(const std::string &cat);

private:
  static const unsigned int MIN_RATING = 1;
  static const unsigned int MAX_RATING = 5;
  static const unsigned int MAX_TITLE_LENGTH = 128;
  static const unsigned int MAX_TEXT_LENGTH = 1024;
  static const unsigned int MAX_PRODUCTID_LENGTH = 64;
  static const unsigned int MAX_CATEGORY_LENGTH = 512;

  std::string validateAndTrim(const std::string &str,
                              unsigned int maxLength,
                              const std::string &fieldName) const;

  unsigned int rating;
  std::string title;
  std::string text;

  // Product-specific members
  std::string productId;
  std::string category;
};

#endif