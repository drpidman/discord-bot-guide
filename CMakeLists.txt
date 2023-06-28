cmake_minimum_required(VERSION 3.10)

set(PROJECT_N discord-programming-guide)
project(${PROJECT_N} VERSION 1.0 DESCRIPTION "Guide discord bot for new programmers")

include(FetchContent)

add_subdirectory(libs/DPP)
add_subdirectory(libs/cpp-dotenv)


add_custom_target(with-env
    COMMAND cp ${CMAKE_CURRENT_LIST_DIR}/.env ${CMAKE_BINARY_DIR}/.env
)

# setts
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

# a macro that gets all of the header containing directories. 
MACRO(header_directories return_list includes_base_folder extention )
    FILE(GLOB_RECURSE new_list ${includes_base_folder}/*.${extention})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

# using said macro.
header_directories(INCLUDES ${PROJECT_SOURCE_DIR}/include/ hpp)

# src files loop
message("src files:")
foreach(file ${SRCS})
        message(STATUS ${file})
endforeach()


# project include dirs
message("include directories:")
foreach(dir ${INCLUDES})
        message(STATUS ${dir})
endforeach()
add_executable(${PROJECT_N} ${SRCS})

find_package(CURL)

# libraries
target_link_libraries(${PROJECT_N} PUBLIC
    dpp
    cpp_dotenv
    ${CURL_LIBRARIES}
)

# directories includes
target_include_directories(${PROJECT_N} PRIVATE
   libs/DPP/include
)

# include_dirs
include_directories(${CURL_INCLUDE_DIR})

# project dirs
target_include_directories(${PROJECT_N} PUBLIC include)
