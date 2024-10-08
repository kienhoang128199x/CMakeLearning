add_library(PowerManagerLib powerMgr.cpp)

option(POWER_FLAG "The flag define current power source is main" ON)

if(POWER_FLAG)
    target_compile_definitions(PowerManagerLib PUBLIC POWER_FLAG) # define POWER_FLAG macro to use in target PowerManagerLib
endif()

target_include_directories(PowerManagerLib
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/SystemPower
                           )