
#include <iostream>
#include <memory>
#include <sdbusplus/sdbus.hpp>
#include <sdeventplus/event.hpp>
#include <vector>
#include <xyz/openbmc_project/Assets/RAM/server.hpp>

namespace phosphor
{
namespace assets
{

using RAMObject = sdbusplus::server::object_t<
    sdbusplus::xyz::openbmc_project::Assets::server::RAM>;

class RAM : public RAMObject
{
  public:
    RAM(sdbusplus::bus::bus& bus, const std::string& path,sdeventplus::Event &event) :
        RAMObject(bus, path.c_str()),event(event)
    {

    }

  private:
    sdeventplus::Event &event;
};
} // namespace assets
} // namespace phosphor
