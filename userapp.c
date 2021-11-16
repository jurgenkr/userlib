#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#include "csse332_lib.h"

int
main(int argc, char **argv)
{
	int err;

	printf("Registering process\n");
	err = register_process();
	if (err < 0) {
		printf("Error registering\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < 50; i++) {
		printf("Process %d completing iteration %d\n", getpid(), i);
		double x = 2.0;
		for(int j = 0; j < 100000000;j++)
			x = x * x;
	}

	// deregister the process
	printf("Deregistering process\n");
	err = withdraw_process();
	if (err < 0) {
		printf("Error deregistering process\n");
		exit(EXIT_FAILURE);
	}
}
