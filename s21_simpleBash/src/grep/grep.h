#pragma once

#include <dirent.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8192

struct Options {
  int e, i, v, c, l, n, h, s, f, o;
  int files_count;
  int empty_line;
};

void opt_parse(int argc, char **argv, char *pattern, struct Options *opt);

void open_file(int argc, char **argv, char *pattern, struct Options *opt);
void e_process(int *e_count, char *pattern, struct Options *opt);
void f_process(int *e_count, char *pattern, struct Options *opt);

void print(char **argv, char *pattern, FILE *fp, struct Options opt);
void print_match(char **argv, struct Options opt, size_t line_num, char *str,
                 regmatch_t *pmatch, regex_t regex);
void print_match_occurrences(char **argv, struct Options opt, char *str,
                             regmatch_t *pmatch, regex_t regex);
void print_count(char **argv, struct Options opt, int lines_count);
