file = $(target)
single:
	g++ $(file).cpp
a.out: server.o client.o
	g++ $(file).o $(file)_client.o
server.o: $(file).h $(file).cpp
	g++ -c $(file).cpp
client.o: $(file)_client.cpp $(file).h
	g++ -c $(file)_client.cpp
clean:
	rm *.o a.out
