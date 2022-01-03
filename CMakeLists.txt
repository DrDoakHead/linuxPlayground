cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${PROJECT_SOURCE_DIR}/Utils)
add_subdirectory(${PROJECT_SOURCE_DIR}/Piece)
add_subdirectory(${PROJECT_SOURCE_DIR}/Board)

add_executable(chessBackend main.cpp)

target_link_libraries(chessBackend
	Utils
	Piece
 	Board
 )
 
target_include_directories(chessBackend PRIVATE
	${PROJECT_SOURCE_DIR}/Piece/inc
	${PROJECT_SOURCE_DIR}/Utils/inc
	${PROJECT_SOURCE_DIR}/Board/inc
)