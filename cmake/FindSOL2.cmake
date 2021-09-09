SET(SOL2_SEARCH_PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw
        /opt/local
        /opt/csw
        /opt
        )
FIND_PATH(SOL2_INCLUDE_DIR sol.hpp
        HINTS
        $ENV{SOL2DIR}
        PATH_SUFFIXES include/sol include
        PATHS ${SOL2_SEARCH_PATHS}
        )
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SOL2 REQUIRED_VARS SOL2_INCLUDE_DIR)