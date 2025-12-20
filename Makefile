NAME = libftpp.a
TESTNAME = program-test

INCSPATH = inc/
SRCSPATH = src/
OBJSPATH = obj/
TESTPATH = test/

HDRSFILES = \
						libftpp.hpp \
						data_structures.hpp \
						pool.hpp \
						data_buffer.hpp \

SRCSFILES = \
						data_buffer.cpp \

TESTFILES = \
						main_data_buffer.cpp \


#HDRS = $(addprefix $(INCSPATH), $(HDRSFILES))
SRCS = $(addprefix $(SRCSPATH), $(SRCSFILES))
TESTSRCS = $(addprefix $(TESTPATH), $(TESTFILES))

OBJS = $(patsubst $(SRCSPATH)%.cpp, $(OBJSPATH)%.o, $(SRCS))
TESTOBJS = $(patsubst $(TESTPATH)%.cpp, $(OBJSPATH)%.o, $(TESTSRCS))

INC = -I $(INCSPATH)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
LDFLAGS 	= -L. -lftpp
FSANITIZE = -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null
AR = ar rcs
RM = rm -rf

all: $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.cpp
	mkdir -p $(OBJSPATH)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(OBJSPATH)%.o: $(TESTPATH)%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJSPATH)*.o

clean:
	$(RM) $(OBJSPATH)

fclean: clean
	$(RM) $(NAME) $(TESTNAME)

re: fclean all

sanitize: CXXFLAGS += $(FSANITIZE)
sanitize: $(NAME) test

test: $(NAME) $(TESTOBJS)
	$(CXX) $(CXXFLAGS) $(INC) -o $(TESTNAME) $(TESTOBJS) $(LDFLAGS)

.PHONY: all clean fclean re
