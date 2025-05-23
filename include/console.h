#ifndef MYOS_INCLUDE_CONSOLE_H
#define MYOS_INCLUDE_CONSOLE_HMYOS_INCLUDE_CONSOLE_H

void clear_terminal();
void print_character(char c);
void print_string(char* str);
void print_line(char* str);

typedef enum {
    BLACK=0, 
    BLUE,  
    GREEN,  
    CYAN,
    RED,
    MAGENTA, 
    BROWN, 
    LIGHT_GRAY, 
    DARK_GRAY, 
    LIGHT_BLUE,  
    LIGHT_GREEN,   
    LIGHT_CYAN,   
    LIGHT_RED,  
    LIGHT_MAGENTA,  
    YELLOW,    
    WHITE
}VGA_Color;

void print_character_with_color(char c, VGA_Color bg_color, VGA_Color font_color);
void print_string_with_color(char* str, VGA_Color bg_color, VGA_Color font_color);
void print_line_with_color(char* str, VGA_Color bg_color, VGA_Color font_color);
void set_terminal_font_color(VGA_Color col);
void set_terminal_background_color(VGA_Color col);
void update_cursor();

#endif