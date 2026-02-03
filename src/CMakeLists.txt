add_subdirectory(file_handler)
add_subdirectory(controller)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE
  ecewo
  ecewo::ecewo
  ecewo::fs
  ecewo::static
  controller
)

# Platform-aware public directory handling
if(WIN32)
    # Windows: Copy directory (symlinks require admin privileges)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/public
            ${CMAKE_BINARY_DIR}/public
        COMMENT "Copying public directory to build folder"
    )
else()
    # Linux/Mac: Create symlink (faster, no duplication)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_SOURCE_DIR}/public
            ${CMAKE_BINARY_DIR}/public
        COMMENT "Creating symlink to public directory"
    )
endif()

