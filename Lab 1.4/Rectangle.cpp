#include "Rectangle.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

// Constructors
Rectangle::Rectangle() {
    x1 = 0; y1 = 0;
    x2 = 1; y2 = 1;
}

Rectangle::Rectangle(double px1, double py1, double px2, double py2) {
    if (!Init(px1, py1, px2, py2)) {
        x1 = 0; y1 = 0;
        x2 = 1; y2 = 1;
    }
}

// Getters
double Rectangle::GetX1() const { return x1; }
double Rectangle::GetY1() const { return y1; }
double Rectangle::GetX2() const { return x2; }
double Rectangle::GetY2() const { return y2; }

// Setters with validation
bool Rectangle::SetX1(double value) {
    if (value < x2) {
        x1 = value;
        return true;
    }
    return false;
}

bool Rectangle::SetY1(double value) {
    if (value < y2) {
        y1 = value;
        return true;
    }
    return false;
}

bool Rectangle::SetX2(double value) {
    if (value > x1) {
        x2 = value;
        return true;
    }
    return false;
}

bool Rectangle::SetY2(double value) {
    if (value > y1) {
        y2 = value;
        return true;
    }
    return false;
}

bool Rectangle::SetCoordinates(double px1, double py1, double px2, double py2) {
    if (px1 < px2 && py1 < py2) {
        x1 = px1;
        y1 = py1;
        x2 = px2;
        y2 = py2;
        return true;
    }
    return false;
}

// Initialization
bool Rectangle::Init(double px1, double py1, double px2, double py2) {
    return SetCoordinates(px1, py1, px2, py2);
}

// Input from keyboard
void Rectangle::Read() {
    double px1, py1, px2, py2;
    do {
        cout << "Enter bottom-left corner coordinates (x1 y1): ";
        cin >> px1 >> py1;
        cout << "Enter top-right corner coordinates (x2 y2): ";
        cin >> px2 >> py2;
        if (!Init(px1, py1, px2, py2)) {
            cout << "Error: x2 must be greater than x1, and y2 greater than y1! Try again.\n";
        }
    } while (!Init(px1, py1, px2, py2));
}

// Display on screen
void Rectangle::Display() const {
    cout << toString() << endl;
}

// Convert to string
string Rectangle::toString() const {
    stringstream ss;
    ss << "Rectangle [Bottom-Left: (" << x1 << ", " << y1
        << "), Top-Right: (" << x2 << ", " << y2
        << "), Width: " << (x2 - x1) << ", Height: " << (y2 - y1) << "]";
    return ss.str();
}

// Additional methods
double Rectangle::Area() const {
    return (x2 - x1) * (y2 - y1);
}

double Rectangle::Perimeter() const {
    return 2 * ((x2 - x1) + (y2 - y1));
}

void Rectangle::Move(double dx, double dy) {
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
}

void Rectangle::Resize(double newWidth, double newHeight) {
    if (newWidth > 0 && newHeight > 0) {
        x2 = x1 + newWidth;
        y2 = y1 + newHeight;
    }
}

// Bounding box (smallest rectangle containing both)
Rectangle Rectangle::BoundingBox(const Rectangle& r1, const Rectangle& r2) {
    double min_x1 = min(r1.x1, r2.x1);
    double min_y1 = min(r1.y1, r2.y1);
    double max_x2 = max(r1.x2, r2.x2);
    double max_y2 = max(r1.y2, r2.y2);
    return Rectangle(min_x1, min_y1, max_x2, max_y2);
}

// Intersection of two rectangles
Rectangle Rectangle::Intersection(const Rectangle& r1, const Rectangle& r2, bool& success) {
    double int_x1 = max(r1.x1, r2.x1);
    double int_y1 = max(r1.y1, r2.y1);
    double int_x2 = min(r1.x2, r2.x2);
    double int_y2 = min(r1.y2, r2.y2);

    if (int_x1 < int_x2 && int_y1 < int_y2) {
        success = true;
        return Rectangle(int_x1, int_y1, int_x2, int_y2);
    }
    else {
        success = false;
        return Rectangle(0, 0, 1, 1);
    }
}