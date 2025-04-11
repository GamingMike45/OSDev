#include <stdint.h>
#include "console.h"

void main() {

	clear_terminal();
	print_string("Hello");
	print_line(" WORLD");
	print_string("TODAY");

	return;
}
