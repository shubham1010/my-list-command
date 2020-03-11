#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>


#define NORMAL_COLOR "\x1B[0m"

void printPermissions(char *dirName);
void lSubcommand(char *dirName); 
void printFilesOrDir(struct dirent *dir);
void printOwnerAndGroup(char *dirName);

void lSubcommand(char *dirName) {
	DIR *d = opendir(dirName);
	struct dirent *dir;
	
	if(d) {
		while((dir = readdir(d)) != NULL) {
			if(dir->d_name[0]!='.') {
				printf("%s",NORMAL_COLOR);
				printPermissions(dir->d_name);
				printOwnerAndGroup(dir->d_name);
				printf("\t");
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

void printOwnerAndGroup(char *dirName) {
	char temp[100];
	struct stat info;
	stat(dirName, &info);  // Error check omitted
	struct passwd *pw = getpwuid(info.st_uid);
	struct group  *gr = getgrgid(info.st_gid);

	if(pw!=0) 
		printf("\t%s",pw->pw_name);
	if(gr!=0)
		printf("\t%s",gr->gr_name);
	
	printf("\t%u",(unsigned int)info.st_size);
	strcpy(temp, ctime(&info.st_mtime));
	temp[strlen(temp)-9]='\0';
	printf("\t%s",temp);
}
