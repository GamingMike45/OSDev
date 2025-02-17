#include <stdint.h>

void clear_terminal();

void main() {

	clear_terminal();

	char* const VGA_BUFFER = (char*) 0xb8000;
	char* str = "Hello World!";

	for (int i=0; str[i] != '\0'; i++) {
		VGA_BUFFER[i*2] = str[i];
	}
	 
	return;
}

void clear_terminal() {
	uint16_t* video_memory = (uint16_t*)0xB8000;
	uint16_t Blank = 0x0700;


	for (int i = 0; i < 2000; i++) {
		video_memory[i] = Blank;
	}
}
