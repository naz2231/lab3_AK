.PHONY: build

build:
	g++ ./Lab3_zoo.cpp -o lab3

default_goal: build def 
.PHONY: def
def:
	./lab3 -l -h -v -f -e -V12

.PHONY: run

run:
	./lab3 -l


.DEFAULT_GOAL:=default_goal