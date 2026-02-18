#include "review.h"

Review::Review(unsigned int r,
               const std::string &t,
               const std::string &txt) : timestamp(std::time(nullptr))
{
  setRating(r);
  setTitle(t);
  setText(txt);
}

Review::~Review()
{
  std::cout << "\nReview object is being deleted." << std::endl;
}

void Review::displayDetails() const
{
  std::cout << "\nRating: " << rating << "/5\n"
            << "Title: " << title << "\n"
            << "Text: " << text << std::endl;
}

void Review::setRating(unsigned int r)
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

void Review::setTitle(const std::string &t)
{
  title = validateAndTrim(t, MAX_TITLE_LENGTH, "Title");
}

void Review::setText(const std::string &txt)
{
  text = validateAndTrim(txt, MAX_TEXT_LENGTH, "Review text");
}

std::string Review::validateAndTrim(const std::string &str,
                                    unsigned int maxLength,
                                    const std::string &fieldName) const
{
  if (str.empty())
  {
    throw std::invalid_argument(fieldName + " cannot be empty");
  }
  return str.length() > maxLength ? str.substr(0, maxLength) : str;
}