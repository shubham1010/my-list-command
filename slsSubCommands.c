void slsSubCommands(char *command) {
	unsigned int l=strlen(command);
	for(int i=1 ; i<l ; i++) {
		switch(command[i]) {
			case 'l':
				sub_Command->l=1;
				break;
			case 'a':
				sub_Command->a=1;
				break;
			case 'i':
				sub_Command->i=1;
				break;
			case 'r':
				sub_Command->r=1;
				break;
			case 'R':
				sub_Command->R=1;
				break;
			case 'h':
				sub_Command->h=1;
				break;
			default:
				printf("\nsls: invalid option -- '%c'\nTry 'sls --help' for more information.",command[i]);
				exit(0);
		}
	}
}
