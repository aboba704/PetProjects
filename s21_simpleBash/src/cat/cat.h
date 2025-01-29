#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Options {
  int b, e, v, n, s, t;
};

void opt_parse(int argc, char** argv, struct Options* opt);
void open_file(char* str, struct Options opt);
void print(FILE* fp, struct Options opt);