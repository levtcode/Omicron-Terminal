cmake_minimum_required(VERSION 3.20)
project(omicron LANGUAGES C)

# Este archivo lista TODOS los archivos del proyecto, incluidos los vacíos.
# La idea es no volver a tocarlo: es el que más conflictos de git genera.

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)  # gnu11: hace falta para POSIX/BSD (termios, ioctl)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

option(OMICRON_WERROR "Tratar warnings como errores" ON)
add_compile_options(-Wall -Wextra -Wshadow -Wvla)
if(OMICRON_WERROR)
    add_compile_options(-Werror)
endif()

include_directories(include)

# --- Selección de plataforma -------------------------------------------------
# Nunca un sandbox_generic.c que no haga nada: un binario que dice que aísla
# y no aísla es peor que no tener binario. Si no hay implementación, se aborta.
if(APPLE)
    set(OM_SANDBOX_SRC src/sandbox_darwin.c)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(OM_SANDBOX_SRC src/sandbox_linux.c)
else()
    message(FATAL_ERROR
        "Omicron: no hay sandbox para ${CMAKE_SYSTEM_NAME}. "
        "Se aborta antes que generar un binario sin aislamiento real.")
endif()

# --- Binario -----------------------------------------------------------------
add_executable(omicron
    src/main.c
    src/policy.c
    src/pty.c
    ${OM_SANDBOX_SRC}
)

# --- Tests -------------------------------------------------------------------
# tests/sandbox_null.c es un doble de test. Solo aparece en estos targets:
# el binario omicron no tiene forma de linkearlo.
enable_testing()

add_executable(test_policy tests/test_policy.c src/policy.c)
add_executable(test_pty    tests/test_pty.c    src/pty.c src/policy.c tests/sandbox_null.c)
add_executable(test_fdleak tests/test_fdleak.c src/pty.c src/policy.c tests/sandbox_null.c)
add_executable(test_sandbox tests/test_sandbox.c src/policy.c ${OM_SANDBOX_SRC})

foreach(t test_policy test_pty test_fdleak test_sandbox)
    add_test(NAME ${t} COMMAND ${t})
    # 77 = el test todavía es un stub; ctest lo reporta como Skipped, no como Passed.
    set_tests_properties(${t} PROPERTIES SKIP_RETURN_CODE 77)
endforeach()
