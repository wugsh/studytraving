CC = gcc
CFLAGS = -Wall -g -std=c99

obj_3 := topic3
obj_3_change1 := topic3_change1

obj := $(obj_3) $(obj_3_change1)
debug_obj := $(patsubst %, %_debug, $(obj))

all : $(obj)
debug: $(debug_obj)



obj_3 :  
	$(CC) $(CFLAGS) $(obj_3).c -o $(obj_3)
obj_3_change1 :
	$(CC) $(CFLAGS) $(obj_3_change1).c -o $(obj_3_change1)
$(obj_3)_debug:
	@$(CC) $(CFLAGS) $(obj_3).c -o $(obj_3)_debug -DDEBUG=1
$(obj_3_change1)_debug:
	@$(CC) $(CFLAGS) $(obj_3_change1).c -o $(obj_3_change1)_debug

.PHONY:	clean

clean:
	@rm -rf $(obj) $(debug_obj)
