CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = cc3k
OBJECTS = barrier.o main.o floor.o textdisplay.o game.o enemy.o posn.o thing.o character.o item.o potion.o gold.o cell.o chamber.o compass.o player.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
