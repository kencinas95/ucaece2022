cc := g++
flags := -Wall
target := ./target
sources := $(wildcard *.cpp)
exes := $(patsubst %.cpp, %, $(sources))

all: clean $(exes)

$(target):
	@mkdir -p $@

%: %.cpp $(target)
	-$(cc) $(flags) -o $(target)/$@ $<

clean:
	@rm -rf $(target)
