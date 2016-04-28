##
## Makefile for Makefile in /home/duhieu_b/CPE/CPE_2015_Lemin
## 
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
## 
## Started on  Fri Apr  8 15:45:04 2016 benjamin duhieu
## Last update Thu Apr 28 00:32:16 2016 marc brout
##

# USEFUL VARIABLES

RM		=	rm -rf

GREEN		=	\033[1;32m

WHITE		=	\033[0m

ECHO		=	echo -e

# COREWAR VARIABLES

GENERATE	=	generation/

PROFON		=	profondeur/solver.c \
			profondeur/resolution.c \
			profondeur/free.c \

LARG		=	largeur/largeur.c \
			largeur/pile_larg.c \
			largeur/free_larg.c \

ASTA		=	astar/astar.c \
			astar/calc_dist.c \
			astar/solver.c \

TOURN		=	tournoi/tournoi.c \
			tournoi/calc_dist.c \
			tournoi/solver.c \

PARSER		=	parser/pars.c \
			parser/link_direction.c \
			parser/move_in_list.c \
			parser/add_cas_list.c \
			parser/free_graph.c \

PROFON		+=	$(PARSER)

LARG		+=	$(PARSER)

ASTA		+=	$(PARSER)

TOURN		+=	$(PARSER)

OBJLAR		=	$(LARG:.c=.o)

OBJPRO		=	$(PROFON:.c=.o)

OBJAST		=	$(ASTA:.c=.o)

OBJTOU		=	$(TOURN:.c=.o)

SRC		=	$(GENERATE)generate.c \
			$(GENERATE)my_bzero.c \
			$(GENERATE)my_getnbr.c \
			$(GENERATE)go.c \
			$(GENERATE)check_corners.c \
			$(GENERATE)imperfect.c \
			$(GENERATE)perfect.c \
			$(GENERATE)init.c \
			$(GENERATE)errors.c \
			$(GENERATE)free.c \
			$(GENERATE)random.c \

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH		=       lib/

LIB		=	lib/libmy.a

SRCLIB		=	$(LIBPATH)my/get_next_line.c \
			$(LIBPATH)my/my_getnbr.c \
			$(LIBPATH)my/my_power_rec.c \
			$(LIBPATH)my/my_printf.c \
			$(LIBPATH)my/my_printfcsspb.c \
			$(LIBPATH)my/my_printfdiouxx.c \
			$(LIBPATH)my/my_printfmetc.c \
			$(LIBPATH)my/my_putchar.c \
			$(LIBPATH)my/my_put_nbr.c \
			$(LIBPATH)my/my_put_error.c \
			$(LIBPATH)my/my_putstr.c \
			$(LIBPATH)my/my_revstr.c \
			$(LIBPATH)my/my_strcmp.c \
			$(LIBPATH)my/my_strdup.c \
			$(LIBPATH)my/my_strlen.c \
			$(LIBPATH)my/my_error.c \
			$(LIBPATH)my/my_strncmp.c \

LDFLAGS		=       -lmy -L$(LIBPATH)

OBJSLIB		=	$(SRCLIB:.c=.o)


# PROJECT VARIABLES

NAME		=	$(GENERATE)generate

PROFONDEUR	=	profondeur/solver

LARGEUR		=	largeur/solver

ASTAR		=	astar/solver

TOURNOI		=	tournoi/solver

IFLAG		=	-Iinclude/

CFLAGS		=	-W -Wall -Wextra

CC		=	gcc -g $(CFLAGS) $(IFLAG)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(TOURNOI) $(ASTAR) $(PROFONDEUR) $(LARGEUR) $(OBJS)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(NAME)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIB)		:	$(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@cp $(LIBPATH)/my/my.h include/
			@cp $(LIBPATH)/my/get_next_line.h include/
			@$(ECHO) "$(GREEN)\n> Compiling Library\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

$(PROFONDEUR)	:	$(OBJPRO)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(PROFONDEUR)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(PROFONDEUR) $(OBJPRO) $(LDFLAGS)

$(LARGEUR)	:	$(OBJLAR)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(LARGEUR)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(LARGEUR) $(OBJLAR) $(LDFLAGS)

$(ASTAR)	:	$(OBJAST)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(ASTAR)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(ASTAR) $(OBJAST) $(LDFLAGS)

$(TOURNOI)	:	$(OBJTOU)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(TOURNOI)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(TOURNOI) $(OBJTOU) $(LDFLAGS)

all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(RM) $(OBJPRO)
			@$(RM) $(OBJLAR)
			@$(RM) $(OBJAST)
			@$(RM) $(OBJTOU)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(PROFONDEUR)
			@$(RM) $(LARGEUR)
			@$(RM) $(ASTAR)
			@$(RM) $(TOURNOI)
			@$(RM) $(LIBPATH)/libmy.a
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
