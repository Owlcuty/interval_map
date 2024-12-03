cmake_minimum_required(VERSION 3.16.3)

project(interval_map_proj)

add_executable ( interval_map_proj main.cpp )
target_link_libraries ( interval_map_proj ${SimpleITK_LIBRARIES} )

SET(UNIT_TESTING ON)

if(${UNIT_TESTING})
    enable_testing()
    add_subdirectory(test)
endif()
