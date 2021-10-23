#include "SimpleClassWithVeryLongName.h"

int main() {
    Logger::NFO() << "Let's try something simple";
    Logger::DBG() << "I am debug " << 1 << " " << 1.1 << std::endl;
    Logger::NFO() << "I am info " << 2 << " " << 2.2 << std::endl;
    Logger::ERR() << "I am error " << 3 << " " << 3.3 << std::endl;
    Logger::NFO() << std::format("I am c98 {} {}", 4, 4.4) << std::endl;
    Logger::NFO() << std::format("I am sneaky {1} {0}", 5, 5.5) << std::endl;
    Logger::NFO() << "I have no endl " << 6 << " " << 6.6;

    Logger::NFO() << "Let's try dynamic debug";
    Logger::DBG() << "Now you can't see me";
    Logger::SetDynamicDebug(true);
    Logger::DBG() << "Now you can see debug messages";

    Logger::NFO() << "Let's try something different";
    SimpleClassWithVeryLongName::complicatedDivisionOperation(5, 5);
    SimpleClassWithVeryLongName::complicatedDivisionOperation(5, 0);

    Logger::NFO() << "Let's try formatted array";
    std::string fmt = "{:3d} | {:5.2f} | 0x{:x}";
    for (auto i = 0; i < 5; i++) {
        Logger::NFO() << std::format(fmt, i, i * 4.3, i);
    }

    return 0;
}
