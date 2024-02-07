CC = gcc
AR = ar
FLAGS= -Wall -g

OBJEKTS_MAIN=my_graph.c
OBJEKTS_MAINO=my_graph.o
OBJEKTS_MATO=my_mat.o
OBJEKTS_MATC=my_mat.c


all: my_graph

connections: $(OBJEKTS_MAINO) libmy_mat.a
	$(CC) -o my_graph $(OBJEKTS_MAINO) libmy_mat.a

libmy_mat.a: $(OBJEKTS_MATO)
	$(AR) -rcs libmy_mat.a $(OBJEKTS_MATO)

main.o: $(OBJEKTS_MAIN) my_mat.h
	$(CC) $(FLAGS) -c $(OBJEKTS_MAIN) 

my_math.o: $(OBJEKTS_MATC) my_mat.h
	$(CC) $(FLAGS) -c $(OBJEKTS_MATC) 


.PHONY: clean all

clean:
	rm -f *.o my_graph *.a
