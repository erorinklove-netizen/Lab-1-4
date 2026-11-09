#pragma once
#include <string>

class Rectangle {
private:
    double x1, y1; // Bottom-left corner
    double x2, y2; // Top-right corner

public:
    // Constructors
    Rectangle();
    Rectangle(double px1, double py1, double px2, double py2);

    // Getters (const)
    double GetX1() const;
    double GetY1() const;
    double GetX2() const;
    double GetY2() const;

    // Setters with validation
    bool SetX1(double value);
    bool SetY1(double value);
    bool SetX2(double value);
    bool SetY2(double value);
    bool SetCoordinates(double px1, double py1, double px2, double py2);

    // Required methods
    bool Init(double px1, double py1, double px2, double py2);
    void Read();
    void Display() const;
    std::string toString() const;

    // Variant specific methods
    double Area() const;
    double Perimeter() const;
    void Move(double dx, double dy);
    void Resize(double newWidth, double newHeight);

    // Smallest rectangle containing two given rectangles (Bounding Box)
    static Rectangle BoundingBox(const Rectangle& r1, const Rectangle& r2);

    // Rectangle representing the intersection of two rectangles
    static Rectangle Intersection(const Rectangle& r1, const Rectangle& r2, bool& success);
};