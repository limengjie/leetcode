
MKFILE      = Makefile

COMPILECPP  = g++ -g -O0 -Wall -Wextra -rdynamic -std=gnu++11

CPPSOURCE   = 91_92.cpp
#CPPSOURCE   = 225.cpp linkedList.cpp
#CPPHEADER   = phase10.h   command.h
EXECBIN     = output

${EXECBIN} : ${CPPSOURCE}
	${COMPILECPP} -o $@ ${CPPSOURCE}

clean: 
	-rm ${EXECBIN}
