NAME = libftpp.a

INCSPATH = inc/
SRCSPATH = src/
OBJSPATH = obj/

HDRSFILES = \
						libftpp.hpp \
						data_structures.hpp \
						pool.hpp \
						data_buffer.hpp \

SRCSFILES = \
						data_buffer.cpp \

HDRS = $(addprefix $(INCSPATH), $(HDRSFILES))
SRCS = $(addprefix $(SRCSPATH), $(SRCSFILES))
OBJS = $(patsubst $(SRCSPATH)%.cpp, $(OBJSPATH)%.o, $(SRCS))

INC = -I $(INCSPATH)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
AR = ar rcs
RM = rm -rf

all: $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.cpp
	mkdir -p $(OBJSPATH)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJSPATH)*.o

clean:
	$(RM) $(OBJSPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
