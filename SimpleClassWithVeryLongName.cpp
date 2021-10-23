#include "SimpleClassWithVeryLongName.h"

double SimpleClassWithVeryLongName::complicatedDivisionOperation(double x, double y) {
    Logger::DBG() << "Try to calculate " << x << "/" << y;
    if (y == 0) {
        Logger::ERR() << "Logic error, can't divide by 0" << std::endl;
        return 0;
    }
    Logger::DBG() << "Return " << x / y;
    return x / y;
}
