#include "review.h"
#include "productreview.h"
#include "restaurantreview.h"

int main()
{
  Review review = Review(5, "excellent", "exceeded my expectations");
  review.displayDetails();

  ProductReview productReview = ProductReview(5,
                                              "Professional tool",
                                              "Great for the price in comparison to higher priced fluke meters.",
                                              "PJ6JBG42557E1F560V7V",
                                              "Multi Testers");
  productReview.displayDetails();

  RestaurantReview restaurantReview = RestaurantReview(4,
                                                       "Overpriced",
                                                       "The food was delicious. However, the prices are way too high.",
                                                       "Sushi & Japanese Steakhouse",
                                                       true);
  restaurantReview.displayDetails();

  return 0;
}