cmake_minimum_required(VERSION 3.5)

project(V2V)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

find_package(libcluon REQUIRED)
include_directories(SYSTEM ${CLUON_INCLUDE_DIRS})

add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/Messages.cpp
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND cluon-msc --cpp-sources --cpp-add-include-file=Messages.hpp --out=${CMAKE_BINARY_DIR}/Messages.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Messages.odvd
        COMMAND cluon-msc --cpp-headers --out=${CMAKE_BINARY_DIR}/Messages.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Messages.odvd
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Messages.odvd)

include_directories(SYSTEM ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME}.Service ${CMAKE_CURRENT_SOURCE_DIR}/V2VService.cpp ${CMAKE_BINARY_DIR}/Messages.cpp)
target_link_libraries(${PROJECT_NAME}.Service ${CLUON_LIBRARIES})

# enable_testing()
# add_executable(${PROJECT_NAME}-Runner ${CMAKE_CURRENT_SOURCE_DIR}/[...].cpp ${CMAKE_BINARY_DIR}/[...].cpp)
# target_link_libraries(${PROJECT_NAME}-Runner ${CLUON_LIBRARIES})

# add_test(NAME ${PROJECT_NAME}-Runner COMMAND ${PROJECT_NAME}-Runner)
