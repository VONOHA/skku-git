all : priority_queue

OBJS0 = array.o linked_list.o  main.o mk_tc.o max_heap.o binary_search_tree.o

priority_queue: $(OBJS0) $(OBJ1)
	gcc -w -Wall -o $@ $^

clean:
	rm -rf *.o *.txt priority_queue
