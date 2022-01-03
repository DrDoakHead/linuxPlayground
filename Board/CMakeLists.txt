include_directories(inc)

set(SOURCES
	src/Board.cpp
	src/BoardManager.cpp
	src/Move.cpp
	src/Square.cpp
)

add_library(Board STATIC ${SOURCES})

target_link_libraries(Board 
	Piece 
	Utils
)

target_include_directories(Board PRIVATE
	${PROJECT_SOURCE_DIR}/Piece/inc
	${PROJECT_SOURCE_DIR}/Utils/inc
)

enable_testing()
add_subdirectory(test)