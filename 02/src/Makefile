CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = obj

SRCS = main.cpp \
       Wheel.cpp \
       Gear.cpp \
       Transmission.cpp \
       Crankshaft.cpp \
       ExplosionChamber.cpp \
       Injector.cpp \
       Motor.cpp \
       Pedal.cpp \
       Direction.cpp \
       DAE.cpp \
       SteerWheel.cpp \
       Brake.cpp \
       BrakeController.cpp \
       GearLever.cpp \
       Cockpit.cpp \
       Electronics.cpp \
       Car.cpp

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

NAME = car

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
