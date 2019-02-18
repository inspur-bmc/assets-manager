#include <iostream>
#include <sdbusplus/bus.hpp>
#include <sdeventplus/event.hpp>
#include "RAM.hpp"
#include "CPU.hpp"

int main()
{
    auto event = sdeventplus::Event::get_default();
    auto bus = sdbusplus::bus::new_default();

    bus.attach_event(event.get(), SD_EVENT_PRIORITY_NORMAL);

    phosphor::assets::RAM ram{bus,"/xyz/openbmc_project/inspur/assets",event};
    phosphor::assets::CPU cpu{bus,"/xyz/openbmc_project/inspur/assets",event};
    bus.request_name("xyz.openbmc_project.Inspur.Assets");

    return event.loop();
}
