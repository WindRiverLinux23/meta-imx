FILESEXTRAPATHS:prepend:mx8-nxp-bsp := "${THISDIR}/${PN}:"

DEPENDS += "readline"

# Add defconfig for NXP Wi-Fi version
SRC_URI += "file://defconfig"

PACKAGECONFIG:append:mx8-nxp-bsp := " openssl"

do_configure:prepend () {
        # Overwrite defconfig with NXP Wi-Fi version
        install -m 0755 ${WORKDIR}/defconfig wpa_supplicant/defconfig

}
