CC = g++
CFLAGS = `wx-config --cxxflags`
CFLAGS += -std=c++11
LDFLAGS = `wx-config --libs`

SRC_DIRS = ./ ./objects ./shaders

SOURCES = $(wildcard $(addsuffix /*.cpp,$(SRC_DIRS)))
EXECUTABLE = Theovision

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -g -o $@ $^ $(LDFLAGS) && ./$(EXECUTABLE)

.PHONY: clean

clean:
	rm -f $(EXECUTABLE)