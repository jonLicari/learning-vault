#include "review.h"

int main()
{
  Review review = Review(5, "Excellent", "Exceeded my expectations");
  review.displayDetails();

  review.setRating(6);
  review.setTitle("Good");
  review.setTitle("Almost perfect!");
  review.displayDetails();

  return 0;
}