cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(chess)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
	Piece/src/Bishop.cpp
	Piece/src/Knight.cpp
	Piece/src/Pawn.cpp
	Piece/src/Piece.cpp
	Piece/src/Queen.cpp
	Piece/src/Rook.cpp
	Piece/src/TypeOfPiece.cpp

	Board/src/Board.cpp
	Board/src/BoardManager.cpp
	Board/src/Move.cpp
	Board/src/Square.cpp

	Utils/src/Position.cpp

	main.cpp
)

#add_subdirectory(${PROJECT_SOURCE_DIR}/Piece/test)

add_executable(chess ${SOURCES})

target_include_directories(chess
	PRIVATE
		${PROJECT_SOURCE_DIR}/Piece/inc
		${PROJECT_SOURCE_DIR}/Utils/inc
		${PROJECT_SOURCE_DIR}/Board/inc
)
