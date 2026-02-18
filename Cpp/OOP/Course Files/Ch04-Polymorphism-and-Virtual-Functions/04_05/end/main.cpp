#include "review.h"
#include "productreview.h"
#include "restaurantreview.h"
#include <vector>

double calculateAverageRating(const std::vector<Review *> &reviews)
{
  if (reviews.empty())
    return 0.0;

  double sum = 0;
  for (const Review *review : reviews)
  {
    sum += review->getRating(); // Calls the right version automatically!
  }
  return sum / reviews.size();
}

int main()
{
  srand(time(0)); // Seed the random generator
  // Create collections for reviews
  std::vector<Review *> reviews;

  // Add product reviews
  reviews.push_back(new ProductReview(5,
                                      "Professional tool",
                                      "Great for the price compared to higher priced fluke meters.",
                                      "PJ6JBG42557E1F560V7V",
                                      "Multi Testers",
                                      true));

  reviews.push_back(new ProductReview(4,
                                      "Good laptop",
                                      "Fast and reliable, but battery life could be better.",
                                      "LT789XYZ",
                                      "Laptops",
                                      false));

  reviews.push_back(new ProductReview(3,
                                      "Decent headphones",
                                      "Good sound quality but not very comfortable for long sessions.",
                                      "HP123ABC",
                                      "Audio",
                                      false));

  // Add restaurant reviews
  reviews.push_back(new RestaurantReview(4,
                                         "Overpriced",
                                         "The food was delicious. However, the prices are way too high.",
                                         "Sushi & Japanese Steakhouse",
                                         true,
                                         5));

  reviews.push_back(new RestaurantReview(5,
                                         "Best Italian in town",
                                         "Authentic pasta dishes and great service.",
                                         "Italian",
                                         false,
                                         4));

  reviews.push_back(new RestaurantReview(2,
                                         "Disappointing",
                                         "Long wait times and cold food.",
                                         "American Diner",
                                         true,
                                         3));

  std::cout << "\nReviews:\n";
  for (const auto &review : reviews)
  {
    review->displayDetails();

    std::cout << "Sentiment: " << review->analyzeSentiment() << std::endl;
    std::cout << "\n";
  }

  // Calculate and display average rating
  double avgRating = calculateAverageRating(reviews);
  std::cout << "\nAverage Rating across all reviews: " << avgRating << "/5\n";

  // cleanup
  for (Review *review : reviews)
  {
    delete review; // Clean up each review
  }
  reviews.clear(); // Clear the vector of now-invalid pointers

  return 0;
}