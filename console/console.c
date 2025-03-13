#include "console.h"  // Ensure the correct include path
#include <stdint.h>  // For standard integer types

#define VIDEO_MEMORY (char*)0xB8000  // VGA text mode memory

const int VGA_WIDTH = 80;
const int VGA_HEIGHT = 25;
const int VGA_BYTES_PER_CHARACTER = 2;

static int cursor_position = 0;

void clear_terminal() {
	for (int i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++) {
		VGA_BUFFER[i*2] = 0x00;
        VGA_BUFFER[(i*2)+1] = 0x00;
	}
}

void print_character(char c) {
    char *video_memory = VIDEO_MEMORY;
    
    if (c == '\n') {  
        cursor_position += VGA_WIDTH - (cursor_position % VGA_WIDTH);
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
