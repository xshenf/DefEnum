cmake_minimum_required(VERSION 3.5)

project(DefEnum VERSION 0.0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
include(GNUInstallDirs)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME}
		INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
		)

add_executable(example Example/example.cpp)
target_link_libraries(example ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
	EXPORT ${PROJECT_NAME}Targets
)
install (EXPORT ${PROJECT_NAME}Targets
  FILE ${PROJECT_NAME}Config.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)
install(DIRECTORY include/ DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

