#include <stdio.h>

void justNameOfDirectories(char *dirname);
void executeSubcommand(char *commands,char *dirName);
char isSubcommand(char *str);

int main(int argc, char *argv[]) {
	char ch;
	switch(argc) {
		
		case 1:
			justNameOfDirectories(".");
			break;
		
		case 2:
			if(argv[1][0]=='-') {
				ch=isSubcommand(argv[1]);
				if(ch==' ')
					executeSubcommand(argv[1],".");
				else {
					printf("myls: invalid option -- '%c'\nTry 'myls --help' for more information.",ch);
				}
					
			}
			else
				justNameOfDirectories(argv[1]);
			break;
	}
}

