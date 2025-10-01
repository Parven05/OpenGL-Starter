cmake_minimum_required(VERSION 3.16)

# Project setup
project(main CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ✅ Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files
file(GLOB SOURCES src/*.cpp)

# Find dependencies
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCES})

# ✅ Add include/ so headers like core.hpp work
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        SDL3::SDL3
        OpenGL::GL
        GLEW::GLEW
)

# ✅ Auto-copy compile_commands.json into project root
if(EXISTS "${CMAKE_BINARY_DIR}/compile_commands.json")
    file(COPY "${CMAKE_BINARY_DIR}/compile_commands.json"
         DESTINATION "${CMAKE_SOURCE_DIR}")
endif()

