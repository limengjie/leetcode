
MKFILE      = Makefile

COMPILECPP  = g++ -g -O0 -Wall -Wextra -rdynamic -std=gnu++11

CPPSOURCE   = 2119.cpp
#CPPHEADER   = phase10.h   command.h
EXECBIN     = output

${EXECBIN} : ${CPPSOURCE}
	${COMPILECPP} -o $@ ${CPPSOURCE}

clean: 
	-rm ${EXECBIN}
