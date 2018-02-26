default : Main

Main : Main.cpp Player.o Cave.o Event.o Room.o Start.o Bats.o Pit.o Gold.o Wumpus.o 
	g++ Main.cpp Player.o Cave.o Event.o Room.o Start.o Bats.o Pit.o Gold.o Wumpus.o -o Main

Player.o : Player.cpp Player.hpp
	g++ -c  Player.cpp -o Player.o

Cave.o : Cave.cpp Cave.hpp
	g++ -c  Cave.cpp -o Cave.o

Event.o : Event.cpp Event.hpp
	g++ -c  Event.cpp -o Event.o

Room.o : Room.cpp Room.hpp
	g++ -c  Room.cpp -o Room.o

Start.o : Start.cpp Start.hpp
	g++ -c  Start.cpp -o Start.o

Bats.o : Bats.cpp Bats.hpp
	g++ -c  Bats.cpp -o Bats.o

Pits.o : Pit.cpp Pit.hpp
	g++ -c  Pit.cpp -o Pit.o

Gold.o : Gold.cpp Gold.hpp
	g++ -c  Gold.cpp -o Gold.o

Wumpus.o : Wumpus.cpp Wumpus.hpp
	g++ -c  Wumpus.cpp -o Wumpus.o

clean :
	rm -f *.o Main
