DESCRIPTION = "i.MX U-Boot suppporting i.MX reference boards."

LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://Licenses/gpl-2.0.txt;md5=b234ee4d69f5fce4486a80fdaf4a4263"

UBOOT_SRC ?= "git://github.com/nxp-imx/uboot-imx.git;protocol=https"
SRC_URI = "${UBOOT_SRC};branch=${SRCBRANCH} \
           file://0001-LFU-573-1-imx8m-hab-Verify-hash-of-FIT-FDT-strucure.patch \
           file://0002-LFU-573-2-imx8m-hab-Verify-optional-FIT-FDT-signatur.patch \
           file://0003-MA-21597-check-spl-fit-pointer-before-parsing-it.patch \
           file://0004-LFU-573-3-doc-imx8m-Update-iMX8M-secure-boot-and-enc.patch \
           file://efi.cfg \
"
SRCBRANCH = "lf_v2023.04"
LOCALVERSION ?= "-${SRCBRANCH}"
SRCREV = "af7d004eaf18437c7db76f7962652b924099405b"

DEPENDS += " \
    bc-native \
    bison-native \
    dtc-native \
    flex-native \
    gnutls-native \
    xxd-native \
"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

inherit fsl-u-boot-localversion

BOOT_TOOLS = "imx-boot-tools"
