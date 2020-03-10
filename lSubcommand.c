#include<dirent.h>
#include<stdio.h>
#include <sys/stat.h>
#include<stdlib.h>
#define NORMAL_COLOR "\x1B[0m"
void printPermissions(char *dirName);
void lSubcommand(char *dirName); 
void printFilesOrDir(struct dirent *dir);

void lSubcommand(char *dirName) {
	DIR *d = opendir(dirName);
	struct dirent *dir;
	
	if(d) {
		while((dir = readdir(d)) != NULL) {
			if(dir->d_name[0]!='.') {
				printPermissions(dir->d_name);
				printf("\t");
				/*printOwner(dir->d_name);
				printGroup(dir->d_name);
				printSize(dir->d_name);
				printBornTime(dir->d_name);*/
				printFilesOrDir(dir);
				printf("\n");
			}
		}
	}
	closedir(d);
}

void printPermissions(char *dirName) {
	struct stat fileStat;
    if(stat(dirName,&fileStat) < 0) {
        printf("Something went wrong!");
		exit(1);
	}
	printf("%s",NORMAL_COLOR);
	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
}
