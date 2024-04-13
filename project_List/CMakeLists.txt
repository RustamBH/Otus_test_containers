cmake_minimum_required(VERSION 3.5)

project(project_List)

#download googletest sources at configure time to build directory
#build from sources at build time
include(FetchContent)
#describe how to get content
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
#it is advisable to use a hash for GIT_TAG rather than a branch or tag name.
#A commit hash is more secure and helps to confirm that the downloaded contents are what you expected.
  GIT_TAG        f8d7d77c06936315286eb55f8de22cd23c188571 # release-1.14
)
#make sure that all the dependencies are available
FetchContent_MakeAvailable(googletest)

#no add_subdirectory to googletest requires!

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Main target
add_executable(
    MyList
    src/MyList.cpp
    src/MyList.h
)

# Test target
add_executable(
    test_mylist
    test/test_mylist.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    test_mylist PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Link test target against gtest libraries
target_link_libraries(
    test_mylist PRIVATE
    gtest
)

set_target_properties(MyList PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(test_mylist PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        MyList PRIVATE
        /W4
    )
    target_compile_options(
        test_mylist PRIVATE
        /W4
    )
else ()
    target_compile_options(
        MyList PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_mylist PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
