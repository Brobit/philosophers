NAME = philo

CC = cc

COMPILATION_FLAG = -Wall -Wextra -Werror -g #-fsanitize=thread

LIB = -lpthread

INCLUDES = -I ./Include/

SOURCES = ./Sources/philosophers.c\
		  ./Sources/ft_atoll.c\
		  ./Sources/writing.c\
		  ./Sources/arg_checker.c\
		  ./Sources/initializer.c\
		  ./Sources/free_structure.c\
		  ./Sources/simulation_entry.c\
		  ./Sources/time.c\
		  ./Sources/routine.c\
		  ./Sources/simulation_checking.c\
		  ./Sources/routine_actions.c\
		  ./Sources/one_philo_case.c\
		  ./Sources/display_message.c

OBJS = ${SOURCES:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${COMPILATION_FLAG} ${OBJS} -o $@ ${LIB}

%.o : %.c
	${CC} ${COMPILATION_FLAG} ${INCLUDES} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
