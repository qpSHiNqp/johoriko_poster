#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int c;
	FILE *fp;
	char buf[9];

	if (argc != 2) {
		printf("usage: %s filename\n", argv[0]);
		exit(0);
	}
	fp = fopen(argv[1], "wb");
	if(fp == NULL) {
		printf("file open error\n");
		exit(0);
	}
	while (fgets(buf, 9, stdin) != NULL) {
		printf("%s\n", buf);
		c = strtol(buf, NULL, 2);
		fputc(c, fp);
	}
	fclose(fp);
	printf("exitting...\n");
	return 0;
}

