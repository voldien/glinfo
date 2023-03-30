#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void readargument(int argc, char **argv) {

	const char *shoopt = "v";
	int c;
	static struct option longoption[] = {{"version", no_argument, nullptr, 'v'}, {nullptr, 0, nullptr, 0}};

	while ((c = getopt_long(argc, argv, shoopt, longoption, nullptr)) != EOF) {
		switch (c) {
		case 'v':
			printf("version %s.\n", GLIF_VERSION);
			exit(EXIT_SUCCESS);
		default:
			break;
		}
	}
}
