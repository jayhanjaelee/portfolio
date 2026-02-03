# 정적 라이브러리 file_handler 를 만든다.
add_library(file_handler STATIC file_handler.c)

# 해당 라이브러리 컴파일 시 사용할 헤더파일 경로
target_include_directories(file_handler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 해당 라이브러리를 컴파일 할 옵션
target_compile_options(file_handler PRIVATE -Wall)
