#include <vector>
#include <iostream>

#include "Kolo.h"
#include "Kwadrat.h"
#include "Trojkat.h"

using ::std::cout;
using ::std::endl;

int main() {
    Kolo c1;
    Kolo c2;
    Kolo c3;
    Kolo c4;
    Kwadrat k1;
    Kwadrat k2;
    Kwadrat k3;
    Kwadrat k4;
    Trojkat t1;
    Trojkat t2;
    Trojkat t3;
    Trojkat t4;

    Ksztalt *figury[12];
    figury[0] = &k1;
    figury[1] = &c2;
    figury[2] = &t2;
    figury[3] = &k2;
    figury[4] = &t1;
    figury[5] = &c3;
    figury[6] = &c1;
    figury[7] = &t3;
    figury[8] = &k3;
    figury[9] = &k4;
    figury[10] = &t3;
    figury[11] = &c4;

    for (int i=0; i < 12; i++) {
        cout << figury[i]->rysuj() << endl;
    }
  /**
   Efektem wywołania metody rysuj na każdym z elementów listy jest wyświetlenie jej w trybie tekstowym.
   **/
    return 0;
}
