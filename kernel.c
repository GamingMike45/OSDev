#include <stdint.h>
#include "console.h"
char* const VGA_BUFFER = (char*) 0x0B8000;

void main() {

	clear_terminal();
	print_string("Hello");
	print_line(" WORLD");
	print_string("TODAY");


	return;
}
