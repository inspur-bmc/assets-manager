# assets module

just a build framework


# How To

```
1. devtool add asseets-manager https://github.com/inspur-bmc/assets-manager.git
2. modify assets-manager_git.bb ,add 
	DEPENDS += "autoconf-archive-native"
        DEPENDS += "sdbus++-native"
	DEPENDS += "sdbusplus"
	DEPENDS += "sdeventplus"
	DEPENDS += "systemd"
	
	SYSTEMD_SERVICE_${PN} += "assets-manager.service"

	inherit pkgconfig autotools
	inherit pythonnative
	inherit systemd


3. bitbake assets-manager
```
