CC=g++
CFLAGS=-I.
DEPS = ../include/BinaryTree.hpp \
			 ../src/BalancedBinaryTree.hpp \
			 ../src/Node.hpp \
			 ../main.cpp

OBJ =  ../main.o

./%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

binary-trees: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) 

clean:
		rm -rf *o ./binary-trees

		rm -rf *o ../include/*.o
		rm -rf *o ../src/*.o
		rm -rf *o ../*.o