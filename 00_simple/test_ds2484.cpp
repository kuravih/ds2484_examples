#include "kato/log.hpp"
#include "ds2484/ds2484.hpp"

int main()
{
    DS2484 bus((DS2484_I2C_BUS_PREFIX + std::to_string(26)).c_str());
    kato::log::cout << KATO_RED << "tester.cpp::main() : scanning " << KATO_RESET << std::endl;
    bus.scan_for_sensors();
    kato::log::cout << KATO_RED << "tester.cpp::main() : found " << std::setfill('0') << std::setw(2) << bus.samples.size() << " sensors " << KATO_RESET << std::endl;
    std::cout << '\r'; // or similar logic depending on how kato::log::cout works
    for (size_t i = 0; i < bus.samples.size(); i++)
    {
        bus.led(bus.samples[i].rom, true);
        bus.led(bus.samples[i].rom, false);
        kato::log::cout << KATO_RED << "tester.cpp::main() " << std::setfill('0') << std::setw(2) << i + 1 << "/" << std::setfill('0') << std::setw(2) << bus.samples.size() << " : sample " << bus.samples[i] << KATO_RESET << std::endl;
    }
}
