include_directories(inc)

set(SOURCES
	src/Bishop.cpp
	src/King.cpp
	src/Knight.cpp
	src/Pawn.cpp
	src/Piece.cpp
	src/Queen.cpp
	src/Rook.cpp
	src/TypeOfPiece.cpp
)

add_library(Piece STATIC ${SOURCES})

target_link_libraries(Piece Utils)

target_include_directories(Piece PRIVATE
	${PROJECT_SOURCE_DIR}/Utils/inc
)

enable_testing()
add_subdirectory(test)