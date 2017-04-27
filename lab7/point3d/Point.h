//
// Created by kerni on 14/04/2017.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include "Point.h"
#include <ostream>

using ::std::ostream;

class Point {


public:
    Point();
    Point(double x, double y);
    virtual ~Point();

    void ToString(ostream *out) const;
    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);

protected:
    double x_, y_;
};

#endif //JIMP_EXERCISES_POINT_H
