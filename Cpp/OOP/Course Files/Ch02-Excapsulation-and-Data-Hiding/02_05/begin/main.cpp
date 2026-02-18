#include "review.h"
#include "reviewbot.h"

int main()
{
  Review review = Review(5, "excellent", "exceeded my expectations");
  review.displayDetails();

  std::cout << "\nAfter formatting\n" << std::endl;

  ReviewBot bot;
  bot.fixFormatting(review);
  review.displayDetails();

  return 0;
}