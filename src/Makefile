#определяем переменные для системы
OS := $(shell uname)
CFLAGS = -std=c11 -g -Wall -Werror -Wextra
INC = -lm -I ./ 
CC = gcc

# Путь к исходным файлам
SRC_DIR = functions
OBJ_DIR = objects
# Получение имен подкаталогов в директории SRC_DIR
SUBDIRS := $(shell find $(SRC_DIR) -type d)

# Получение списка исходных файлов
SRCS := $(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.c))

# Преобразование имен исходных файлов в имена объектных файлов
OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

# Имя статической библиотеки
LIB = s21_string.a

ifeq ($(OS),Linux) # определяем ОС
	TEST_LIBS = -lcheck -lsubunit -lpthread -lm -lrt -D_GNU_SOURCE
	GCC_COMPILE_BUILD = $(CC) $(CFLAGS) 
	ADD_LIB = -L. -l:$(LIB) $(INC)
	GCC_COMPILE_TEST = $(CC) $(CFLAGS) -c -I ./ -L. -l:$(LIB) $(TEST_LIBS) ./tests/*.c 
else
	TEST_LIBS = -lcheck
	GCC_COMPILE_BUILD = $(CC) $(CFLAGS) 
	ADD_LIB = $(LIB) $(INC)
	GCC_COMPILE_TEST = $(CC) $(CFLAGS) -c $(LIB) $(TEST_LIBS) ./tests/*.c 
endif

GCC_COMPILE_GCOV = $(CC) $(CFLAGS) -c --coverage -I ./ $(TEST_LIBS)


all: clean test

# Компиляция исходных файлов в объектные файлы
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


# Создание статической библиотеки
$(LIB): $(OBJS)
	ar rcs $@ $^

gcov_report: clean
	$(GCC_COMPILE_GCOV) $(SRCS) ./tests/*.c
	mv ./*.o ./$(OBJ_DIR)/
	ar rc s21_string.a ./objects/*.o 
	ranlib s21_string.a
ifeq ($(OS),Linux)
	$(CC) --coverage s21_test.c -I ./ -L. -l:s21_string.a $(TEST_LIBS) s21_string.h -o s21_test
else
	$(CC) --coverage s21_test.c s21_string.a $(TEST_LIBS) s21_string.h -o s21_test
endif 
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	mkdir -p gcov_objects
	mv *.gcda gcov_objects
	mv *.gcno gcov_objects
	open ./report/index.html

clean:
	rm -rf ./objects/tests/*.o
	rm -rf $(OBJ_DIR)/functions
	rm -rf *.a $(OBJ_DIR)/*.o ./s21_test
	rm -fr *.gcno *.gcda s21_test.info ./report
	rm -f valgrind_report.txt
	rm -fr ./gcov_objects/*

format:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c *.h functions/*.c tests/*.c
	rm .clang-format

valgrind_test: clean $(LIB) compile_test
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./s21_test 2> valgrind_report.txt

test: clean $(LIB) compile_test run_test


run_test:
	./s21_test

compile_test:
	$(GCC_COMPILE_TEST)
	mkdir -p objects/tests
	mv *.o objects/tests
ifeq ($(OS),Linux)
	$(CC) $(CFLAGS) ./objects/tests/*.o s21_test.c -I ./ -L. -l:s21_string.a $(TEST_LIBS) -o s21_test
else
	$(CC) $(CFLAGS) ./objects/tests/*.o s21_test.c s21_string.a $(TEST_LIBS) -o s21_test
endif

.PHONY: clean