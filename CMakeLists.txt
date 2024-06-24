cmake_minimum_required(VERSION 3.16)

project(tessellation VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_standard_project_setup()

qt_add_executable(tessellation
  main.cpp
  TessellationView.cpp
  Sierpinski.cpp
  SierpinskiTiles.cpp
)

target_link_libraries(tessellation PRIVATE Qt6::Widgets)
set_target_properties(tessellation PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
)
