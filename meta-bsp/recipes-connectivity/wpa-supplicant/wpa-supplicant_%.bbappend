FILESEXTRAPATHS:prepend:mx8-nxp-bsp := "${THISDIR}/${PN}:"

DEPENDS:append:mx8-nxp-bsp = " readline"

# Add defconfig for NXP Wi-Fi version
SRC_URI:append:mx8-nxp-bsp = " file://defconfig"

PACKAGECONFIG:append:mx8-nxp-bsp := " openssl"

do_configure:prepend:mx8-nxp-bsp () {
        # Overwrite defconfig with NXP Wi-Fi version
        install -m 0755 ${WORKDIR}/defconfig wpa_supplicant/defconfig

}
