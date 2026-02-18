#include "review.h"

void Review::displayDetails() const
{
  std::cout << "Rating: " << rating << "/5\nTitle: " << title << "\nText: " << text << std::endl;
}