# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 07:49:21 by ffreze            #+#    #+#              #
#    Updated: 2024/03/19 07:49:23 by ffreze           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = phone

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

CC = g++
CFLAGS = -Wall -Wextra -std=c++11

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