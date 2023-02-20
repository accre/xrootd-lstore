# - Find lstore
#
# LSTORE_INCLUDE_DIR       - location of the lstore-devel header files
# LSTORE_LIBS              - list of lstore libraries, with full path
# LSTORE_FOUND

find_path(
  LSTORE_INCLUDE_DIR
  lio/lio.h
  HINTS
  ${LSTORE_DIR}
  $ENV{LSTORE_DIR}
  /usr
  /opt
  PATH_SUFFIXES include
)

find_library(
  LSTORE_LIB
  NAMES liblio.so
  HINTS
  ${LSTORE_DIR}
  $ENV{LSTORE_DIR}
  /usr
  /opt
  PATH_SUFFIXES lib
)

set(LSTORE_LIBS ${LSTORE_LIB})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(lstore DEFAULT_MSG LSTORE_INCLUDE_DIR LSTORE_LIBS)
