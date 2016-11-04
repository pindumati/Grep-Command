#ifndef __GREP_H
#define __GREP_H
#include <regex.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include<stdio.h>
#include<stdlib.h>
#define MSGBUFSIZE	512	/* arbitrary */

int ignore_case;		/* -i option: ignore case */
int extended ;		/* -E option: use extended RE's */
int non_matches;		/* -L option: non-match of RE's */
int errors;			/* number of errors */

regex_t pattern;		/* pattern to match */


void compile_pattern(const char *pat);
void match(const char *name, FILE *fp);
void nonmatch(const char *name, FILE *fp);
static char *filename;



#endif
