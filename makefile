CC = gcc
AR = ar
FLAGS= -Wall -g

OBJEKTS_MAIN=my_graph.c
OBJEKTS_MAINO=my_graph.o
OBJEKTS_MATO=my_mat.o
OBJEKTS_MATC=my_mat.c


all: my_graph $(OBJEKTS_MAINO) $(BJEKTS_MATO)

my_graph: $(OBJEKTS_MAINO) libmy_mat.a
	$(CC) -o my_graph $(OBJEKTS_MAINO) libmy_mat.a

libmy_mat.a: $(OBJEKTS_MATO)
	$(AR) -rcs libmy_mat.a $(OBJEKTS_MATO)

$(OBJEKTS_MAINO): $(OBJEKTS_MAIN) my_mat.h
	$(CC) $(FLAGS) -c $(OBJEKTS_MAIN) 

$(BJEKTS_MATO): $(OBJEKTS_MATC) my_mat.h
	$(CC) $(FLAGS) -c $(OBJEKTS_MATC) 


.PHONY: clean all

clean:
	rm -f *.o my_graph *.a
