#include <stdio.h>
#define True 1
#define False 0

void justNameOfDirectories(char *dirname);
int main(int argc, char *argv[]) {
	
	switch(argc) {
		
		case 1:
			justNameOfDirectories(".");
			break;
		
		case 2:
			if(!isSubcommand(argv[1]))
				justNameOfDirectories(argv[1]);
			else
				executeSubcommand(argv[1])
			break;
	}
}
