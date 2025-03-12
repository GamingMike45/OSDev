#include "console.h"  // Ensure the correct include path
#include <stdint.h>  // For standard integer types

#define VIDEO_MEMORY (char*)0xB8000  // VGA text mode memory
#define SCREEN_WIDTH 80  // Number of columns in VGA mode

uint16_t cursor_position = 0;

void clear_terminal() {
	uint16_t* video_memory = (uint16_t*)0xB8000;
	uint16_t Blank = 0x0700;


	for (int i = 0; i < 2000; i++) {
		video_memory[i] = Blank;
	}
}

void print_character(char c) {
    char *video_memory = VIDEO_MEMORY;
    
    if (c == '\n') {  
        cursor_position += SCREEN_WIDTH - (cursor_position % SCREEN_WIDTH);
    } else {
        video_memory[cursor_position * 2] = c;
        video_memory[cursor_position * 2 + 1] = 0x07; // Light gray on black
        cursor_position++;
    }
}

void print_string(char* str) {
    while (*str) {
        print_character(*str);
        str++;
    }
}

void print_line(char* str) {
    print_string(str);
    print_character('\n');
}
