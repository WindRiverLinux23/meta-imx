require optee-os-common-imx.inc

SUMMARY = "OP-TEE Trusted OS TA devkit"
DESCRIPTION = "OP-TEE TA devkit for build TAs"
HOMEPAGE = "https://www.op-tee.org/"

DEPENDS += "python3-pycryptodome-native"

do_compile:aarch64() {
    for plat in ${OPTEEOS_CONFIG}; do
        oe_runmake -C ${S} PLATFORM=$plat O=${B}/$plat all
    done
}

do_install() {
    #install TA devkit
    install -d ${D}${includedir}/optee/export-user_ta/
    for plat in ${OPTEEOS_CONFIG}; do
        for f in ${B}/$plat/export-ta_${OPTEE_ARCH}/* ; do
            cp -aR $f ${D}${includedir}/optee/export-user_ta/
        done
    done
}

do_deploy() {
	echo "Do not inherit do_deploy from optee-os."
}

FILES:${PN} = "${includedir}/optee/"

# Build paths are currently embedded
INSANE_SKIP:${PN}-dev += "buildpaths"
