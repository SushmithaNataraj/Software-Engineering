INCS=expr.hpp

OBJS=main.o expr.o

expr: $(OBJS)
	c++ --std=c++14 -O2 -o expr $(OBJS)

main.o:main.cpp
	c++ --std=c++14 -O2 -c main.cpp

expr.o:expr.cpp $(INCS)
	c++ --std=c++14 -O2 -c expr.cpp

clean:
	$(RM) expr expr.o main.o expr.o
