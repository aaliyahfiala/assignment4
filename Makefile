default : Main

Main : Main.cpp Player.o Dummy.o Cave.o Event.o Room.o Start.o Bats.o Pit.o Gold.o Wumpus.o 
	g++ -g Main.cpp Player.o Dummy.o Cave.o Event.o Room.o Start.o Bats.o Pit.o Gold.o Wumpus.o -o Main

Dummy.o : Dummy.cpp Dummy.hpp
	g++ -g -c Dummy.cpp -o Dummy.o

Player.o : Player.cpp Player.hpp
	g++ -g -c Player.cpp -o Player.o

Cave.o : Cave.cpp Cave.hpp
	g++ -g -c Cave.cpp -o Cave.o

Event.o : Event.cpp Event.hpp
	g++ -g -c Event.cpp -o Event.o

Room.o : Room.cpp Room.hpp
	g++ -g -c Room.cpp -o Room.o

Start.o : Start.cpp Start.hpp
	g++ -g -c Start.cpp -o Start.o

Bats.o : Bats.cpp Bats.hpp
	g++ -g -c Bats.cpp -o Bats.o

Pits.o : Pit.cpp Pit.hpp
	g++ -g -c Pit.cpp -o Pit.o

Gold.o : Gold.cpp Gold.hpp
	g++ -g -c Gold.cpp -o Gold.o

Wumpus.o : Wumpus.cpp Wumpus.hpp
	g++ -g -c Wumpus.cpp -o Wumpus.o

clean :
	rm -f *.o Main
