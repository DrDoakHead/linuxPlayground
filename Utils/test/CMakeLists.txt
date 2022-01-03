include(GoogleTest)

set(SOURCES
	TestPosition.cpp
)

add_executable(testUtils ${SOURCES})

target_link_libraries(testUtils gtest gmock_main)