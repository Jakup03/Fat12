#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2023-01-17 15:25:30.454707
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-Wall"
      "-fdiagnostics-color"
      "-Wextra"
      "-Wno-error=implicit-fallthrough"
      "-Werror=vla"
      "-D_ANSI_OUTPUT"
      "-Wno-error=parentheses"
      "-DINSIDE_DANTE"
      "-pedantic"
      "-ggdb3"
      "-xc"
      "-Werror"
      "-Wno-parentheses"
      "-std=c11"
      "-Wno-error=unused-parameter"
      "-D_GNU_SOURCE"
      "-fmax-errors=5"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-Wl,-cref"
        "-ggdb3"
        "-Wl,-wrap,main"
        "-Wl,-Map=main.map"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "file_reader.c"
        "main.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)