cmake_minimum_required(VERSION 3.15)
project(Rathaus VERSION 1.0 DESCRIPTION "Rathaus Discord Main Bot")

add_subdirectory(libs/DPP)
add_subdirectory(libs/sqlpp11)

# Create an executable
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Bot.cpp src/Bot.h src/util.h
        src/sensitive.h)

# Linking libraries
target_link_libraries(${PROJECT_NAME}
        dpp
        sqlpp11
        )

# Specify includes
target_include_directories(${PROJECT_NAME} PRIVATE
        libs/DPP/include
        libs/sqlpp11/include
        )

# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )