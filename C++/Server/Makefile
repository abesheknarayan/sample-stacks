SOURCEDIR := networking/ strings/ test-server/
SOURCES := $(shell find $(SOURCEDIR) -name '*.cpp')

start-server : $(SOURCES)
	g++ -o test $(SOURCES) 