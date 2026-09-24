cmake_minimum_required(VERSION 4.2)

# enable import std;
# the uuid here should be the exact one based on cmake version
# also this should be before any C++ is mentioned, so it is safest
# to put it above project command
# In order to find uuid for your version
# 1. Check your installed CMake version by running 
#    cmake --version in your terminal.
# 2. Go to the CMake GitHub Repository or GitLab Repository.
# 3. Switch the branch/tag in the URL to match your exact 
#    version (for example, v4.2.3 for default cmake on ubuntu 26).
# 4. Navigate to or open the file Help/dev/experimental.rst.
# 5. Look for the UUID listed under the C++ import std support section.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")

# CMake creates the standard-library module target during project(), so this
# must be set first to keep its BMI flags consistent with application targets.
set(CMAKE_CXX_EXTENSIONS OFF)

project(APCProject LANGUAGES CXX)

# create compile_commands.json for vscode
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# enable modules support for cpp
set(CMAKE_CXX_MODULE_STD 1)

# Use C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable strict warnings supported by Clang.
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Wmissing-include-dirs
        -Wredundant-decls
        -Wstrict-overflow
        -Wundef
        -Wnull-dereference
        -Walloca
        -Werror=vla
    )
endif()

# Add executable
add_executable(${PROJECT_NAME} main.cpp)

# Add threading support
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
