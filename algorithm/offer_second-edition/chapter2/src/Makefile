CC = gcc
CFLAGS = -Wall -g -std=c99

prefix := topic
topicname := $(patsubst %, %$(topicid), $(prefix))

all: $(topicname)  
	
topicname :
	$(CC) $(topicname).c $(CFLAGS) -o $(topicname)

