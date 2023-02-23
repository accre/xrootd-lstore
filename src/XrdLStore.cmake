include_directories( ${XROOTD_INCLUDE_DIR} )
include_directories( ${LSTORE_INCLUDE_DIR} )
include_directories( ${APR_INCLUDE_DIR} )
include_directories( ${ZMQ_INCLUDE_DIR} )
include_directories( ${CMAKE_SOURCE_DIR}/src )

#-------------------------------------------------------------------------------
# The XrdLStore module
#-------------------------------------------------------------------------------
set( LIB_XRD_LSTORE XrdLStore-${PLUGIN_VERSION} )

add_library(
  ${LIB_XRD_LSTORE}
  MODULE
  XrdLStore/XrdLStoreOss.cc       XrdLStore/XrdLStoreOss.hh 
  XrdLStore/XrdLStoreOssDF.cc       XrdLStore/XrdLStoreOssDF.hh )

target_link_libraries(
  ${LIB_XRD_LSTORE}
  ${XROOTD_LIBRARIES}
  ${APR_LIBS}
  ${ZMQ_LIBS}
  ${LSTORE_LIBS} )

set_target_properties(
  ${LIB_XRD_LSTORE}
  PROPERTIES
  INTERFACE_LINK_LIBRARIES ""
  LINK_INTERFACE_LIBRARIES "" )

#-------------------------------------------------------------------------------
# The XrdLStoreXattr module
#-------------------------------------------------------------------------------
set( LIB_XRD_LSTORE_XATTR XrdLStoreXattr-${PLUGIN_VERSION} )

add_library(
  ${LIB_XRD_LSTORE_XATTR}
  MODULE
  XrdLStore/XrdLStoreXAttr.cc   XrdLStore/XrdLStoreXAttr.hh )

target_link_libraries(
  ${LIB_XRD_LSTORE_XATTR}
  ${XROOTD_LIBRARIES}  )

set_target_properties(
  ${LIB_XRD_LSTORE_XATTR}
  PROPERTIES
  INTERFACE_LINK_LIBRARIES ""
  LINK_INTERFACE_LIBRARIES "" )

#-------------------------------------------------------------------------------
# Install
#-------------------------------------------------------------------------------
install(
  TARGETS ${LIB_XRD_LSTORE} ${LIB_XRD_LSTORE_XATTR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} )

