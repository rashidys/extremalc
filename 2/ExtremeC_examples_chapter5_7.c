#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	char* ptr = (char*)malloc(16 * sizeof(char));
	memset(ptr, 0, 16 * sizeof(char));
	memset(ptr, 0xff, 16 * sizeof(char));

	free(ptr);
	return 0;

}
