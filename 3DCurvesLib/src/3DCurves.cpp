#include "pch.h" 
#include "3DCurves.h"

double Circle::GetX(double t) const
{
	return radius * cos(t);
}

double Circle::GetY(double t) const
{
	return radius * sin(t);
}

double Circle::GetDerivativeX(double t) const
{
	return -radius * sin(t);
}

double Circle::GetDerivativeY(double t) const
{
	return radius * cos(t);
}

double Circle::GetRadius() const
{
	return radius;
}


double Ellipse::GetX(double t) const
{
	return radiusX * cos(t);
}

double Ellipse::GetY(double t) const
{
	return radiusY * sin(t);
}

double Ellipse::GetDerivativeX(double t) const
{
	return -radiusX * sin(t);
}

double Ellipse::GetDerivativeY(double t) const
{
	return radiusY * cos(t);
}

double Ellipse::GetRadius() const
{
	return std::max<double>({ radiusX, radiusY });
}

double Helix::GetX(double t) const
{
	return radius * cos(t);
}

double Helix::GetY(double t) const
{
	return radius * sin(t);
}

double Helix::GetDerivativeX(double t) const
{
	return -radius * sin(t);
}

double Helix::GetDerivativeY(double t) const
{
	return radius * cos(t);
}

double Helix::GetDerivativeZ(double t) const
{
	return step / (2 * M_PI);
}

double Helix::GetRadius() const
{
	return radius;
}

double Helix::GetStep() const
{
	return step;
}

Circle* CircleCreator(double radius)
{
	return new Circle(radius);
}

class Ellipse* EllipseCreator(double radiusX, double radiusY)
{
	return new class Ellipse(radiusX, radiusY);
}

Helix* HelixCreator(double radius, double step) 
{
	return new Helix(radius, step);
}