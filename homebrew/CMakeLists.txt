add_library(HomebrewLib hsla.c)

target_include_directories(HomebrewLib
INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

set(installable_libs HomebrewLib)
install(FILES hsla.h DESTINATION INCLUDE)

enable_testing()

