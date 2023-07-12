FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append:imxgpu = " \
    file://0002-glamor-Fix-fbo-pixmap-format-with-GL_BGRA_EXT.patch \
"

LIBEGL ?= "libegl"
LIBEGL:imxgpu = "libegl-imx"

PACKAGECONFIG[glamor] = "-Dglamor=true,-Dglamor=false,libepoxy virtual/libgbm,${LIBEGL}"
