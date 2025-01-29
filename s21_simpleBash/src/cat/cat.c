#include "cat.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "No arguments\n");
    return -1;
  } else {
    struct Options opt = {0};
    opt_parse(argc, argv, &opt);
  }
  return 0;
}

void opt_parse(int argc, char **argv, struct Options *opt) {
  for (int i = 1; i < argc; ++i) {
    if (argv[i][0] == '-') {
      if (strcmp(argv[i], "--number-nonblank") == 0)
        opt->b = 1;
      else if (strcmp(argv[i], "--number") == 0)
        opt->n = 1;
      else if (strcmp(argv[i], "--squeeze-blank") == 0)
        opt->s = 1;
      else {
        int j = 0;
        while (argv[i][j] != 0) {
          switch (argv[i][j]) {
            case 'b':
              opt->b = 1;
              opt->n = 0;
              break;
            case 'e':
              opt->e = 1;
              opt->v = 1;
              break;
            case 'v':
              opt->v = 1;
              break;
            case 'E':
              opt->e = 1;
              break;
            case 'n':
              if (opt->b == 0) opt->n = 1;
              break;
            case 's':
              opt->s = 1;
              break;
            case 't':
              opt->t = 1;
              opt->v = 1;
              break;
            case 'T':
              opt->t = 1;
              break;
            default:
              // fprintf(stderr,
              //         "cat: illegal option -- %c\n"
              //         "usage: cat [-belnstuv] [file ...]\n",
              //         argv[i][j]);
              // exit(1);
              break;
          }
          ++j;
        }
      }
    } else
      open_file(argv[i], *opt);
  }
}

void open_file(char *name, struct Options opt) {
  FILE *fp = fopen(name, "rt");
  if (fp == NULL)
    fprintf(stderr, "cat: %s: No such file or directory\n", name);
  else {
    print(fp, opt);
    fclose(fp);
  }
}

void print(FILE *fp, struct Options opt) {
  int ch;
  int line_number = 1;
  int empty_line_flag = 0;
  int new_line = 1;
  int v_new_line_flag = 0;

  while ((ch = fgetc(fp)) != EOF) {
    if (opt.s) {
      if (ch == '\n') {
        empty_line_flag += 1;
        if (empty_line_flag > 2) continue;
      } else
        empty_line_flag = 0;
    }
    if (opt.n && new_line) {
      printf("%6d\t", line_number++);
      new_line = 0;
    }
    if (opt.b && new_line && ch != '\n') {
      printf("%6d\t", line_number++);
      new_line = 0;
    }
    if (opt.t && ch == '\t') {
      printf("^");
      ch = 'I';
    }
    if (opt.v) {
      if (ch != '\n' && ch != '\t' && ch < 32) {
        printf("^");
        ch += 64;
      } else if (ch == 127) {
        printf("^");
        ch = '?';
      } else if (ch > 127 && ch < 160) {
        printf("M-^");
        ch -= 64;
        if (ch == 'J' && (opt.b || opt.n)) {
          printf("%c%6d\t", ch, line_number++);
          v_new_line_flag = 1;
        }
      }
    }
    if (opt.e && ch == '\n') {
      if (new_line && (opt.b || opt.n))
        printf("      \t$");
      else
        printf("$");
    }
    if (ch == '\n') ++new_line;
    if (!v_new_line_flag) printf("%c", ch);
    v_new_line_flag = 0;
  }
}