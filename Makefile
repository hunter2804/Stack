cc=g++
cf=-c
app=stack

all:	$(app)

$(app): main.o stack.o
	$(cc) -o $@ $^

main.o: main.cpp
	$(cc) $(cf) $<

stack.o: stack.cpp
	$(cc) $(cf) $<

clean:
	rm *.o $(app) *.~
