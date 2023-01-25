CC=gcc
CFLAGS=-c -Wextra -Werror -Wall -std=c11 -g
CFLAGS_COVERAGE=-fprofile-arcs -ftest-coverage
LFLAGS_COVERAGE=-lgcov --coverage
CHECK_LIBS=-lcheck
SRCS=s21_*.c
OBJS=s21_*.o
OS := $(shell uname -s)
ifeq ($(OS), Linux)
    CHECK_LIBS += -lm -lsubunit -lpthread -lrt
endif

all: s21_string.a

build: clean test gcov_report

s21_string:
	$(CC) $(CFLAGS) $(SRCS)

s21_string.a: s21_string
	ar rcs s21_string.a *.o
	ranlib s21_string.a

test: s21_string
	$(CC) $(CFLAGS) tests.c
	$(CC) $(OBJS) tests.o -o tests.out $(CHECK_LIBS)


gcov_report: $(SRCS) tests.c
	$(CC) $(LFLAGS_COVERAGE) $(SRCS) tests.c -o tests_cov.out $(CHECK_LIBS)
	./tests_cov.out
	lcov --no-external --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
ifeq ($(OS), Linux)
	xdg-open out/index.html
else
	open -a "Google Chrome" out/index.html
endif


leak:
ifeq ($(OS), Linux)
	valgrind --leak-check=full --leak-resolution=med ./tests.out
else
	leaks --atExit -- ./tests.out
endif

clean:
	rm -rf *.o *.a *.gcno *.gcda *.gcov *.out *.info out
