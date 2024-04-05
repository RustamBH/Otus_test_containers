# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-src"
  "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-build"
  "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/MyProjectsVSCode/OTUS/16_hw/project_List/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
