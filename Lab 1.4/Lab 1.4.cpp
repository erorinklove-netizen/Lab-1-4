#include <iostream>
#include "Rectangle.h"

using namespace std;

void ShowMenu() {
    cout << "\n================ RECTANGLE MANAGEMENT MENU ================\n";
    cout << "1. Create default rectangle and test Init\n";
    cout << "2. Input rectangle from keyboard (Read)\n";
    cout << "3. Demonstrate setters and getters (with validation)\n";
    cout << "4. Calculate area and perimeter\n";
    cout << "5. Move rectangle on the plane (Move)\n";
    cout << "6. Resize rectangle (Resize)\n";
    cout << "7. Build bounding box containing two rectangles\n";
    cout << "8. Find intersection of two rectangles\n";
    cout << "9. Demonstrate array of objects\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Rectangle rect1; // Default constructor
    Rectangle rect2(1, 1, 4, 5); // Parameterized constructor

    int choice;
    do {
        ShowMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\n--- Creation and Initialization ---\n";
            cout << "Rect1 (default): " << rect1.toString() << endl;
            cout << "Rect2 (parameterized): " << rect2.toString() << endl;

            Rectangle rect3;
            if (rect3.Init(0, 0, 5, 3)) {
                cout << "Rect3 successfully initialized via Init: " << rect3.toString() << endl;
            }
            break;
        }
        case 2: {
            cout << "\n--- Keyboard Input ---\n";
            rect1.Read();
            cout << "New state of rect1: ";
            rect1.Display();
            break;
        }
        case 3: {
            cout << "\n--- Setters, Getters & Validation ---\n";
            cout << "Current rect2: " << rect2.toString() << endl;
            cout << "Attempting to set x2 = 0 (which is less than x1 = 1): ";
            if (rect2.SetX2(0)) {
                cout << "Success\n";
            }
            else {
                cout << "Failed! Value rejected by class security rules.\n";
            }
            cout << "Attempting to set x2 = 6 (valid): ";
            if (rect2.SetX2(6)) {
                cout << "Success! New X2: " << rect2.GetX2() << endl;
            }
            cout << "Updated rect2: " << rect2.toString() << endl;
            break;
        }
        case 4: {
            cout << "\n--- Area and Perimeter (for rect2) ---\n";
            rect2.Display();
            cout << "Area: " << rect2.Area() << endl;
            cout << "Perimeter: " << rect2.Perimeter() << endl;
            break;
        }
        case 5: {
            double dx, dy;
            cout << "\n--- Move Rectangle rect2 ---\n";
            cout << "Enter shift along X and Y axes (dx dy): ";
            cin >> dx >> dy;
            rect2.Move(dx, dy);
            cout << "After moving: " << rect2.toString() << endl;
            break;
        }
        case 6: {
            double w, h;
            cout << "\n--- Resize Rectangle rect2 ---\n";
            cout << "Enter new width and height (>0): ";
            cin >> w >> h;
            rect2.Resize(w, h);
            cout << "After resizing: " << rect2.toString() << endl;
            break;
        }
        case 7: {
            cout << "\n--- Bounding Box ---\n";
            Rectangle rA(0, 0, 2, 2);
            Rectangle rB(3, 1, 5, 4);
            cout << "Rectangle A: " << rA.toString() << endl;
            cout << "Rectangle B: " << rB.toString() << endl;
            Rectangle box = Rectangle::BoundingBox(rA, rB);
            cout << "Smallest rectangle containing both: " << box.toString() << endl;
            break;
        }
        case 8: {
            cout << "\n--- Intersection of Rectangles ---\n";
            Rectangle rA(0, 0, 4, 4);
            Rectangle rB(2, 2, 6, 6);
            cout << "Rectangle A: " << rA.toString() << endl;
            cout << "Rectangle B: " << rB.toString() << endl;

            bool hasIntersection = false;
            Rectangle inter = Rectangle::Intersection(rA, rB, hasIntersection);
            if (hasIntersection) {
                cout << "Intersection found: " << inter.toString() << endl;
            }
            else {
                cout << "Rectangles do not intersect!\n";
            }
            break;
        }
        case 9: {
            cout << "\n--- Array of Objects Demonstration ---\n";
            const int size = 3;
            Rectangle arr[size] = {
                Rectangle(0, 0, 2, 2),
                Rectangle(1, 1, 4, 3),
                Rectangle(-2, -2, 0, 0)
            };
            for (int i = 0; i < size; i++) {
                cout << "Array object [" << i << "]: " << arr[i].toString()
                    << " | Area = " << arr[i].Area() << endl;
            }
            break;
        }
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}