#include<dirent.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>

#define NORMAL_COLOR "\x1B[0m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"

void printFilesOrDir(struct dirent *dir);
void justNameOfDirectories(char *dirName);

void justNameOfDirectories(char *dirName) {
	DIR *d = opendir(dirName);
	struct dirent *dir;

	if(d) {
		while((dir = readdir(d)) != NULL) {
			if(dir->d_name[0]!='.') {
				printFilesOrDir(dir);
			}
		}
	}
	else if(ENOENT == errno) {
		printf("myls: cannot access '%s': No such file or directory",dirName);	
	}
	else
		printf("\nSomething went wrong");

	closedir(d);
}

void printFilesOrDir(struct dirent *dir) {
	if(dir->d_type != DT_DIR)
		printf("%s%s\t",GREEN,dir->d_name);
	else
		printf("%s%s\t",BLUE,dir->d_name);
}
