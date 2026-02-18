#include "review.h"

int main()
{
  Review review = Review(5, "Excellent", "Exceeded my expectations");
  review.displayDetails();

  // review.rating = 0;
  // review.text = "";

  return 0;
}