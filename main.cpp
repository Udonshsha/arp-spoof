#include "lihd.h"
#include "pch.h"
#include "fnc.h"

int main(int argc, char *argv[]){
	if (argc < 3 || argc % 2 == 1){
		miss_out();
		return 0;
	}
	else
		nomal_out();

	char *iface = argv[1];

	for (int i = 2; i < argc; i += 2){
		pid_t pid = fork(); 
		if (pid == 0){ 
			process_ip_pair(iface, argv[i], argv[i + 1]);
			exit(1); 
		}
		else if(pid < 0){
			fprintf(stderr,"fork failed");
			exit(2);
		}
	}

	for (int i = 2; i < argc; i += 2){
		wait(NULL);
	}

	return 0;
}
