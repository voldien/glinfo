#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void readargument(int argc, char **argv) {

	const char *shoopt = "v";
	int c;
	static struct option longoption[] = {{"version", no_argument, NULL, 'v'}, {NULL, NULL, NULL, NULL}};

	while ((c = getopt_long(argc, argv, shoopt, longoption, NULL)) != EOF) {
		switch (c) {
		case 'v':
			printf("version %s.\n", GLIF_VERSION);
			exit(EXIT_SUCCESS);
		default:
			break;
		}
	}
}
