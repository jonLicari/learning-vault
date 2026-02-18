#include "review.h"
#include "productreview.h"
#include "restaurantreview.h"
#include <vector>

double calculateAverageRating(std::vector<ProductReview> &productReviews,
                              std::vector<RestaurantReview> &restaurantReviews)
{
  double sum = 0;
  int count = 0;

  // Process product reviews
  for (const auto &review : productReviews)
  {
    sum += review.getRating();
    ++count;
  }

  // Process restaurant reviews
  for (const auto &review : restaurantReviews)
  {
    sum += review.getRating();
    ++count;
  }

  return count > 0 ? sum / count : 0;
}

int main()
{
  // Create collections for reviews
  std::vector<ProductReview> productReviews;
  std::vector<RestaurantReview> restaurantReviews;

  // Add product reviews
  productReviews.push_back(ProductReview(5,
                                         "Professional tool",
                                         "Great for the price compared to higher priced fluke meters.",
                                         "PJ6JBG42557E1F560V7V",
                                         "Multi Testers",
                                         true));

  productReviews.push_back(ProductReview(4,
                                         "Good laptop",
                                         "Fast and reliable, but battery life could be better.",
                                         "LT789XYZ",
                                         "Laptops",
                                         false));

  productReviews.push_back(ProductReview(3,
                                         "Decent headphones",
                                         "Good sound quality but not very comfortable for long sessions.",
                                         "HP123ABC",
                                         "Audio",
                                         false));

  // Add restaurant reviews
  restaurantReviews.push_back(RestaurantReview(4,
                                               "Overpriced",
                                               "The food was delicious. However, the prices are way too high.",
                                               "Sushi & Japanese Steakhouse",
                                               true,
                                               5));

  restaurantReviews.push_back(RestaurantReview(5,
                                               "Best Italian in town",
                                               "Authentic pasta dishes and great service.",
                                               "Italian",
                                               false,
                                               4));

  restaurantReviews.push_back(RestaurantReview(2,
                                               "Disappointing",
                                               "Long wait times and cold food.",
                                               "American Diner",
                                               true,
                                               3));

  // Display all reviews
  std::cout << "\nProduct Reviews:\n";
  for (const auto &review : productReviews)
  {
    review.displayDetails();
    std::cout << "\n";
  }

  std::cout << "\nRestaurant Reviews:\n";
  for (const auto &review : restaurantReviews)
  {
    review.displayDetails();
    std::cout << "\n";
  }

  // Calculate and display average rating
  double avgRating = calculateAverageRating(productReviews, restaurantReviews);
  std::cout << "\nAverage Rating across all reviews: " << avgRating << "/5\n";

  return 0;
}