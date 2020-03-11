#include<stdio.h>
#include<stdlib.h>

typedef struct Struct-My-List-Command {
	char dirName[100];
	unsigned long int inode;
	char permission[11];
	char username[100];
	char groupname[100];
	unsigned long int size;
	char lastModifiedTime[50];
	unsigned int numDir;

}sls;

typedef struct StructRedBlackTree{
	sls *data;
	struct StructRedBlackTree *left,*right;
}

typedef struct Struct-Sub-Commands {
	int l;
	int a;
	int R;
	int r;
	int h;
	int i;
}sub_Command;
