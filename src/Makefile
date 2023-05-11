UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	LCOV= lcov
	GENHTML= genhtml 
	LFLAG= -lm -lrt -lpthread -lsubunit
endif
ifeq ($(UNAME), Darwin)
	PATH := $(PATH):${HOME}/homebrew/bin
	LCOV= $(shell PATH=$(PATH) which lcov)
	GENHTML= $(shell PATH=$(PATH) which genhtml) 
	LFLAG=
endif
CC=gcc
CFLAGS=  -Wall -Wextra -Werror -std=c11 -pedantic
#DEBUG= -D DEBUG -g
SOURCE:=$(shell find . -maxdepth 2 -name "s21_*.c")
ALL_SOURCE:= $(shell find . -maxdepth 2 -name "*.c" -o -name "*.h")
OBJECTS:=$(SOURCE:.c=.o)
RESULT= s21_matrix.a
DIR = s21_matrix

all: $(RESULT) test gcov_report

clean:
	rm -rf $(OBJECTS) $(RESULT) test report *.gc* *.out *.gch log.txt gcov* cov main

$(OBJECTS): %.o: %.c
	$(CC) $(DEBUG) $(CFLAGS) -c $< -o $@ 

$(RESULT): $(OBJECTS)
	ar rc $@ $^
	ranlib $@
	rm -rf *.o *.gch

test: $(RESULT)
	$(CC) $(DEBUG) $(CFLAGS) tests/*.c -o $@ $^ -lcheck $(LFLAG)
	./$@

gcov_report: clean
	mkdir -p cov
	$(CC) $(DEBUG) $(SOURCE) tests/*.c -lcheck -o $@ --coverage $(LFLAG)
	./$@
	rm -rf *test*.gc*
	gcov -d . s21_*.c 
	$(LCOV) -d . -o cov/$@.info -c
	$(GENHTML) -o cov/report cov/$@.info
	open cov/report/index.html
	mv *.gc* cov

style:
	clang-format -n $(ALL_SOURCE)

leak: test
	leaks -atExit -- ./test

valgrind: test
	valgrind --undef-value-errors=yes --log-fd=1 --leak-check=full --log-file=log.txt -s ./test

main: $(RESULT)
	$(CC) $(DEBUG) main.c $(RESULT) -o $@
	./$@