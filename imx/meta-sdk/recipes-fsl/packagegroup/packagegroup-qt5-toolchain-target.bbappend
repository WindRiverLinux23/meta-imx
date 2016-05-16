
RDEPENDS_${PN}_remove_mx6 = "qtquick1-dev \
    qtquick1-mkspecs \
    qtquick1-plugins \
    qtquick1-qmlplugins \
    qttranslations-qtquick1 \
    qtwebkit-dev \
    qtwebkit-mkspecs \
    qtwebkit-qmlplugins \
"
# Remove qtimageformats to get pass build error for 64 bit
RDEPENDS_${PN}_remove_mx8 = "qtimageformats-dev \
    qtimageformats-plugins \
"
RDEPENDS_${PN}_append = " \
    qtdeclarative-tools \
"
