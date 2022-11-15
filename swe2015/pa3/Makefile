all : priority_queue

OBJS0 = array.o linked_list.o  main.o mk_tc.o
OBJS1 = max_heap.o binary_serach_tree.o

priority_queue: $(OBJS0) #$(OBJ1)
	gcc -w -Wall -o $@ $^

clean:
	rm -rf *.o *.txt array
