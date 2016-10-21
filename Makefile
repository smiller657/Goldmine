run: dynamicList.o Box.o GoldMine.o playGame.o 
	g++ dynamicList.o Box.o GoldMine.o playGame.o -o run
playGame.o: playGame.cpp
	g++ -c playGame.cpp
GoldMine.o: GoldMine.h GoldMine.cpp
	g++ -c GoldMine.cpp
Box.o: Box.h Box.cpp
	g++ -c Box.cpp
dynamicList.o: dynamicList.h dynamicList.cpp 
	g++ -c dynamicList.cpp
clean:
	rm -rf *.o 
