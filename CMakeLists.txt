cmake_minimum_required(VERSION 2.6)
project(rapid)

if   (MINGW)
        set(MINGWLIBS "${CMAKE_SOURCE_DIR}/mingwlibs" CACHE PATH "Location of the mingwlibs package")
        if(NOT EXISTS "${MINGWLIBS}" OR NOT IS_DIRECTORY "${MINGWLIBS}")
                 MESSAGE(FATAL_ERROR "MINGWLIBS is not a valid directory")
        endif ()
        include_directories(${MINGWLIBS}/include)
        message(${MINGWLIBS})
#FIXME: remove hardcoded path
        include_directories("/usr/i586-mingw32msvc/include/")
        set(CMAKE_LIBRARY_PATH ${MINGWLIBS}/lib)
        set(CMAKE_PREFIX_PATH ${MINGWLIBS})
        set(CMAKE_FIND_ROOT_PATH ${MINGWLIBS} ${CMAKE_FIND_ROOT_PATH})
        set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
        set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
        set(CMAKE_SHARED_LIBRARY_PREFIX "")
        set(CMAKE_SHARED_MODULE_PREFIX "")

        set(CMAKE_CXX_FLAGS "-Wall -O0 -g -D_WIN32_WINNT=0x0501 -fPIC")
else ()
        set(CMAKE_CXX_FLAGS "-Wall -O0 -g -fPIC")
endif ()

find_package(CURL)
find_package(ZLIB)
find_package(Boost 1.34 COMPONENTS system)
include(FindPkgConfig)

include_directories(${CURL_INCLUDE_DIR})
include_directories(${ZLIB_INCLUDE_DIR})
include_directories("src")
include_directories(".")

#----------------------------------------------------------------------------------------------------
# libtorrent-rasterbar dependency check
#----------------------------------------------------------------------------------------------------

IF (NOT WIN32)
        SET ( LIBTORRENT_MIN_VERSION 0.13 )
        pkg_check_modules( LIBTORRENT libtorrent-rasterbar>=${LIBTORRENT_MIN_VERSION} )
        IF( LIBTORRENT_FOUND )
                INCLUDE_DIRECTORIES( ${LIBTORRENT_INCLUDE_DIRS} )
                LINK_LIBRARIES( ${LIBTORRENT_LIBRARIES} )
        ELSE()
                MESSAGE( FATAL_ERROR "libtorrent-rasterbar library not found! Please install the package or toggle OPTION_TORRENT_SYSTEM to OFF")
        ENDIF()
ELSE()
        FIND_LIBRARY("LIBTORRENT_LIBRARY" NAMES "libtorrent-rasterbar" PATH "${MINGWLIBS}/lib")
        IF (LIBTORRENT_FOUND)
                MESSAGE("Found libtorrent ${LIBTORRENT_LIBRARY}")
        ENDIF()
        ADD_DEFINITIONS( -mthreads  )
        LINK_LIBRARIES( -mthreads ws2_32 mswsock  )
ENDIF ()

subdirs(src)
