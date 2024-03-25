# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 13:11:20 by ffreze            #+#    #+#              #
#    Updated: 2024/03/25 13:11:25 by ffreze           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = Violence


SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

CC = c++
CFLAGS = -Wall -Wextra -std=c++98 -g

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

INCLUDES = $(wildcard $(INCDIR)/*.h)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	rm -rf $(OBJECTS) $(TARGET) $(OBJDIR)

all: $(TARGET)


.DEFAULT_GOAL := all

.PHONY: clean all