CC=g++
CF=-std=c++17 -I../include/ -pthread
SOURCEDIR=.
BUILDDIR=build

SOURCES := $(shell find $(SOURCEDIR) -name '*.cc')
OBJECTS := $(addprefix $(SOURCEDIR)/,$(SOURCES:%.cc=%))
OUTFILES := $(addprefix $(BUILDDIR)/,$(SOURCES:%.cc=%))

.PHONY: all test clean

all: $(OBJECTS)

test: all
	$(foreach file, $(OUTFILES), $(file);)

%: %.cc
	$(CC) $(CF) $< -o $(BUILDDIR)/$@

clean:
	rm $(BUILDDIR)/*
