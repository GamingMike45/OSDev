#ifndef MYOS_INCLUDE_CONSOLE_H
#define MYOS_INCLUDE_CONSOLE_HMYOS_INCLUDE_CONSOLE_H
// Futer Code will Go here
#endif

extern char* const VGA_BUFFER;
extern const int VGA_WIDTH;
extern const int VGA_HEIGHT;
extern const int VGA_BYTES_PER_CHARACTER;

void clear_terminal();
void print_character(char c);
void print_string(char* str);
void print_line(char* str);
