CPP = g++
CFLAGS = -Wall -Wextra -Werror


ttest: tree_test.cpp BST.o Node.o Glob.o TwoDArray.o
	$(CPP) $(CFLAGS) -o ttest $^

BST.o: BST.h BST.cpp
	$(CPP) $(CFLAGS) -c BST.cpp

ntest: node_test.cpp Node.o Glob.o
	$(CPP) $(CFLAGS) -o ntest node_test.cpp Node.o Glob.o

Node.o: Node.h Node.cpp
	$(CPP) $(CFLAGS) -c Node.cpp

Glob.o: Glob.h Glob.cpp
	$(CPP) $(CFLAGS) -c Glob.cpp

TwoDArray.o: TwoDArray.h TwoDArray.cpp
	$(CPP) $(CFLAGS) -c TwoDArray.cpp

clean:
	rm -f *.o;
	rm -f ntest; rm -f ttest;
	rm -f *~;
