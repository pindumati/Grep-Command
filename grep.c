


/*****************************************************************************
 * Copyright (C) PAWAR I.A. indumatipawar157@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//#include <regex.h>
#include <unistd.h>
//#include <sys/types.h>
#include "grep.h"


void match(const char *name, FILE *fp)
{
	char *buf = NULL;
	size_t size = 0;
	char error[MSGBUFSIZE];
	int ret;

	while (getline(& buf, &size, fp) != -1) 
	{
		ret = regexec(& pattern, buf, 0, NULL, 0);
		if (ret != 0) 
		{
			if (ret != REG_NOMATCH) 
			{
				(void) regerror(ret, & pattern, error, sizeof error);
				printf("file %s: %s\n", filename, error);
				free(buf);
				errors++;
				return;
			}
		} 
		else
			printf("%s", buf);
			//printf("%s: %s", filename, buf);	/* print matching lines */
	}
	free(buf);
}


void nonmatch(const char *name, FILE *fp)
{
	char *buf = NULL;
	size_t size = 0;
	char error[MSGBUFSIZE];
	int ret;

	while (getline(& buf, &size, fp) != -1) 
	{
		
		if((ret = regexec(& pattern, buf, 0, NULL, 0))!=0) 
		{
			printf("%s", buf);	/* print non matching lines */
		}
		else
		{
	/*		if (ret != 0)
			{
				(void) regerror(ret, & pattern, error, sizeof error);
				printf("%s: %s\n", filename, error);
				free(buf);
				errors++;
				return;
			}
	*/
		}			

			
	}
	free(buf);
}

void compile_pattern(const char *pat)
{
	int flags = REG_NOSUB;	/* don't need where-matched info */
	int ret;

	char error[MSGBUFSIZE];

	if (ignore_case)
		flags |= REG_ICASE;
	if (extended)
		flags |= REG_EXTENDED;

	ret = regcomp(& pattern, pat, flags);
	if (ret != 0)
	{
		(void) regerror(ret, & pattern, error, sizeof error);
		printf("pattern `%s': %s\n", pat, error);
		errors++;
	}
}

