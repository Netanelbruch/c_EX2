CC = gcc 
AR = ar
FLAGS= -Wall -g

OBJEKTS_MAIN=main.c
OBJEKTS_MAINO=main.o
OBJEKTS_MATO=my_mat.o
OBJEKTS_MATC=my_mat.c


all: connections 

connections: $(OBJEKTS_MAINO) libmy_mat.a
	$(CC) -o connections $(OBJEKTS_MAINO) libmy_mat.a

libmy_mat.a: $(OBJEKTS_MATO)
	$(AR) -rcs libmy_mat.a $(OBJEKTS_MATO)

main.o: $(OBJEKTS_MAIN) my_mat.h
	$(CC) $(FLAGS) -c $(OBJEKTS_MAIN) 

my_math.o: $(OBJEKTS_MATC) my_mat.h
	$(CC) $(FLAGS) -c $(OBJEKTS_MATC) 


.PHONY: clean all

clean:
	rm -f *.o connections *.a
