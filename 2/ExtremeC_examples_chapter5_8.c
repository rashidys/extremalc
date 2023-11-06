int main(int argc, char** argv){

	char* ptr = (char*)malloc(16 * sizeof(char));

	ptr = (char*)realloc(32 * sizeof(char));

	free(ptr);
	return 0;
}
