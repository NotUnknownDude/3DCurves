#include <iostream>
#include <vector>
#include <algorithm>

#define _USE_MATH_DEFINES

#include <math.h>

#include <3DCurves.h>

int main() {
    std::vector<Curve3D*> curves;

    // Populate container with random curves
    for (int i = 1; i < 10; i++)
    {
        curves.push_back(CircleCreator(i));
    }

    curves.push_back(EllipseCreator(3.0, 2.0));
    curves.push_back(HelixCreator(1.0, 0.5));

    // Print coordinates and derivatives at t = PI/4
    double t = M_PI / 4;
    for (const auto& curve : curves) {
        std::cout << "\nCurve type: ";
        if (dynamic_cast<Circle*>(curve)) {
            std::cout << "Circle";
        } else if (dynamic_cast<Ellipse*>(curve)) {
            std::cout << "Ellipse";
        } else if (dynamic_cast<Helix*>(curve)) {
            std::cout << "Helix";
        }

        std::cout << "\nPoint: (" << curve->GetX(t) << ", " << curve->GetY(t) << ", " << curve->GetZ(t) << ")";
        std::cout << "\nDerivative: (" << curve->GetDerivativeX(t) << ", " << curve->GetDerivativeY(t) << ", " << curve->GetDerivativeZ(t) << ")\n";
    }

    // Populate second container with circles from the first container
    std::vector<const Circle*> circles;
    for (const auto& curve : curves) {
        if (const Circle* circle = dynamic_cast<const Circle*>(curve)) {
            circles.push_back(circle);
        }
    }

    // Sort the second container by ascending order of radii
    std::sort(circles.begin(), circles.end(), [](const Circle* a, const Circle* b) {
        return a->GetRadius() < b->GetRadius();
    });

    // Compute the total sum of radii of all circles
    double totalRadiusSum = 0.0;
    for (const auto& circle : circles) {
        totalRadiusSum += circle->GetRadius();
    }

    std::cout << "\nTotal sum of radii: " << totalRadiusSum << std::endl; // Flush

    // Clean up
    for (const auto& curve : curves) {
        delete curve;
    }

    return 0;
}