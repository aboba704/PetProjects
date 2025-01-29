CC = gcc
CFLAGS = -Wall -Werror -Wextra  -std=c11

OBJ_DIR = obj
OBJ_TESTS_DIR = $(OBJ_DIR)/obj_tests
EXECTUTABLE = s21_test_string

# Исходные файлы
SRCS_STRING_FUNC = $(wildcard string_func/*.c)
SRCS_SSCANF = $(wildcard sscanf/*.c)
SRCS_SPRINTF = $(wildcard sprintf/*.c)
SRCS_TESTS = $(wildcard tests/*.c)

ALL_SRCS = $(SRCS_SPRINTF) $(SRCS_SSCANF) $(SRCS_STRING_FUNC) $(SRCS_TESTS)

# Объектные файлы
OBJ_SRCS_STRING_FUNC = $(patsubst string_func/%.c, $(OBJ_DIR)/%.o, $(SRCS_STRING_FUNC))
OBJ_SRCS_SSCANF = $(patsubst sscanf/%.c, $(OBJ_DIR)/%.o, $(SRCS_SSCANF))
OBJ_SRCS_SPRINTF = $(patsubst sprintf/%.c, $(OBJ_DIR)/%.o, $(SRCS_SPRINTF))
OBJ_SRCS_TESTS = $(patsubst tests/%.c, $(OBJ_TESTS_DIR)/%.o, $(SRCS_TESTS))

# Все объектные файлы
OBJS = $(OBJ_SRCS_STRING_FUNC) $(OBJ_SRCS_SSCANF) $(OBJ_SRCS_SPRINTF)

OS = $(shell uname)
ifeq ($(OS), Darwin)
	LDFLAGS = -lcheck -lpthread -lm 
else
	LDFLAGS = -lcheck -lsubunit -lrt -lpthread -lm
endif

# Основная цель
all: s21_string.a

# Правило для создания объектных файлов
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: string_func/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: sscanf/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: sprintf/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_TESTS_DIR)/%.o: tests/%.c | $(OBJ_TESTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	#$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -I/opt/homebrew/Cellar/check/0.15.2/include  -c $< -o $@ 

# Создание директорий
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_TESTS_DIR):
	mkdir -p $(OBJ_TESTS_DIR)

rebuild_test: clean test

# Создание статической библиотеки
s21_string.a: $(OBJS)
	/usr/bin/ar rc s21_string.a $^
	ranlib s21_string.a

# Очистка промежуточных файлов
clean:
	rm -rf $(OBJ_DIR) $(REPORT_DIR) *.gcda *.gcno *.info *.a *.h.gch tests/*.gcno report $(EXECTUTABLE)

# Запуск программы
run: all
	./$(EXECTUTABLE)

# Запуск тестов
test: s21_string.a
	$(CC) $(CFLAGS) -o s21_test_string $(SRCS_TESTS) s21_string.a $(LDFLAGS)
	./$(EXECTUTABLE)

test_al: s21_string.a
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -I/opt/homebrew/Cellar/check/0.15.2/include -o s21_test_string $(SRCS_TESTS) s21_string.a -lpthread -lm $(shell pkg-config --libs check)
	./$(EXECTUTABLE)

gcov_report: s21_string.a
	$(CC) $(CFLAGS) --coverage $(ALL_SRCS) s21_string.a -L. $(LDFLAGS) -o $(EXECTUTABLE)
	./$(EXECTUTABLE) || true
	lcov -t "Report" -o coverage.info -c -d . --no-external
	genhtml coverage.info --output-directory report/
	open report/index.html
	rm *.gcda *.gcno

style:
	clang-format -n -style=Google string_func/*.c sprintf/*.c tests/*.c
	clang-format -n -style=Google tests/*.h *.h

set_style:
	clang-format -i -style=Google string_func/*.c sprintf/*.c tests/*.c
	clang-format -i -style=Google tests/*.h *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem string_func/*.c sscanf/*.c sprintf/*.c string_func/*.h sscanf/*.h sprintf/*.h

leaks:	
	valgrind --tool=memcheck --leak-check=full  --leak-check=full --show-leak-kinds=all ./s21_test_string

leaks_mac:
	leaks -atExit -- ./s21_test_string | grep LEAK:

.PHONY: all clean run test testing