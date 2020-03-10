#include<string.h>

void lSubcommand(char *dirName);
void executeSubcommand(char *commands,char *dirName) {
	for(int i=1 ; i<strlen(commands) ; i++) {
		switch(commands[i]) {
			case 'l':
				lSubcommand(dirName);
				break;
			/*case 'a':
				aSubcommand(dirName);
				break;
			case 'r':
				rSubcommand(dirName);
				break;
			case 'R':
				RSubcommand(dirName);
				break;
			*/
		}
	}
}
