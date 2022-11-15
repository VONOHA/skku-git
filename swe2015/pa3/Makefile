all : array

OBJS = array.o max_heap.o binary_serach_tree.o main.o mk_tc.o

array: $(OBJS)
	gcc -w -Wall -o $@ $^

clean:
	rm -rf *.o *.txt array
