CC = g++
CFLAGS = `wx-config --cxxflags`
LDFLAGS = `wx-config --libs`

SOURCES = main.cpp display.cpp
EXECUTABLE = Theovision

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(EXECUTABLE)