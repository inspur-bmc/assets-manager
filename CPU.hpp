
#include <iostream>
#include <memory>
#include <sdbusplus/sdbus.hpp>
#include <sdeventplus/event.hpp>
#include <vector>
#include <xyz/openbmc_project/Assets/CPU/server.hpp>

namespace phosphor
{
namespace assets
{

using CPUObject = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Assets::server::CPU>;

class CPU : public CPUObject
{
  public:
    CPU(sdbusplus::bus::bus& bus, const std::string& path,sdeventplus::Event &event) :
        CPUObject(bus, path.c_str()),event(event)
    {

    }

  private:
    sdeventplus::Event &event;
};
} // namespace assets
} // namespace phosphor
