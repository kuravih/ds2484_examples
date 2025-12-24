#include "kato/log.hpp"
#include "ds2484/ds2484.hpp"
#include <fstream>
#include <csignal>

#include <atomic>

volatile std::atomic<bool> busy{true};

void sigint_handler(int signal)
{
    if (signal == SIGINT)
    {
        busy.store(false);
        kato::log::cout << KATO_RED << "ds2484_reader.cpp::sigint_handler() Terminating stream ..." << KATO_RESET << std::endl;
    }
}

int main()
{

    std::signal(SIGINT, sigint_handler);

    std::string filename = std::string("sensors_") + kato::function::TimeStampString(0, "%d%H%M%S") + ".log";

    std::ofstream output(filename);
    kato::log::cout << KATO_GREEN << "tester.cpp::main() : file " << filename << " opened" << KATO_RESET << std::endl;

    DS2484 bus((DS2484_I2C_BUS_PREFIX + std::to_string(26)).c_str());
    kato::log::cout << KATO_GREEN << "tester.cpp::main() : scanning " << KATO_RESET << std::endl;
    bus.scan_for_sensors();
    kato::log::cout << KATO_GREEN << "tester.cpp::main() : found " << std::setfill('0') << std::setw(2) << bus.samples.size() << " sensors " << KATO_RESET << std::endl;
    std::cout << '\r';
    
    while (busy.load() && (bus.samples.size() > 0) && output.is_open())
    {
        for (size_t i = 0; i < bus.samples.size(); i++)
        {
            bus.led(bus.samples[i].rom, true);
            bus.read_temperature(bus.samples[i].rom, bus.samples[i].temperature);
            bus.samples[i].set_timestamp();
            bus.led(bus.samples[i].rom, false);
            kato::log::cout << KATO_GREEN << "tester.cpp::main() " << std::setfill('0') << std::setw(2) << i + 1 << "/" << std::setfill('0') << std::setw(2) << bus.samples.size() << " : sample " << bus.samples[i] << KATO_RESET << std::endl;
            output << bus.samples[i] << KATO_RESET << std::endl;
        }
    }

    output.close();

    kato::log::cout << KATO_GREEN << "tester.cpp::main() : file " << filename << " created" << KATO_RESET << std::endl;
}
