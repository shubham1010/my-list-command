CC=gcc  #compiler
TARGET=myls #target file name
 
all:
	$(CC)  -Wall myls.c justNameOfDirectories.c  -o $(TARGET) && sudo cp -r $(TARGET) /bin 
 
clean:
	rm $(TARGET)
