include(GoogleTest)

set(SOURCES
	TestBishop.cpp
	TestKing.cpp
	#TestKnight.cpp
	#TestPawn.cpp
	#TestQueen.cpp
	#TestRook.cpp
)

add_executable(testPiece ${SOURCES})

target_link_libraries(
	testPiece 
	gtest 
	gmock_main
	Piece
)

target_include_directories(testPiece PRIVATE
	${PROJECT_SOURCE_DIR}/Utils/inc
)