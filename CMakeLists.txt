### version settings
set(ENGINE_VERSION_MAJOR 0)
set(ENGINE_VERSION_MINOR 1)
set(ENGINE_VERISON_PATCH 0)
set(ENGINE_VERSION "${ENGINE_VERSION_MAJOR}.${ENGINE_VERSION_MINOR}.${ENGINE_VERISON_PATCH}")
###// version settings

### options
# option(CSD_DEBUG_MODE "debug settings are set to true" OFF)
# ###// options

# if(CSD_DEBUG_MODE)
# message("debug mode on")    
# else()
# message("debug mode off")    
# endif(CSD_DEBUG_MODE)

### verifying plataforms
if (NOT WIN32 AND NOT UNIX AND NOT APPLE)
  message(FATAL_ERROR "Unsupported operating system. Only Windows, Mac and Unix systems supported.")
endif (NOT WIN32 AND NOT UNIX AND NOT APPLE)
###// verifying plataform

### CMake Headers
cmake_minimum_required(VERSION 3.1.0)
cmake_policy(SET CMP0048 NEW)
project(SimpleVulkanEngine VERSION ${ENGINE_VERSION})
###// cmake header


### In-source builds are disabled.
if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_BINARY_DIR}")
    message(FATAL_ERROR
    "CMake generation is not possible within the source directory!"
    "\n Remove the CMakeCache.txt file and try again from another folder, e.g.:"
    "\n "
    "\n rm CMakeCache.txt"
    "\n mkdir build"
    "\n cd build"
    "\n cmake ..")
endif()
###// In-source builds are disabled.

### cmake flags
set(CMAKE_OSX_ARCHITECTURES x86_64)
set(CMAKE_BUILD_TYPE=Debug)
###// cmake flags

### set lists
set(INCLUDES_LIST "")
set(LINKS_LIST "")
set(CFLAGS_LIST "")
set(DEFINES_LIST "")
###// set lists
### plataform settings
if(MSVC OR MINGW OR MSYS)### windows plataform
    set(PLATAFORM WINDOWS)
    ### Windows kits
    set(WINDOWS_SDK_LIBRARIES "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.17763.0/um/x86")
    set(WINDOWS_SDK_INCLUDES "C:/Program Files (x86)/Windows Kits/10/Include/10.0.17763.0/um")
    list(APPEND INCLUDES_LIST ${WINDOWS_SDK_INCLUDES})
    list(APPEND LINKS_LIST "${WINDOWS_SDK_LIBRARIES}/User32.lib")


    ###// Windows kits
    if(MSVC) # visual studio compiler
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Zi -02" )
    else() # using MinGW
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++0x -Wall " )
    endif(MSVC)

elseif(UNIX AND NOT APPLE) ### linux plataform

    set(PLATAFORM UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++0x -Wall " )
    find_package(PkgConfig REQUIRED)

    pkg_check_modules(GLFW REQUIRED glfw3)
    if(GLFW_FOUND)
        list(APPEND INCLUDES_LIST ${GLFW_INCLUDE_DIRS})
        list(APPEND LINKS_LIST ${GLFW_LIBRARIES})
    endif(GLFW_FOUND)

else()### APPLE plataform
    
    set(PLATAFORM APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++0x -Wall " )
    find_package(PkgConfig REQUIRED)
    
    pkg_check_modules(GLFW REQUIRED glfw3)
    if(GLFW_FOUND)
        list(APPEND INCLUDES_LIST ${GLFW_INCLUDE_DIRS})
        list(APPEND LINKS_LIST ${GLFW_LIBRARIES})
    endif(GLFW_FOUND)

endif()
###// plataform settings

### install settings
set(BUILD_RESULT_DIR "${CMAKE_SOURCE_DIR}/_install")
set(CMAKE_INSTALL_PREFIX "${BUILD_RESULT_DIR}/${PLATAFORM}")
set(CMAKE_SKIP_BUILD_RPATH  FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${BUILD_RESULT_DIR}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
###// install settings


### find general package modules
find_package(Vulkan REQUIRED)
if(VULKAN_FOUND)
    message("VULKAN found")
    list(APPEND INCLUDES_LIST ${Vulkan_INCLUDE_DIRS})
    list(APPEND LINKS_LIST ${Vulkan_LIBRARIES})
endif(VULKAN_FOUND)

###//find genreal package modules

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    message("--- debug mode ---")
    add_subdirectory(external)
    # get_directory_property(IMGUI_SOURCES DIRECTORY external DEFINITION IMGUI_SOURCES)
    get_directory_property(EXTERNAL_HEADERS DIRECTORY external DEFINITION EXTERNAL_HEADERS)
    get_directory_property(EXTERNAL_SOURCES DIRECTORY external DEFINITION EXTERNAL_SOURCES)
    list(APPEND INCLUDES_LIST ${EXTERNAL_HEADERS})
    list(APPEND LINKS_LIST ${EXTERNAL_SOURCES})
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    message("--- release mode ---")
endif()

### set directory of the targets  in build
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${PLATAFORM}/lib")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${PLATAFORM}/bin")
###// set directory of the targets in build

###// find package modules

add_subdirectory(sources)
get_directory_property(INCLUDES_LIST DIRECTORY sources DEFINITION INCLUDES_LIST)
get_directory_property(LINKS_LIST DIRECTORY sources DEFINITION LINKS_LIST)
add_subdirectory(tests)