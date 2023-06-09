CXX = g++
CXXFLAGS = -Wall -g -O -std=c++11
PROJ = words
OBJS = main.o counter.o



all: $(PROJ) 

$(PROJ): $(OBJS)
	$(CXX) $(OBJS) -o $(PROJ)	


clean:
	$(RM) *.o depends

-include .depends

depend:
	$(CXX) -MM $(OBJS:.o=.cc) > depends
