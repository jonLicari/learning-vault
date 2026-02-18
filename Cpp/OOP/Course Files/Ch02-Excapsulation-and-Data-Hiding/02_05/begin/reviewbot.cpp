#include "reviewbot.h"
#include "review.h"
#include <iostream>

void ReviewBot::fixFormatting(Review &review)
{
  // Get the text, fix it, then set it back
  std::string text = review.getText();
  std::string title = review.getTitle();

  // Capitalize first letter of sentences
  title[0] = toupper(title[0]);
  text[0] = toupper(text[0]);

  // Remove extra spaces
  // ... formatting logic ...

  // Update the review using setters
  review.setTitle(title); // Triggers validation
  review.setText(text);   // Triggers validation again
}