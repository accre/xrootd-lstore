# - Find zeromq
#
# ZMQ_INCLUDE_DIR          - location of the zeromq-devel header files
# ZMQ_LIBS                 - list of zeromq libraries, with full path
# ZMQ_FOUND

find_path(
  ZMQ_INCLUDE_DIR
  HINTS
  ${ZMQ_DIR}
  $ENV{ZMQ_DIR}
  /usr
  /opt
  PATH_SUFFIXES include
)

find_library(
  ZMQ_LIB
  NAMES libzmq.so.5
  HINTS
  ${ZMQ_DIR}
  $ENV{ZMQ_DIR}
  /usr
  /opt
  PATH_SUFFIXES lib
)

set(ZMQ_LIBS ${ZMQ_LIB})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(zmq DEFAULT_MSG ZMQ_INCLUDE_DIR ZMQ_LIBS)
