# Compiler settings
ifeq ($(OS),Windows_NT)
CC = g++
CXXFLAGS = -g -Werror
LDFLAGS = 
else
CC = g++
CXXFLAGS = -g -Werror -fsanitize=address -O1 -fno-omit-frame-pointer
LDFLAGS = 
endif

# Makefile settings
APPNAME = nosferatu
EXT = .cpp
BASEDIR = 
SRCDIR = src
LIBDIR = lib
OBJDIR = obj

SRC = $(wildcard $(BASEDIR)/*$(EXT))
OBJ = $(SRC:$(BASEDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(BASEDIR)/%$(EXT)=$(OBJDIR)\\%.o)

all: $(APPNAME)

# Builds the app for windows OS and linux.
ifeq ($(OS),Windows_NT)
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LIBDIR)/excepciones/*.cpp $(LIBDIR)/interfaz/*.cpp $(LIBDIR)/objetos/*.cpp  $(LIBDIR)/personajes/*.cpp $(LIBDIR)/utilidades/*.cpp $(SRCDIR)/*.cpp
	
#*.dll
else
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)  $(LIBDIR)/excepciones/*.cpp $(LIBDIR)/estructuras/grafo/*.cpp $(LIBDIR)/interfaz/*.cpp $(LIBDIR)/objetos/*.cpp  $(LIBDIR)/personajes/*.cpp $(LIBDIR)/utilidades/*.cpp $(SRCDIR)/*.cpp

#-L/usr/include/SFML/ -lsfml-graphics -lsfml-window -lsfml-system
endif

# Creates the dependecy rules
%.d: $(BASEDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(BASEDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)

