include_directories(inc)

set(SOURCES
	src/Position.cpp
)

add_library(Utils STATIC ${SOURCES})

enable_testing()
add_subdirectory(test)