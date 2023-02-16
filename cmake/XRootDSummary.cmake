#-------------------------------------------------------------------------------
# Print the configuration summary
#-------------------------------------------------------------------------------
set( TRUE_VAR TRUE )
component_status( LSTORE   TRUE_VAR        LSTORE_FOUND )
component_status( XROOTD   TRUE_VAR        XROOTD_FOUND )
component_status( TESTS    BUILD_TESTS     CPPUNIT_FOUND )

message( STATUS "----------------------------------------" )
message( STATUS "Installation path: " ${CMAKE_INSTALL_PREFIX} )
message( STATUS "C Compiler:        " ${CMAKE_C_COMPILER} )
message( STATUS "C++ Compiler:      " ${CMAKE_CXX_COMPILER} )
message( STATUS "Build type:        " ${CMAKE_BUILD_TYPE} )
message( STATUS "Plug-in version:   " ${PLUGIN_VERSION} )
message( STATUS "" )
message( STATUS "LSTORE:            " ${STATUS_LSTORE} )
message( STATUS "XRootD:            " ${STATUS_XROOTD} )
message( STATUS "Tests:             " ${STATUS_TESTS} )
message( STATUS "----------------------------------------" )
