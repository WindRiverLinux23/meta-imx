require optee-os-common-imx.inc

EXTRA_OEMAKE:remove = " \
    PLATFORM=${OPTEEMACHINE} \
"

do_compile:aarch64() {
    for plat in ${OPTEEOS_CONFIG}; do
        oe_runmake -C ${S} PLATFORM=$plat O=${B}/$plat all
    done
}

do_install:aarch64 () {
    install -d ${D}${nonarch_base_libdir}/firmware/
    for plat in ${OPTEEOS_CONFIG}; do
        #install core in firmware
        install -m 644 ${B}/$plat/core/*.bin ${B}/$plat/core/tee.elf ${D}${nonarch_base_libdir}/firmware/
    done
}

do_install:append () {
    # Install embedded TAs
    install -d ${D}${nonarch_base_libdir}/optee_armtz/
    for plat in ${OPTEEOS_CONFIG}; do
        install -m 444 ${B}/$plat/ta/*/*.ta ${D}${nonarch_base_libdir}/optee_armtz/
    done
}

do_deploy:append() {
    install -d ${DEPLOYDIR}/${MLPREFIX}optee
    for plat in ${OPTEEOS_CONFIG}; do
        install -m 644 ${D}${nonarch_base_libdir}/firmware/* ${DEPLOYDIR}/${MLPREFIX}optee
        cp ${B}/$plat/core/tee-raw.bin ${DEPLOYDIR}/${MLPREFIX}optee/tee.${plat}.bin
        ln -sf ${MLPREFIX}optee/tee.${plat}.bin ${DEPLOYDIR}/tee${plat}.bin
    done
}

do_deploy:append:arm() {
    cp ${B}/core/uTee ${DEPLOYDIR}/${MLPREFIX}optee/uTee-${OPTEE_BIN_EXT}
    ln -sf ${MLPREFIX}optee/uTee-${OPTEE_BIN_EXT} ${DEPLOYDIR}/uTee-${OPTEE_BIN_EXT}
}

FILES:${PN} += "${nonarch_base_libdir}/optee_armtz"
