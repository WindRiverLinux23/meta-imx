require recipes-connectivity/nxp-wlan-sdk/nxp-wlan-sdk_git.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append:mx8-nxp-bsp = " file://0001-mxm_wifiex-Dlete-REGULATORY_IGNORE_STALE_KICKOFF.patch;striplevel=3"

SUMMARY = "Kernel loadable module for NXP Wi-Fi module 88w8801/8987/8997/9098 IW416/612"

inherit module

EXTRA_OEMAKE += "-C ${STAGING_KERNEL_BUILDDIR} M=${S}"
