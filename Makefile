SRC_DIR         = src/
OBJ_DIR         = objs/
INC_DIR         = header/

PARS_DIR        = $(SRC_DIR)pars/
PARS_OBJDIR     = $(OBJ_DIR)pars/

LIB             = $(SRC_DIR)/libft/libft.a

PARS_FILES      =	map_parsing.c \
					error.c \
					print_utils.c \
					get_texture.c \

SRC_FILES       =	main.c	\

SOURCES         = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
                  $(addprefix $(PARS_DIR), $(PARS_FILES)) \

OBJS            = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o)) \
                  $(addprefix $(PARS_OBJDIR), $(PARS_FILES:.c=.o)) \

HEADER          = $(INC_DIR)cub3D.h
NAME            = cub3D

CC              = cc
FLAGS           = -Wall -Wextra -Werror -g3 -I$(INC_DIR)

all: $(OBJ_DIR) $(PARS_OBJDIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PARS_OBJDIR):
	mkdir -p $(PARS_OBJDIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(PARS_OBJDIR)%.o: $(PARS_DIR)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB) $(HEADER) Makefile
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB)

$(LIB): FORCE
	make -C $(SRC_DIR)libft

FORCE:

clean:
	make clean -C $(SRC_DIR)libft/
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(SRC_DIR)libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re FORCE

