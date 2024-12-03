cmake_minimum_required(VERSION 3.12)

find_package(GTest REQUIRED)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)

file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(UNIT_TESTS_TARGET ${PROJECT_NAME}_unit_tests)
add_executable(${UNIT_TESTS_TARGET} ${TEST_SOURCES})
target_link_libraries(${UNIT_TESTS_TARGET}
    PRIVATE ${OBJECT_LIBRARY}
        GTest::GTest
        GTest::gmock
        GTest::Main
)

add_test(NAME ${UNIT_TESTS_TARGET} COMMAND ${UNIT_TESTS_TARGET})
