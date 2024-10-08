# to use cmake_print_variables function
include(CMakePrintHelpers)

# Specifying a minimum CMake version \
# This establishes policy settings and ensures that the following CMake functions are run with a compatible version of CMake
cmake_minimum_required(VERSION 3.9.1)

# set both the project name and version number. \
# CMake defines KIEN_HOANG_LEARNING_CMAKE_VERSION_MAJOR and KIEN_HOANG_LEARNING_CMAKE_VERSION_MINOR behind the scenes.
project(KIEN_HOANG_LEARNING_CMAKE VERSION 3.4)

# show value of variable                          
cmake_print_variables(PROJECT_SOURCE_DIR)
cmake_print_variables(PROJECT_BINARY_DIR)  

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(ECALL_ENABLE 66)
set(ECALL_VARIANT "PSAP ECALL IS ACTIVE")
set(ECALL_STATUS 77)
set(ECALL_RUNNING_VARIANT "ECALL_RUNNING_VARIANT_psap")

# add preprocessor definitions: Add -D define flags to the compilation of source files.
add_definitions(-DKIENMACRO="kien hoang macro")

# generate a .h file from .h.in file with value of macro are replaced by some above set(...) command
configure_file(macro.h.in macro.h @ONLY)

# This command searches for libAntennaMgr.so in ./lib/shareLib. If found, it stores the full path to the library in the ANTENNA_MGR_SHARELIB variable.
# The same with libWifiMgr.a
find_library(ANTENNA_MGR_SHARELIB AntennaMgr PATHS ./lib/shareLib/build)
find_library(WIFI_MGR_STATICLIB WifiMgr PATHS ./lib/staticLib/build)

# specify output file and source file
add_executable(fileRun main.cpp ./PowerManager/powerMgr.cpp) 

# To make use of the new library we call add_subdirectory() in the top-level CMakeLists.txt file \
# so that the library will get built. Parameter is the path to folder that contain library
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/lib64)
add_subdirectory(${PROJECT_SOURCE_DIR}/PowerManager)

# the new library target is linked to the executable target using target_link_libraries().                    
target_link_libraries(fileRun PUBLIC 
                        MyLib64Library
                        PowerManagerLib
                        ${ANTENNA_MGR_SHARELIB}
                        ${WIFI_MGR_STATICLIB}
                            )   

# specify where the executable target should look for include files (example: .h file).
target_include_directories(fileRun PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        "${PROJECT_SOURCE_DIR}/lib/lib64"
                        "${PROJECT_SOURCE_DIR}/PowerManager"
                        "${PROJECT_SOURCE_DIR}/lib/shareLib"
                        "${PROJECT_SOURCE_DIR}/lib/staticLib"
#                         #   "/home/worker/delete/cmakeTutorial/build"
#                         "${PROJECT_SOURCE_DIR}/myLib/lib64"
                          )           


                        
                          

                       


