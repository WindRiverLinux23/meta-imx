require recipes-security/optee/optee-os.inc

DEPENDS:append:arm = "u-boot-mkimage-native"

FILESEXTRAPATHS:prepend := "${THISDIR}/optee-os:"

SRC_URI:remove = "git://github.com/OP-TEE/optee_os.git;branch=master;protocol=https"
SRC_URI:prepend = "${OPTEE_OS_SRC};branch=${SRCBRANCH} "
SRC_URI:append = " file://0001-core-Define-section-attributes-for-clang.patch"
SRC_URI:remove = "file://0008-no-warn-rwx-segments.patch"

OPTEE_OS_SRC ?= "git://github.com/nxp-imx/imx-optee-os.git;protocol=https"

inherit features_check

REQUIRED_MACHINE_FEATURES = "optee"

OPTEEMACHINE                   = "imx-${@d.getVar('MACHINE')[1:]}"
OPTEEMACHINE:imx6qpdlsolox     = "imx-mx6qsabresd"
OPTEEMACHINE:mx6ul-nxp-bsp     = "imx-mx6ulevk"
OPTEEMACHINE:mx6ull-nxp-bsp    = "imx-mx6ullevk"
OPTEEMACHINE:mx6ulz-nxp-bsp    = "imx-mx6ulzevk"
OPTEEMACHINE:mx8mq-nxp-bsp     = "imx-mx8mqevk"
OPTEEMACHINE:mx8mm-nxp-bsp     = "imx-mx8mmevk"
OPTEEMACHINE:mx8mn-nxp-bsp     = "imx-mx8mnevk"
OPTEEMACHINE:mx8mp-nxp-bsp     = "imx-mx8mpevk"
OPTEEMACHINE:mx8mpul-nxp-bsp   = "imx-mx8mpevk"
OPTEEMACHINE:mx8qm-nxp-bsp     = "imx-mx8qmmek"
OPTEEMACHINE:mx8qxp-nxp-bsp    = "imx-mx8qxpmek"
OPTEEMACHINE:mx8dx-nxp-bsp     = "imx-mx8dxmek"
OPTEEMACHINE:mx8dxl-nxp-bsp    = "imx-mx8dxlevk"
OPTEEMACHINE:mx8mnul-nxp-bsp   = "imx-mx8mnevk"
OPTEEMACHINE:mx8ulp-nxp-bsp    = "imx-mx8ulpevk"
OPTEEMACHINE:mx93-nxp-bsp      = "imx-mx93evk"

# Strip the leading imx-
PLATFORM_FLAVOR = "${@d.getVar('OPTEEMACHINE')[4:]}"

EXTRA_OEMAKE:append = " \
    CFG_TEE_TA_LOG_LEVEL=0 \
    CFG_TEE_CORE_LOG_LEVEL=0 \
"

COMPATIBLE_MACHINE = "(imx-nxp-bsp)"
