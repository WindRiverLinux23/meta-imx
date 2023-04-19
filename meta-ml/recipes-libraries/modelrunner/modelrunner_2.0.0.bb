DESCRIPTION = "This package includes the updated and experimental ModelRunner for TensorFlow Lite and ARM NN. Also in this repository is a pre-release of DeepViewRT with support for the OpenVX backend."
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7853b7bf2936b2c25c893eac7033374"

SRC_URI = "${FSL_MIRROR}/${BPN}-${PV}.bin;fsl-eula=true"
SRC_URI[md5sum] = "4c1e3da461c62eb845d50a1a4f57f775"
SRC_URI[sha256sum] = "2bff60aa3253b4a67aeed605533e38ac898d2dd73e8f6dc4a070c281a34acab1"
S = "${WORKDIR}/${BPN}-${PV}"

inherit fsl-eula-unpack python3native

PACKAGECONFIG ?= "${PACKAGECONFIG_OPENVX}"
PACKAGECONFIG_OPENVX                    = ""
PACKAGECONFIG_OPENVX:mx8-nxp-bsp:imxgpu = "openvx"
PACKAGECONFIG_OPENVX:mx8mm-nxp-bsp      = ""
# The tensorflow-lite implementation for 8ULP uses CPU, and so doesn't
# support OpenVX
PACKAGECONFIG_OPENVX:mx8ulp-nxp-bsp     = ""

PACKAGECONFIG[openvx] = ",,,libopenvx-imx"

do_install () {
    install -d ${D}${bindir}
    install -d ${D}${libdir}

    cp -r  ${S}/modelrunner/bin/* ${D}${bindir}
    cp -rP ${S}/modelrunner/lib/* ${D}${libdir}

    chown -R root:root "${D}"
}

INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_SYSROOT_STRIP = "1"

FILES_SOLIBSDEV = ""

FILES:${PN} += "${libdir}/*"
RDEPENDS:${PN} = "onnxruntime tensorflow-lite"
INSANE_SKIP:${PN} += "dev-so dev-deps ldflags"

BBCLASSEXTEND = "nativesdk"

COMPATIBLE_MACHINE = "(mx8-nxp-bsp|mx9-nxp-bsp)"