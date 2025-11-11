NAME    =  libft.a
CC      =  cc
AR      =  ar -rcs
FLAGS   =  -Wall -Wextra -g3 -fPIE
HEADER  =  libft.h

OBJS_DIR = objs/

SOURCES = \
    ft_arg_error.c \
    ft_atoi.c     \
    ft_bzero.c    \
    ft_calloc.c       \
    ft_isalnum.c   \
    ft_isalpha.c   \
    ft_isascii.c   \
    ft_isdigit.c   \
    ft_isprint.c   \
    ft_memchr.c       \
    ft_memcmp.c       \
    ft_memcpy.c       \
    ft_memmove.c   \
    ft_memset.c       \
    ft_strchr.c       \
    ft_strdup.c       \
    ft_strlcat.c   \
    ft_strlcpy.c   \
    ft_strlen.c       \
    ft_strncmp.c   \
    ft_strnstr.c   \
    ft_strrchr.c   \
    ft_tolower.c   \
    ft_toupper.c   \
    ft_substr.c       \
    ft_strjoin.c   \
    ft_strtrim.c   \
    ft_split.c    \
    ft_itoa.c     \
    ft_strmapi.c   \
    ft_striteri.c  \
    ft_putchar_fd.c    \
    ft_putstr_fd.c \
    ft_putendl_fd.c    \
    ft_putnbr_fd.c \
    ft_putnbr_base.c\
    ft_printf.c \
    get_next_line.c \
    get_next_line_utils.c \
    ft_lstnew_bonus.c     \
    ft_lstadd_front_bonus.c    \
    ft_lstsize_bonus.c    \
    ft_lstlast_bonus.c    \
    ft_lstadd_back_bonus.c \
    ft_lstdelone_bonus.c   \
    ft_lstclear_bonus.c       \
    ft_lstiter_bonus.c    \
    ft_lstmap_bonus.c

OBJS    =  $(addprefix $(OBJS_DIR), ${SOURCES:.c=.o})

all :  $(OBJS_DIR) ${NAME}

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o :  %.c ${HEADER} | $(OBJS_DIR)
	${CC} ${FLAGS} -c $< -o $@

${NAME} :  ${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

clean   :
	@rm -rf ${OBJS_DIR}

fclean  :  clean
	@rm -f ${NAME}

re  :  fclean all

.PHONY  :  all clean fclean re
