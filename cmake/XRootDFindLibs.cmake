#-------------------------------------------------------------------------------
# Find the required libraries
#-------------------------------------------------------------------------------

find_package( XRootD REQUIRED )

find_package( apr REQUIRED )
find_package( zmq REQUIRED )
find_package( lstore REQUIRED )

if( ENABLE_TESTS )
  find_package( CPPUnit )
  if( CPPUNIT_FOUND )
    set( BUILD_TESTS TRUE )
  else()
    set( BUILD_TESTS FALSE )
  endif()
endif()
