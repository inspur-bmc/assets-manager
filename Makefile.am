AM_DEFAULT_SOURCE_EXT = .cpp

sbin_PROGRAMS = assets-manager

if HAVE_SYSTEMD
systemdsystemunit_DATA = assets-manager.service
endif

assets_manager_SOURCES = \
	main.cpp  \
	xyz/openbmc_project/Assets/RAM/server.cpp \
	xyz/openbmc_project/Assets/CPU/server.cpp

BUILT_SOURCES = \
		xyz/openbmc_project/Assets/RAM/server.hpp \
		xyz/openbmc_project/Assets/RAM/server.cpp \
		xyz/openbmc_project/Assets/CPU/server.hpp \
		xyz/openbmc_project/Assets/CPU/server.cpp

assets_manager_LDADD = \
		      $(SDBUSPLUS_LIBS) \
		      $(SDEVENTPLUS_LIBS)

assets_manager_CXXFLAGS =  \
		      $(SDBUSPLUS_CFLAGS) \
		      $(SDEVENTPLUS_CFLAGS)

xyz/openbmc_project/Assets/RAM/server.hpp: ${top_srcdir}/xyz/openbmc_project/Assets/RAM.interface.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS)  -r ${top_srcdir} interface server-header xyz.openbmc_project.Assets.RAM > $@
xyz/openbmc_project/Assets/RAM/server.cpp: ${top_srcdir}/xyz/openbmc_project/Assets/RAM.interface.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS)  -r ${top_srcdir} interface server-cpp xyz.openbmc_project.Assets.RAM > $@
xyz/openbmc_project/Assets/CPU/server.hpp: ${top_srcdir}/xyz/openbmc_project/Assets/CPU.interface.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS)  -r ${top_srcdir} interface server-header xyz.openbmc_project.Assets.CPU > $@
xyz/openbmc_project/Assets/CPU/server.cpp: ${top_srcdir}/xyz/openbmc_project/Assets/CPU.interface.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS)  -r ${top_srcdir} interface server-cpp xyz.openbmc_project.Assets.CPU > $@

