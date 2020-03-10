#include<string.h>
#include<stdio.h>

char isSubcommand(char *str) {
	int l=strlen(str);
	for(int i=1 ; i<l ; i++) {
		switch(str[i]) {
			case 'l' :
				break;
			case 'a':
				break;
			case 'i':
				break;
			case 'r':
				break;
			case 'd':
				break;
			default:
				return str[i];
		}
	}
	return ' ';
}
