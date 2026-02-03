# 정적 라이브러리 controller 를 만든다.
add_library(controller STATIC controller.c)

# 해당 라이브러리 컴파일 시 사용할 헤더파일 경로
target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 해당 라이브러리를 컴파일 할 옵션
target_compile_options(controller PRIVATE -Wall)
target_link_libraries(controller PRIVATE ecewo file_handler)
