# Copyright 2021-2023 NXP

DESCRIPTION = "NXP RetuneDSP Voice Seeker Libraries"
SECTION = "multimedia"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=ea25d099982d035af85d193c88a1b479"

inherit autotools pkgconfig

DEPENDS += "alsa-lib nxp-afe"

SRCBRANCH = "MM_04.07.03_2301_L6.1.y"
PV = "2.0+${SRCPV}"

NXPAFE_VOICESEEKER_SRC ?= "git://github.com/nxp-imx/imx-voiceui.git;protocol=https"
SRC_URI = "${NXPAFE_VOICESEEKER_SRC};branch=${SRCBRANCH}"

SRCREV = "d682a2e1330873faf5deb4d99ff541b18eedbe51"
S = "${WORKDIR}/git"

EXTRA_CONF = "--enable-armv8 --bindir=/unit_tests/ --libdir=/usr/lib/"

EXTRA_OEMAKE:mx8-nxp-bsp = "BUILD_ARCH=CortexA53"
EXTRA_OEMAKE:mx93-nxp-bsp = "BUILD_ARCH=CortexA55"

do_compile () {
    echo "====Enter into ${WORKDIR}/git===="
    cd ${WORKDIR}/git
    echo "====make all==="
    oe_runmake all
}

do_install() {
    install -d ${D}${libdir}/nxp-afe
    install -d ${D}/unit_tests/nxp-afe
    install -m 0644 ${WORKDIR}/git/release/*.so.2.0    ${D}${libdir}/nxp-afe/
    ln -sf -r ${D}${libdir}/nxp-afe/libvoiceseekerlight.so.2.0 ${D}${libdir}/nxp-afe/libvoiceseekerlight.so
    install -m 0755 ${WORKDIR}/git/release/voice_ui_app    ${D}/unit_tests/nxp-afe
    install -m 0644 ${WORKDIR}/git/release/*.bin    ${D}/unit_tests/nxp-afe
    install -m 0644 ${WORKDIR}/git/release/Config.ini    ${D}/unit_tests/nxp-afe
}

PACKAGE_ARCH = "${MACHINE_ARCH}"

FILES:${PN} += "${libdir}/nxp-afe/* \
                /unit_tests/* \
"
INSANE_SKIP:${PN} += "dev-so"

COMPATIBLE_MACHINE = "(mx8-nxp-bsp|mx9-nxp-bsp)"
