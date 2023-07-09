#pragma once

#ifdef CURVES3D_EXPORTS
#define CURVES3D_API __declspec(dllexport)
#else
#define CURVES3D_API __declspec(dllimport)
#endif

class Curve3D
{
public:
	virtual double GetX(double t) const { return 0.0; };
	virtual double GetY(double t) const { return 0.0; };
	virtual double GetZ(double t) const { return 0.0; };
	virtual double GetDerivativeX(double t) const { return 0.0; };
	virtual double GetDerivativeY(double t) const { return 0.0; };
	virtual double GetDerivativeZ(double t) const { return 0.0; };
	virtual double GetStep() const { return 0.0; };
	virtual double GetRadius() const { return 0.0; };
	virtual ~Curve3D() { };
};

class Circle : public Curve3D
{
	double radius;

public:
	Circle(double radius) : radius(radius) { };

	double GetX(double t) const override;
	double GetY(double t) const override;
	double GetDerivativeX(double t) const override;
	double GetDerivativeY(double t) const override;
	double GetRadius() const override;
};

class Ellipse : public Curve3D
{
	double radiusX, radiusY;

public:
	Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) { };

	double GetX(double t) const override;
	double GetY(double t) const override;
	double GetDerivativeX(double t) const override;
	double GetDerivativeY(double t) const override;
	double GetRadius() const override;
};

class Helix : public Curve3D
{
	double radius;
	double step;

public:
	Helix(double radius, double step) : radius(radius), step(step) { };

	double GetX(double t) const override;
	double GetY(double t) const override;
	double GetDerivativeX(double t) const override;
	double GetDerivativeY(double t) const override;
	double GetDerivativeZ(double t) const override;
	double GetRadius() const override;
	double GetStep() const override;
};

CURVES3D_API Circle* CircleCreator(double radius);
CURVES3D_API class Ellipse* EllipseCreator(double radiusX, double radiusY);
CURVES3D_API Helix* HelixCreator(double radius, double step);
