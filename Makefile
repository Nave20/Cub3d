SRC_DIR         = src/
OBJ_DIR         = objs/
INC_DIR         = header/

PARS_DIR        = $(SRC_DIR)pars/
PARS_OBJDIR     = $(OBJ_DIR)pars/

MOV_DIR        = $(SRC_DIR)mov/
MOV_OBJDIR     = $(OBJ_DIR)mov/

RAY_DIR        = $(SRC_DIR)ray/
RAY_OBJDIR     = $(OBJ_DIR)ray/

LIB             = $(SRC_DIR)/libft/libft.a

PARS_FILES      =	get_texture.c	\
					get_color.c		\
					parsing_servo.c	\
					pars_utils.c	\
					error_messages.c\
					pars_free.c		\
					validation.c	\
					map_parsing.c 	\
					error.c 		\
					print_utils.c 	\

MOV_FILES		=

RAY_FILES		=

SRC_FILES       =	main.c	\

SOURCES         = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
                  $(addprefix $(PARS_DIR), $(PARS_FILES)) \
                  $(addprefix $(MOV_DIR), $(MOV_FILES)) \
                  $(addprefix $(RAY_DIR), $(RAY_FILES)) \

OBJS            = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o)) \
                  $(addprefix $(PARS_OBJDIR), $(PARS_FILES:.c=.o)) \
                  $(addprefix $(MOV_OBJDIR), $(MOV_FILES:.c=.o)) \
                  $(addprefix $(RAY_OBJDIR), $(RAY_FILES:.c=.o)) \

HEADER          = $(INC_DIR)cub3D.h
NAME            = cub3D

CC              = cc
FLAGS           = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(OBJ_DIR) $(PARS_OBJDIR) $(MOV_OBJDIR) $(RAY_OBJDIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PARS_OBJDIR):
	mkdir -p $(PARS_OBJDIR)

$(MOV_OBJDIR):
	mkdir -p $(MOV_OBJDIR)

$(RAY_OBJDIR):
	mkdir -p $(RAY_OBJDIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(PARS_OBJDIR)%.o: $(PARS_DIR)%.c $(HEADER)
	mkdir -p $(PARS_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(MOV_OBJDIR)%.o: $(MOV_DIR)%.c $(HEADER)
	mkdir -p $(MOV_OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(RAY_OBJDIR)%.o: $(RAY_DIR)%.c $(HEADER)
	mkdir -p $(RAY_OBJDIR)
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
