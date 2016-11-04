

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
#include <sys/types.h>
#include "grep.h"

int main(int argc, char *argv[])
{
	
	FILE *fp;

	if(argc<3)
	{
		printf("Please enter correct format for tail information");
		return -1;	
	}

	if(argc == 3)
	{
		filename = argv[2];
		fp = fopen(filename,"r");
		
		if(fp==NULL)
		{
			printf("File not found, check the error %d\n",errno);
      			return -1;
		}
		
		extended = 1;
		compile_pattern(argv[1]);
		match(filename,fp);
	}
	else
	{
		if(strcmp(argv[1],"-i")==0)
		{
			filename = argv[3];
			fp = fopen(filename,"r");
		
			if(fp==NULL)
			{
				printf("File not found, check the error %d\n",errno);
      				return -1;
			}
			
			ignore_case = 1;
			compile_pattern(argv[2]);
			match(filename,fp);

		}
		
		if(strcmp(argv[1],"-E")==0)
		{
			filename = argv[3];
			fp = fopen(filename,"r");
		
			if(fp==NULL)
			{
				printf("File not found, check the error %d\n",errno);
      				return -1;
			}
		
			extended = 1;
			compile_pattern(argv[2]);
			match(argv[2],fp);
		}

		if(strcmp(argv[1],"-L")==0)
		{
			filename = argv[3];
			fp = fopen(filename,"r");
		
			if(fp==NULL)
			{
				printf("File not found, check the error %d\n",errno);
      				return -1;
			}
		
			extended = 1;
			compile_pattern(argv[2]);
			nonmatch(argv[2],fp);
		}
		

	}
	return 0;
}


