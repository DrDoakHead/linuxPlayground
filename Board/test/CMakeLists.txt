include(GoogleTest)

set(SOURCES
    TestBoard.cpp
    TestBoardManager.cpp
    TestMove.cpp
    TestSquare.cpp
)

add_executable(testBoard ${SOURCES})

target_link_libraries(
    testBoard 
    gtest 
    gmock_main
    Board
)

target_include_directories(testBoard PRIVATE
    ${PROJECT_SOURCE_DIR}/Utils/inc
    ${PROJECT_SOURCE_DIR}/Piece/inc
)