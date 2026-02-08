/**
 * @file file_handler.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-29 22:17
 */

#include "file_handler.h"

#include <stdio.h>
#include <stdlib.h>

char *read_file(char *filename) {
    char *buffer = 0;
    long length;
    FILE *f = fopen(filename, "rb"); // 파일 열기

    if (f) {
        fseek(f, 0, SEEK_END); // 파일 포인터의 위치를 파일의 끝으로 설정.
        length = ftell(f); // 스트림 위치 지정자의 현재 위치를 구한다; 파일 끝까지 텍스트 길이를 구함.
        fseek(f, 0, SEEK_SET); // 파일 포인터를 다시 처음으로 설정.
        buffer = (char *)malloc(length + 1); // 전체 파일 크기 + NULL 종료 문자 공간.
        if (buffer) {
            fread(buffer, 1, length, f); // 파일 읽어서 첫번째 파라미터 buffer 에 할당.
            buffer[length] = '\0'; // NULL 종료 문자 추가.
        }
        fclose(f); // 파일 닫기.
    }

    return buffer; // buffer 가 존재하지 않는다면 NULL이 리턴될것임.
}

