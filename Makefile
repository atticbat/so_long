# -*- MakeFile -*-

VPATH	=	bonus mandatory helper
NAME	=	so_long
BNAME	=	so_long_bonus
FUNCTS	=	get_next_line.c get_next_line_utils.c so_long.c \
			initialise_tiles.c load_map.c controls.c utilities.c draw.c \
			storyboard.c initialise_units.c ft_linelen.c
BFUNCTS	=	controls_bonus.c draw_bonus.c ft_linelen.c get_next_line_utils.c \
			get_next_line.c initialise_tiles_bonus.c initialise_units_bonus.c \
			load_map_bonus.c so_long_bonus.c storyboard_bonus.c \
			utilities_bonus.c
LIBFTNAME =	./libft/libft.a
PTFNAME	=	./ft_printf/libftprintf.a
MLXNAME	=	./minilibx/libmlx.a
PTFPATH	=	./ft_printf
OBJS	=	$(addprefix $(OBJ_PATH),$(notdir $(FUNCTS:.c=.o)))
BOBJS	=	$(addprefix $(BOBJ_PATH),$(notdir $(BFUNCTS:.c=.o)))
CC		=	cc
CFLAGS	= 	-Wall -Werror -Wextra
OBJ_PATH =	./obj/
BOBJ_PATH =	./obj_bonus/
MLXPATH	=	./minilibx
LIBFTPATH =	./libft/
LFLAGS	=	-L $(MLXPATH) -lmlx
IFLAGS	=	-I ./includes -I $(LIBFTPATH)
RM 		=	/bin/rm -f
RMR		=	/bin/rm -rf
FRAMEWK	=	-framework OpenGL -framework AppKit
DEPEND	=	-MMD -MP

all: $(NAME)

bonus: $(BNAME)

$(OBJ_PATH) :
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c | $(OBJ_PATH)
	$(CC) $(CLFAGS) $(IFLAGS) $(DEPEND) -c $< -o $@

$(BOBJ_PATH) :
	mkdir $(BOBJ_PATH)

$(BOBJ_PATH)%.o: %.c | $(BOBJ_PATH)
	$(CC) $(CLFAGS) $(IFLAGS) $(DEPEND) -c $< -o $@

$(NAME): $(OBJ_PATH) $(OBJS)
	make -C $(LIBFTPATH)
	make -C $(PTFPATH)
	make -C $(MLXPATH)
	$(CC) -o $(NAME) $(CFLAGS) $(IFLAGS) $(DEPEND) $(FRAMEWK) $(OBJS) \
		$(PTFNAME) $(MLXNAME) $(LIBFTNAME)

$(BNAME): $(BOBJ_PATH) $(BOBJS)
	make -C $(LIBFTPATH)
	make -C $(PTFPATH)
	make -C $(MLXPATH)
	$(CC) -o $(BNAME) $(CFLAGS) $(IFLAGS) $(DEPEND) $(FRAMEWK) $(BOBJS) \
		$(PTFNAME) $(MLXNAME) $(LIBFTNAME)

clean:
	make clean -C $(LIBFTPATH)
	make clean -C $(PTFPATH)
	make clean -C $(MLXPATH)
	$(RMR) $(OBJ_PATH)
	$(RMR) $(BOBJ_PATH)

fclean: clean
	make fclean -C $(LIBFTPATH)
	make fclean -C $(PTFPATH)
	$(RM) $(NAME)
	$(RM) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(OBJ_PATH):%.o=%.d
-include $(BOBJ_PATH):%.o=%.d