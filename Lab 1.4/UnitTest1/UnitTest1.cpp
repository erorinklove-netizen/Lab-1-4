#include "pch.h"
#include "CppUnitTest.h"
#include "Rectangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(RectangleTests)
    {
    public:

        TEST_METHOD(TestInitAndValidation)
        {
            Rectangle r;
            Assert::IsTrue(r.Init(0, 0, 4, 3));
            Assert::AreEqual(0.0, r.GetX1(), 0.0001);
            Assert::AreEqual(0.0, r.GetY1(), 0.0001);
            Assert::AreEqual(4.0, r.GetX2(), 0.0001);
            Assert::AreEqual(3.0, r.GetY2(), 0.0001);

            Assert::IsFalse(r.Init(5, 0, 2, 3));
        }

        TEST_METHOD(TestSettersValidation)
        {
            Rectangle r(1, 1, 5, 5);

            Assert::IsFalse(r.SetX2(0));
            Assert::AreEqual(5.0, r.GetX2(), 0.0001);

            Assert::IsTrue(r.SetX2(6));
            Assert::AreEqual(6.0, r.GetX2(), 0.0001);
        }

        TEST_METHOD(TestAreaAndPerimeter)
        {
            Rectangle r(0, 0, 4, 3);
            Assert::AreEqual(12.0, r.Area(), 0.0001);
            Assert::AreEqual(14.0, r.Perimeter(), 0.0001);
        }

        TEST_METHOD(TestMove)
        {
            Rectangle r(0, 0, 2, 2);
            r.Move(3, -1);

            Assert::AreEqual(3.0, r.GetX1(), 0.0001);
            Assert::AreEqual(-1.0, r.GetY1(), 0.0001);
            Assert::AreEqual(5.0, r.GetX2(), 0.0001);
            Assert::AreEqual(1.0, r.GetY2(), 0.0001);
        }

        TEST_METHOD(TestResize)
        {
            Rectangle r(1, 1, 3, 3);
            r.Resize(5, 4);

            Assert::AreEqual(1.0, r.GetX1(), 0.0001);
            Assert::AreEqual(1.0, r.GetY1(), 0.0001);
            Assert::AreEqual(6.0, r.GetX2(), 0.0001);
            Assert::AreEqual(5.0, r.GetY2(), 0.0001);
        }

        TEST_METHOD(TestBoundingBox)
        {
            Rectangle r1(0, 0, 2, 2);
            Rectangle r2(3, 1, 5, 4);

            Rectangle box = Rectangle::BoundingBox(r1, r2);

            Assert::AreEqual(0.0, box.GetX1(), 0.0001);
            Assert::AreEqual(0.0, box.GetY1(), 0.0001);
            Assert::AreEqual(5.0, box.GetX2(), 0.0001);
            Assert::AreEqual(4.0, box.GetY2(), 0.0001);
        }

        TEST_METHOD(TestIntersection)
        {
            Rectangle r1(0, 0, 4, 4);
            Rectangle r2(2, 2, 6, 6);
            bool hasIntersection = false;

            Rectangle inter = Rectangle::Intersection(r1, r2, hasIntersection);

            Assert::IsTrue(hasIntersection);
            Assert::AreEqual(2.0, inter.GetX1(), 0.0001);
            Assert::AreEqual(2.0, inter.GetY1(), 0.0001);
            Assert::AreEqual(4.0, inter.GetX2(), 0.0001);
            Assert::AreEqual(4.0, inter.GetY2(), 0.0001);
        }
    };
}