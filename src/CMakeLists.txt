#-------------------------------------------------------------------------------
# Include the subcomponents
#-------------------------------------------------------------------------------
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
if( XRDLSTORE_SUBMODULE )
  add_compile_definitions( XRDLSTORE_SUBMODULE )
endif()
include( XrdLStore )
