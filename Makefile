CC = g++
CFLAGS = `wx-config --cxxflags`
LDFLAGS = `wx-config --libs`

SOURCES = main.cpp ./objects/bmesh.cpp ./objects/vertex.cpp ./objects/edge.cpp ./objects/face.cpp operations.cpp controller.cpp display.cpp camera.cpp ./shaders/flatShader.cpp
EXECUTABLE = Theovision

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -g -o $@ $^ $(LDFLAGS) && ./$(EXECUTABLE)

.PHONY: clean

clean:
	rm -f $(EXECUTABLE)