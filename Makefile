CC = g++
CFLAGS = `wx-config --cxxflags`
LDFLAGS = `wx-config --libs`

SOURCES = main.cpp display.cpp object.cpp operations.cpp controller.cpp
EXECUTABLE = Theovision

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) && ./$(EXECUTABLE)

.PHONY: clean

clean:
	rm -f $(EXECUTABLE)