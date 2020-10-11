
MKFILE      = Makefile

COMPILECPP  = g++ -g -O0 -Wall -Wextra -rdynamic -std=gnu++17

<<<<<<< HEAD
CPPSOURCE   = bin_tree.cpp BSTtwoSum.cpp
#CPPSOURCE   = bin_tree.cpp 517.cpp
=======
CPPSOURCE   = test.cpp
>>>>>>> caedd976c5c7fad40dcc757a96ab953e9018bd0d
#CPPSOURCE   = 225.cpp linkedList.cpp
#CPPHEADER   = phase10.h   command.h
EXECBIN     = output

${EXECBIN} : ${CPPSOURCE}
	${COMPILECPP} -o $@ ${CPPSOURCE}

clean: 
	-rm ${EXECBIN}
