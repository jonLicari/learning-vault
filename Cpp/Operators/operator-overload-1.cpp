#include <iostream>

struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 Add(const Vector2 & other ) const {
        return Vector2(x + other.x, y + other.y);
    }

    // Overload the + operator to make + symbolic of the Add() function
    Vector2 operator+(const Vector2 & other) const {
        return Add(other);
    }

    Vector2 Multiply(const Vector2 & other ) const {
        return Vector2(x * other.x, y * other.y);
    }

    // Overload the * operator to make * symbolic of the Multiply() function
    Vector2 operator*(const Vector2 & other) const {
        return Multiply(other);
    }

};

// define the overload of << outside of Vector2 bc it has nothing to do with this object
// output stream reference is the original type of the << operator
// We take in std::ostream& stream as a parameter since we need a reference to the original stream (in this case, std::cout)
std::ostream& operator<<(std::ostream& stream, const Vector2& obj) {
    stream << obj.x << ", " << obj.y;
    return stream;
}

int main() {
    Vector2 position(4.0f, 5.0f);
    Vector2 speed(3.0f, 6.0f);
    Vector2 powerup(1.2f, 1.5f);

    Vector2 result = position.Add(speed.Multiply(powerup)); // ! PROBLEM: This is hard af to read 
    // We can overload operators to redefine their behaviour to make this more readable

    // Now that I defined the operator overload, i can write readable syntax like this
    Vector2 overload = position + speed * powerup;

    // This will not work unless we overload <<
    // cout takes a string but Vector2 is not a string
    // we can overload << to print the members of Vector2 in an output stream and return the stream reference
    std::cout << overload << std::endl; 

    return 0;
}