#include "console.h"  // Ensure the correct include path
#include <stdint.h>  // For standard integer types

const int VGA_WIDTH = 80;
const int VGA_HEIGHT = 25;
const int VGA_BYTES_PER_CHARACTER = 2;
char* const VGA_BUFFER = (char*) 0x0B8000;

static int cursor_position = 0;

void clear_terminal() {
	for (int i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++) {
		VGA_BUFFER[i * VGA_BYTES_PER_CHARACTER] = 0x0;
        VGA_BUFFER[i * VGA_BYTES_PER_CHARACTER + 1] = 0x07; // Light gray on black
        cursor_position = 0;
	}
}

void print_character(char c) {    
    if (c == '\n') {
        cursor_position += VGA_WIDTH - (cursor_position % VGA_WIDTH);
    } else {
        VGA_BUFFER[cursor_position * VGA_BYTES_PER_CHARACTER] = c;
        VGA_BUFFER[cursor_position * VGA_BYTES_PER_CHARACTER + 1] = 0x07; // Light gray on black
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
