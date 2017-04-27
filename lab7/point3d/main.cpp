//
// Created by kerni on 14/04/2017.
//

#include "Point3d.h"
#include <iostream>

using ::std::cout;
using ::std::endl;

int main() {

    Point3d point3d(1, 1, 2);
    Point point2d(2, 2);
    /**
     Kolejność wywoływania:
     1. Konstruktor parametrowy klasy Point dla obiektu Point3d
     2. Konstruktor parametrowy klasy Point3D dla obiektu Point3d
     3. Konstruktor parametrowy klasy Point dla obiektu Point2d
     4. Destruktor klasy Point dla obiektu Point3d
     5. Destruktor klasy Point3d dla obiektu Point3d
     6. Destruktor klasy Point dla obiektu Point2d
     **/

    cout << point2d.Distance(point3d) << endl;

    /**
      Dystans obliczony został jakby nie istniał trzeci parametr
     **/



    Point3d p3d(1, 2, 3);
     //cout << p3d << endl;

    /**
     Nie zadziała, gdyż operator<< nie został zdefiniowany
    **/

    return 0;
}