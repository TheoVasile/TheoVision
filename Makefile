CC = g++
CFLAGS = `wx-config --cxxflags`
LDFLAGS = `wx-config --libs`

SOURCES = main.cpp vector.cpp ./objects/bmesh.cpp ./objects/vertex.cpp ./objects/edge.cpp ./objects/face.cpp utils.cpp controller.cpp display.cpp camera.cpp ./shaders/shaderUtils.cpp ./shaders/ray.cpp ./shaders/flatShader.cpp ./shaders/phongShader.cpp
EXECUTABLE = Theovision

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -g -o $@ $^ $(LDFLAGS) && ./$(EXECUTABLE)

.PHONY: clean

clean:
	rm -f $(EXECUTABLE)