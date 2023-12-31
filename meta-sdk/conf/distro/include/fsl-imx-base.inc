require conf/distro/poky.conf

DISTRO = "imx-nxp"
DISTRO_NAME = "NXP i.MX Release Distro"
DISTRO_VERSION = "6.1-langdale"
DISTROOVERRIDES = "fsl"

MAINTAINER = "NXP <lauren.post@nxp.com>"

REMOVE_VULKAN_FEATURE = "vulkan"
REMOVE_VULKAN_FEATURE:mx8-nxp-bsp = ""
POKY_DEFAULT_DISTRO_FEATURES:remove      = "wayland ${REMOVE_VULKAN_FEATURE}"
POKY_DEFAULT_DISTRO_FEATURES:append:mx8-nxp-bsp  = " jailhouse"
POKY_DEFAULT_DISTRO_FEATURES:append:mx9-nxp-bsp  = " jailhouse"

DISTRO_FEATURES:append:mx8-nxp-bsp = " virtualization"
SKIP_META_VIRT_SANITY_CHECK = "1"

SKIP_META_SECURITY_SANITY_CHECK = "1"
SKIP_META_TPM_SANITY_CHECK = "1"

# Set a more generic tuning for code reuse across parts
DEFAULTTUNE:mx8-nxp-bsp    ?= "armv8a-crc-crypto"
DEFAULTTUNE:mx8m-nxp-bsp   ?= "armv8a-crc-crypto"
DEFAULTTUNE:mx8qm-nxp-bsp  ?= "armv8a-crc-crypto"
DEFAULTTUNE:mx8x-nxp-bsp   ?= "armv8a-crc-crypto"
DEFAULTTUNE:mx8ulp-nxp-bsp ?= "armv8a-crc-crypto"
DEFAULTTUNE:mx9-nxp-bsp    ?= "armv8a-crc-crypto"

PACKAGECONFIG:append:pn-gstreamer1.0-plugins-ugly = " x264"

PACKAGECONFIG:append:pn-pulseaudio = " autospawn-for-root"

PACKAGECONFIG:append:class-target:pn-qtquick3d     = " examples"
PACKAGECONFIG:append:class-target:pn-qtwebengine   = " examples"

PACKAGECONFIG:append:pn-systemd = " unmanaged-network"
