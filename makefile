PROJECT = lum_p2
CFLAGS = -Wall -Werror -g -std=c++14

.PHONY: all run clean memcheck

all: $(PROJECT)

$(PROJECT): $(PROJECT).cpp 
		g++ $(CFLAGS) $(PROJECT).cpp -o $(PROJECT) 

run: $(PROJECT) all
		./$(PROJECT)

clean:
		rm -vf *.o $(PROJECT)

memcheck: all
		valgrind ./$(PROJECT)
