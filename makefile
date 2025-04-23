output: main.o contactbst.o contact.o myvector.o
	g++ main.o contactbst.o contact.o myvector.o -o cms

main.o: main.cpp
	g++ -c main.cpp

contactbst.o: contactbst.cpp contactbst.h
	g++ -c contactbst.cpp

contact.o: contact.cpp contact.h
	g++ -c contact.cpp

myvector.o: myvector.cpp myvector.h
	g++ -c myvector.cpp

clean:
	rm *.o cms