#include "console.h"  // Ensure the correct include path
#include <stdint.h>  // For standard integer types

const int VGA_WIDTH = 80;
const int VGA_HEIGHT = 25;
const int VGA_BYTES_PER_CHARACTER = 2;
char* const VGA_BUFFER = (char*) 0x0B8000;

static int cursor_position = 0;

static VGA_Color terminal_font_color = LIGHT_GRAY; // Default font color will be light gray
static VGA_Color terminal_background_color = BLACK; // Default background color is black

void clear_terminal() {
	for (int i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++) {
		VGA_BUFFER[i * VGA_BYTES_PER_CHARACTER] = 0x0;
        VGA_BUFFER[i * VGA_BYTES_PER_CHARACTER + 1] = 0x07; // Light gray on black
        cursor_position = 0;
	}
}

void print_character(char c) {  
    print_character_with_color(c, terminal_background_color, terminal_font_color);  
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

void set_terminal_font_color(VGA_Color col) {
    terminal_font_color = col;
}

void set_terminal_background_color(VGA_Color col) {
    terminal_background_color = col;
}

void print_line_with_color(char* str, VGA_Color bg_color, VGA_Color font_color) {
    print_string_with_color(str, bg_color, font_color);
    print_character_with_color('\n', bg_color, font_color);
}

void print_string_with_color(char* str, VGA_Color bg_color, VGA_Color font_color) {
    for (int i=0; str[i] != '\0'; i++) {
           print_character_with_color(str[i], bg_color, font_color);
    }
}

void print_character_with_color(char c, VGA_Color bg_color, VGA_Color font_color) {
    if (c == '\n') {
        cursor_position += VGA_WIDTH - (cursor_position % VGA_WIDTH);
    } else {
        VGA_BUFFER[cursor_position * VGA_BYTES_PER_CHARACTER] = c;
        VGA_BUFFER[cursor_position * VGA_BYTES_PER_CHARACTER + 1] = (bg_color << 4) | (font_color);
        cursor_position++;
    }
}