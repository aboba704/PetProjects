#include "grep.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr,
            "usage: grep [-abcdDEFGHhIiJLlMmnOopqRSsUVvwXxZz] [-A num] [-B "
            "num] [-C[num]]\n"
            "\t[-e pattern] [-f file] [--binary-files=value] [--color=when]\n"
            "\t[--context[=num]] [--directories=action] [--label] "
            "[--line-buffered]\n"
            "\t[--null] [pattern] [file ...]\n");
    return -1;
  } else {
    struct Options opt = {0};
    char pattern[BUFSIZE] = {0};
    opt_parse(argc, argv, pattern, &opt);
    open_file(argc, argv, pattern, &opt);
  }

  return 0;
}

void opt_parse(int argc, char **argv, char *pattern, struct Options *opt) {
  int option, e_count = 0;

  while ((option = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    switch (option) {
      case 'e':
        opt->e = 1;
        e_process(&e_count, pattern, opt);
        break;
      case 'i':
        opt->i = 1;
        break;
      case 'v':
        opt->v = 1;
        break;
      case 'c':
        opt->c = 1;
        break;
      case 'l':
        opt->l = 1;
        break;
      case 'n':
        opt->n = 1;
        break;
      case 'h':
        opt->h = 1;
        break;
      case 's':
        opt->s = 1;
        break;
      case 'f':
        opt->f = 1;
        f_process(&e_count, pattern, opt);
        break;
      case 'o':
        opt->o = 1;
        break;
      default:
        fprintf(
            stderr,
            "usage: grep [-abcdDEFGHhIiJLlMmnOopqRSsUVvwXxZz] [-A num] [-B "
            "num] [-C[num]]\n"
            "\t[-e pattern] [-f file] [--binary-files=value] [--color=when]\n"
            "\t[--context[=num]] [--directories=action] [--label] "
            "[--line-buffered]\n"
            "\t[--null] [pattern] [file ...]\n");
        exit(1);
        break;
    }
  }
  if (!opt->e && !opt->f) {
    if (!*argv[optind]) argv[optind] = ".";
    strcat(pattern, argv[optind++]);
  }
}

void open_file(int argc, char **argv, char *pattern, struct Options *opt) {
  opt->files_count = argc - optind;

  for (; optind < argc; optind++) {
    FILE *fp = fopen(argv[optind], "rt");
    if (fp != NULL) {
      print(argv, pattern, fp, *opt);
      fclose(fp);
    } else if (!opt->c && !opt->s)
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[optind]);
  }
}

void e_process(int *e_count, char *pattern, struct Options *opt) {
  if (*e_count) strcat(pattern, "|");
  if (!*optarg) {
    optarg = ".";
    opt->empty_line += 1;
  }
  strcat(pattern, optarg);
  *e_count += 1;
}

void f_process(int *e_count, char *pattern, struct Options *opt) {
  FILE *fp = NULL;
  char line[BUFSIZE] = {0};

  if ((fp = fopen(optarg, "rt"))) {
    fseek(fp, 0, SEEK_SET);
    while (fgets(line, BUFSIZE, fp) != NULL) {
      if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = 0;
      if (*e_count > 0) strcat(pattern, "|");
      if (*line == '\0') {
        opt->empty_line = 1;
        strcat(pattern, ".");
      } else
        strcat(pattern, line);
      *e_count += 1;
    }
    fclose(fp);
  } else {
    fprintf(stderr, "grep: %s: No such file or directory\n", optarg);
    exit(1);
  }
}

void print(char **argv, char *pattern, FILE *fp, struct Options opt) {
  regex_t regex;  // структура для регулярного выржаения
  int regflag = REG_EXTENDED;
  char str[BUFSIZE];
  size_t line_num = 1;
  int lines_count = 0;
  regmatch_t pmatch[1] = {0};
  size_t nmatch = 1;

  // игнорировать регистр при поиске
  if (opt.i) regflag |= REG_ICASE;

  regcomp(&regex, pattern, regflag);  // готовит бинарник регулярного выражения

  while (fgets(str, BUFSIZE, fp)) {
    int success = regexec(&regex, str, nmatch, pmatch, 0);
    if (opt.v) success = success ? 0 : 1;
    if (success != REG_NOMATCH) {
      if (!opt.c && !opt.l)
        print_match(argv, opt, line_num, str, pmatch, regex);
      ++lines_count;
    }
    ++line_num;
  }

  print_count(argv, opt, lines_count);
  regfree(&regex);
}

// выводит строки, соответствующие шаблону
void print_match(char **argv, struct Options opt, size_t line_num, char *str,
                 regmatch_t *pmatch, regex_t regex) {
  if (opt.files_count > 1 && !opt.h && !opt.o) printf("%s:", argv[optind]);
  if (opt.n) printf("%lu:", line_num);
  if (opt.o && !opt.v)
    print_match_occurrences(argv, opt, str, pmatch, regex);
  else {
    printf("%s", str);
    if (str[strlen(str) - 1] != '\n') printf("\n");
  }
}

// выводит только совпадения в строках
void print_match_occurrences(char **argv, struct Options opt, char *str,
                             regmatch_t *pmatch, regex_t regex) {
  char *ptr = str;
  int success;
  while (1) {
    if (!opt.h && opt.files_count > 1) printf("%s:", argv[optind]);
    if (pmatch[0].rm_eo == pmatch[0].rm_so) break;
    printf("%.*s\n", (int)(pmatch[0].rm_eo - pmatch[0].rm_so),
           ptr + pmatch[0].rm_so);
    ptr += pmatch[0].rm_eo;
    success = regexec(&regex, ptr, 1, pmatch, REG_NOTBOL);
    if (success == REG_NOMATCH) break;
  }
}

// выводит количество найденных строк
void print_count(char **argv, struct Options opt, int lines_count) {
  if (opt.c) {
    if (opt.files_count > 1 && !opt.h) printf("%s:", argv[optind]);
    if (opt.l && lines_count)
      printf("1\n");
    else
      printf("%d\n", lines_count);
  }

  if (opt.l && lines_count) printf("%s\n", argv[optind]);
}
