# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/crisiumnih/esp/esp-idf/components/bootloader/subproject"
  "/home/crisiumnih/stuff/River_cleaning_robot/river/build/bootloader"
  "/home/crisiumnih/stuff/River_cleaning_robot/river/build/bootloader-prefix"
  "/home/crisiumnih/stuff/River_cleaning_robot/river/build/bootloader-prefix/tmp"
  "/home/crisiumnih/stuff/River_cleaning_robot/river/build/bootloader-prefix/src/bootloader-stamp"
  "/home/crisiumnih/stuff/River_cleaning_robot/river/build/bootloader-prefix/src"
  "/home/crisiumnih/stuff/River_cleaning_robot/river/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/crisiumnih/stuff/River_cleaning_robot/river/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/crisiumnih/stuff/River_cleaning_robot/river/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
