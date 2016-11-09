TITLE-IMPLEMENT GREP COMMAND

NAME-PAWAR INDUMATI ANNA

MIS-141608009

BRANCH-INFORMATION TECHNOLOGY

BATCH-S4


Discription of grep command-

In which grep commans i have implement basic grep command and the options of grep command.
 Option implement like 
1.-E
2.-L
3.-w
4.-r
5.-v
6.-h
7.-i
                   above mentioned options of grep commmand i have implement in this project

                    Basically grep command using the find global expression and print the match patterns in given files or given standard inputs of user.grep searches the named input files for lines containing a match to the given PATTERN.
syntax of grep command- grep[option]PATTERN[FILE...]

1.-E = --extended-regexp
              Interpret PATTERN as an extended regular  expression  (ERE,  see
              below).
       to run ./project -E hello data1


2.-L = -E, --extended-regexp
              Interpret PATTERN as an extended regular  expression  (ERE,  see
              below).
    to run ./project -L hii data1

3.-w = -w, --word-regexp
              Select  only  those  lines  containing  matches  that form whole
              words.  The test is that the matching substring must  either  be
              at  the  beginning  of  the  line,  or  preceded  by  a non-word
              constituent character.  Similarly, it must be either at the  end
              of  the  line  or  followed by a non-word constituent character.
              Word-constituent  characters  are  letters,  digits,   and   the
              underscore.
   to run ./project -w how data1

4.-r = -r, --recursive
              Read all files  under  each  directory,  recursively,  following
              symbolic  links only if they are on the command line.  Note that
              if  no  file  operand  is  given,  grep  searches  the   working
              directory.  This is equivalent to the -d recurse option.

  to run ./project -r hello data1

5.-v = -v, --invert-match
              Invert the sense of matching, to select non-matching lines.

           to run ./project -v hi data1

6.-h =   -h, --no-filename
              Suppress  the  prefixing  of  file names on output.  This is the
              default when there is only one file (or only standard input)  to
              search.
   to run ./project -h hello data1

7.-i =  -i, --ignore-case
              Ignore case distinctions in  both  the  PATTERN  and  the  input
              files.

  to run ./project -i HeLlo data1




above listed option am implementing in grep command












