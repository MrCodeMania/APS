#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

using namespace std;

class Circle
{
private:
	double radius;
public:
	Circle(double r);
	double GetEuclid();
	double GetTaxi();
};

Circle::Circle(double r)
{
	this->radius = r;
}

double Circle::GetEuclid()
{
	return PI * this->radius * this->radius;
}

double Circle::GetTaxi()
{
	return 2 * this->radius * this->radius;
}

int main()
{
	double radius;
	cin >> radius;

	Circle C(radius);

	cout << fixed;
	cout.precision(6);
	cout << C.GetEuclid() << endl;
	cout << C.GetTaxi() << endl;

	return 0;
}