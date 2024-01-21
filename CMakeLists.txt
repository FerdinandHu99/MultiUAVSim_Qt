cmake_minimum_required(VERSION 3.14)

project(MultiUAVSim_Qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

set(PROJECT_SOURCES
        main.cpp
        multiuavsimqmlglobal.cpp
        settingsmanage.cpp
        qml.qrc
)

set(PROJECT_HEADERS
        multiuavsimqmlglobal.h
        settingsmanage.h
)

add_executable(MultiUAVSim_Qt ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(MultiUAVSim_Qt
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

set_target_properties(MultiUAVSim_Qt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/AirLib/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/AirLib/deps/eigen3)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/AirLib/deps/rpclib/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/AirLib/deps/MavLinkCom/include)

target_link_directories(MultiUAVSim_Qt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/AirLib/lib/x64/Debug
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/AirLib/deps/MavLinkCom/lib/x64/Debug
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/AirLib/deps/rpclib/lib/x64/Debug)
target_link_libraries(MultiUAVSim_Qt PRIVATE AirLib rpc MavLinkCom)

install(TARGETS MultiUAVSim_Qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

