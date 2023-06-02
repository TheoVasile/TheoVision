CC = g++

CFLAGS = $(shell pkg-config --cflags glfw3 gl)
CFLAGS += -I./dependencies/include
CFLAGS += `wx-config --cxxflags`
CFLAGS += -std=c++11
LDFLAGS = $(shell pkg-config --libs glfw3 gl)
LDFLAGS += -L./dependencies/lib
LDFLAGS += -lGL -framework OpenGL
LDFLAGS += `wx-config --libs`

SRC_DIRS = ./ ./objects ./objects/lights ./objects/meshes ./modifiers ./materials

SOURCES = $(wildcard $(addsuffix /*.cpp,$(SRC_DIRS)))
SOURCES += ./glad.c
EXECUTABLE = Theovision

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) && ./$(EXECUTABLE)

.PHONY: clean

clean:
	rm -f $(EXECUTABLE)