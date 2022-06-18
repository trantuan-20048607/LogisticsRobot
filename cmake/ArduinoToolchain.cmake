set(CMAKE_SYSTEM_NAME Arduino)

# ================================================
#   Environment settings
# ================================================
set(ARDUINO_SDK_PATH "C:/Program Files (x86)/Arduino")  # SDK path, including "hardware" directory
set(TARGET_BOARD mega)  # Target board
# Target CPU, REMAIN EMPTY or DELETE it if TARGET_BOARD is:
#   yun, uno, megaADK, leonardo, leonardoeth, micro, esplora,
#   ethernet, fio, LilyPadUSB, robotControl, robotMotor, gemma,
#   circuitplay32u4cat, yunmini, chiwawa, one, unowifi
# Otherwise, you MUST set this variable when TARGET_BOARD is set as:
#   diecimila, nano, mega, mini, bt, lilypad, pro, atmegang
set(ARDUINO_CPU atmega2560)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)

if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/Platform/Arduino.cmake)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR})
endif ()

if (UNIX)
    include(Platform/UnixPaths)
    if (APPLE)
        list(APPEND CMAKE_SYSTEM_PREFIX_PATH ~/Applications
                /Applications
                /Developer/Applications
                /sw
                /opt/local)
    endif ()
elseif (WIN32)
    include(Platform/WindowsPaths)
endif ()

if (NOT ARDUINO_SDK_PATH)
    set(ARDUINO_PATHS)

    foreach (DETECT_VERSION_MAJOR 1)
        foreach (DETECT_VERSION_MINOR RANGE 5 0)
            list(APPEND ARDUINO_PATHS arduino-${DETECT_VERSION_MAJOR}.${DETECT_VERSION_MINOR})
            foreach (DETECT_VERSION_PATCH RANGE 3 0)
                list(APPEND ARDUINO_PATHS arduino-${DETECT_VERSION_MAJOR}.${DETECT_VERSION_MINOR}.${DETECT_VERSION_PATCH})
            endforeach ()
        endforeach ()
    endforeach ()

    foreach (VERSION RANGE 23 19)
        list(APPEND ARDUINO_PATHS arduino-00${VERSION})
    endforeach ()

    if (UNIX)
        file(GLOB SDK_PATH_HINTS /usr/share/arduino*
                /opt/local/arduino*
                /opt/arduino*
                /usr/local/share/arduino*)
    elseif (WIN32)
        set(SDK_PATH_HINTS "C:\\Program Files\\Arduino"
                "C:\\Program Files (x86)\\Arduino"
                )
    endif ()
    list(SORT SDK_PATH_HINTS)
    list(REVERSE SDK_PATH_HINTS)
endif ()

find_path(ARDUINO_SDK_PATH
        NAMES lib/version.txt
        PATH_SUFFIXES share/arduino
        Arduino.app/Contents/Resources/Java/
        Arduino.app/Contents/Java/
        ${ARDUINO_PATHS}
        HINTS ${SDK_PATH_HINTS}
        DOC "Arduino SDK path.")

if (ARDUINO_SDK_PATH)
    list(APPEND CMAKE_SYSTEM_PREFIX_PATH ${ARDUINO_SDK_PATH}/hardware/tools/avr)
    list(APPEND CMAKE_SYSTEM_PREFIX_PATH ${ARDUINO_SDK_PATH}/hardware/tools/avr/utils)
else ()
    message(FATAL_ERROR "Could not find Arduino SDK (set ARDUINO_SDK_PATH)!")
endif ()

set(ARDUINO_CPUMENU)
if (ARDUINO_CPU)
    set(ARDUINO_CPUMENU ".menu.cpu.${ARDUINO_CPU}")
endif (ARDUINO_CPU)
