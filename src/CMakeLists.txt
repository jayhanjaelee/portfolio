add_subdirectory(file_handler)
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE ecewo file_handler)
