all : priority_queue

OBJS0 = array.o linked_list.o  mk_tc.o max_heap.o binary_search_tree.o
OBJS1 = array.c linked_list.c  mk_tc.c max_heap.c binary_search_tree.c

priority_queue: p_q 
	gcc -o  $@ main.c -L./ -l$^
	mv main.c source

p_q: $(OBJS0)
	ar rc libp_q.a $^
	rm -rf $^
	mv $(OBJS1) source

clean:
	rm -rf *.txt *.a priority_queue
	mv ./source/*.c .
	rm -rf ./textfile/*.txt
