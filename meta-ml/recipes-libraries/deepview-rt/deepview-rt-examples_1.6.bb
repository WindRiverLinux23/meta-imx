DESCRIPTION = "DeepViewRT examples"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://COPYING;md5=65c483bb431ccd9a1820e6872c604771"

DEPENDS = "deepview-rt" 

SRC_URI = "${FSL_MIRROR}/${BPN}-${PV}.bin;fsl-eula=true"
SRC_URI[md5sum] = "3eee283c8492b7f904cbc04619bff48b"
SRC_URI[sha256sum] = "a8421f017f83ed1f454fa665cf40127493251ca77748a526b5b828862239c86b"
S = "${WORKDIR}/${BPN}-${PV}"

inherit fsl-eula-unpack pkgconfig

EXTRA_OEMAKE += "SDK_SYSROOT=${RECIPE_SYSROOT}"

do_install () {
    install -d ${D}${bindir}/${BPN}

    cp -fr ${S}/labelimg/labelimg  ${D}${bindir}/${BPN}
    cp -fr ${S}/detect_ssd/detect_ssd ${D}${bindir}/${BPN}
    cp -fr ${S}/python-examples ${D}${bindir}/${BPN}
 
    chown -R root:root "${D}"
}

INSANE_SKIP:${PN} += "rpaths dev-deps ldflags"
CLEANBROKEN = "1"

RDEPENDS:${PN} = "deepview-rt python3-core"

BBCLASSEXTEND = "nativesdk"

COMPATIBLE_MACHINE = "(mx8-nxp-bsp|mx9-nxp-bsp)"