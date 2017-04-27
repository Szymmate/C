//
// Created by kerni on 14/04/2017.
//

#include "Point3d.h"
#include <iostream>
#include <cmath>

using ::std::pow;
using ::std::sqrt;
using ::std::cout;
using ::std::endl;

Point3d::Point3d():z_(0) {
    cout << "Konstruktor bezparametrowy point3d" << endl;
}

Point3d::Point3d(double x, double y, double z) : Point(x, y) {
    cout << "Konstruktor parametrowy point3d" << endl;
    z_ = z;
}

Point3d::~Point3d() {
    cout << "Destruktor point3d";
    cout << endl;
}

double Point3d::Distance(const Point3d &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2) + pow(GetZ() - other.GetZ(), 2));
}

double Point3d::GetZ() const {
    return z_;
}

void Point3d::SetZ(double z) {
    z_ = z;
}


