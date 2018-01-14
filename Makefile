CC = g++
CFLAGS = -std=c++11 -O3
MAIN = preferone

all: $(MAIN)

$(MAIN): $(MAIN).cpp
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN).cpp

clean:
	rm -f *.o $(MAIN) $(MAIN).exe