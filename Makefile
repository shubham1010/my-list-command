CC=gcc  #compiler
TARGET=myls #target file name
 
all:
	$(CC)  -Wall myls.c justNameOfDirectories.c  executeSubcommands.c isSubcommand.c lSubcommand.c -o $(TARGET) && sudo mv $(TARGET) /bin 
 
clean:
	rm $(TARGET)
