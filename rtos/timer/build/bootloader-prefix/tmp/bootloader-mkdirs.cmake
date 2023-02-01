# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/training/esp/esp-idf/components/bootloader/subproject"
  "/home/training/hiya/rtos/timer/build/bootloader"
  "/home/training/hiya/rtos/timer/build/bootloader-prefix"
  "/home/training/hiya/rtos/timer/build/bootloader-prefix/tmp"
  "/home/training/hiya/rtos/timer/build/bootloader-prefix/src/bootloader-stamp"
  "/home/training/hiya/rtos/timer/build/bootloader-prefix/src"
  "/home/training/hiya/rtos/timer/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/training/hiya/rtos/timer/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/training/hiya/rtos/timer/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
