# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/aurenciabarton/esp/esp-idf/components/bootloader/subproject"
  "/Users/aurenciabarton/Team1917-VR-Glove/build/bootloader"
  "/Users/aurenciabarton/Team1917-VR-Glove/build/bootloader-prefix"
  "/Users/aurenciabarton/Team1917-VR-Glove/build/bootloader-prefix/tmp"
  "/Users/aurenciabarton/Team1917-VR-Glove/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/aurenciabarton/Team1917-VR-Glove/build/bootloader-prefix/src"
  "/Users/aurenciabarton/Team1917-VR-Glove/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/aurenciabarton/Team1917-VR-Glove/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/aurenciabarton/Team1917-VR-Glove/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
