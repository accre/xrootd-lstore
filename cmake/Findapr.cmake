# - Find apr
#
# APR_INCLUDE_DIR          - location of the apr-devel header files
# APR_LIBS                 - list of apr libraries, with full path
# APR_FOUND

find_path(
  APR_INCLUDE_DIR
  HINTS
  ${APR_DIR}
  $ENV{APR_DIR}
  /usr
  /opt
  PATH_SUFFIXES include
)

find_library(
  APR_LIB
  NAMES libapr-1.so
  HINTS
  ${APR_DIR}
  $ENV{APR_DIR}
  /usr
  /opt
  PATH_SUFFIXES lib
)

set(APR_LIBS ${APR_LIB})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(apr DEFAULT_MSG APR_INCLUDE_DIR APR_LIBS)
