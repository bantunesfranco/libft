RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
END=\033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h

DIR_S = srcs
DIR_O = obj
DIR_I = incs

SRCS = bonus/ft_lstnew.c bonus/ft_lstadd_front.c bonus/ft_lstsize.c bonus/ft_lstlast.c\
		bonus/ft_lstadd_back.c bonus/ft_lstdelone.c bonus/ft_lstclear.c bonus/ft_lstiter.c bonus/ft_lstmap.c\
		lists/ft_dlstnew.c lists/ft_dlstadd_front.c lists/ft_dlstsize.c lists/ft_dlstlast.c lists/ft_dlstfirst.c\
		lists/ft_dlstadd_back.c lists/ft_dlstdelone.c lists/ft_dlstclear.c lists/ft_dlstiter.c lists/ft_dlstmap.c\
		conversions/ft_atoi.c conversions/ft_itoa.c conversions/ft_itoa_ptr.c\
		conversions/ft_itoa_hex.c conversions/ft_itoa_uint.c conversions/ft_atol.c\
		checks/ft_isalnum.c checks/ft_isalpha.c checks/ft_isascii.c checks/ft_isnumber.c\
		checks/ft_isprint.c checks/ft_isdigit.c checks/ft_isspace.c\
		str/ft_tolower.c str/ft_toupper.c str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c str/ft_arrlen.c\
		str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strlen.c str/ft_strmapi.c str/ft_strjoin_free.c\
		str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c str/ft_strtrim.c str/ft_substr.c str/ft_split.c\
		mem/ft_memchr.c mem/ft_memcmp.c mem/ft_memcpy.c mem/ft_memmove.c\
		mem/ft_memset.c mem/ft_bzero.c mem/ft_calloc.c mem/ft_free_arr.c\
		int/ft_intlen.c int/ft_uintlen.c int/ft_hexlen.c\
		io/ft_putchar_fd.c io/ft_putendl_fd.c io/ft_putnbr_fd.c io/ft_putstr_fd.c\
		io/get_next_line.c io/get_next_line_bonus.c io/ft_printf.c io/ft_error.c\
		utils/printf_utils.c\

OBJS =  ${SRCS:%.c=${DIR_O}/%.o}

${NAME}: ${OBJS} 
	@echo "${MAGENTA}Creating $@${END}"
	@ar rcs ${NAME} ${OBJS}
	@echo "${GREEN}Done!${END}"

${OBJS}: ${DIR_O}/%.o: ${DIR_S}/%.c
	@mkdir -p ${@D}
	@echo "${BLUE}Compiling $<${END}"
	@${CC} ${CFLAGS} -I ${DIR_I} -c $< -o $@

all: ${NAME}

clean: 
	@echo "${RED}Removing objs${END}"
	@rm -rf obj

fclean: clean
	@echo "${RED}Removing ${NAME}${END}"
	@rm -rf ${NAME}

re: fclean all

git:
	git commit -m "auto commit"
	git push

.PHONY: all clean fclean re bonus test git
