INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_ASPIN ASPIN)

FIND_PATH(
    ASPIN_INCLUDE_DIRS
    NAMES ASPIN/api.h
    HINTS $ENV{ASPIN_DIR}/include
        ${PC_ASPIN_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    ASPIN_LIBRARIES
    NAMES gnuradio-ASPIN
    HINTS $ENV{ASPIN_DIR}/lib
        ${PC_ASPIN_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ASPIN DEFAULT_MSG ASPIN_LIBRARIES ASPIN_INCLUDE_DIRS)
MARK_AS_ADVANCED(ASPIN_LIBRARIES ASPIN_INCLUDE_DIRS)

