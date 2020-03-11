int main(int argc, char *argv[]) {
	checkValidSubCommands(argc,argv);
	insertDataAccordingWithSubCommands(argc,argv);
}

void checkValidSubCommands(unsigned int n,char **totArgs) {
	(int i=1; i<n ; i++)	 {
		if(totArgs[i][0]=='-')
			slsSubCommands(totArgs[i]);
	}

}

void insertDataAccordingWithSubCommands(unsigned int n,char **totArgs) {
	sls *totDir = (sls *)malloc(sizeof(sls)*n);
	RBT *root=NULL;
	unsigned int cnt=0;
	for(int i=1 ; i<n ; i++) {
		if(totArgs[i][0]!='-') {
			if(sub_Command->l==1)
				l_SubCommand(totDir[i]);
			if(sub_Command->a==1) 
				a_SubCommand(totDir[i]);
			if(sub_Command->R==1) 
				R_SubCommand(totDir[i]);
			if(sub_Command->h==1) 
				h_SubCommand(totDir[i]);
			if(sub_Command->i==1) 
				i_SubCommand(totDir[i]);
			cnt+=1;

			root=insertIntoRBT(root,totArgs[i]);
		}
	}
	if(sub_Command->r==1) 
		r_SubCommand(root);
	else
		printByAsc(root);

}
