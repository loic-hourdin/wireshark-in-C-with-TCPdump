# project name (generate executable with this name)
TARGET   = analyse

CC       = gcc
# compiling flags here
CFLAGS   =-Wall

LINKER   = gcc -o
# linking flags here
LFLAGS   = 
LDFLAGS  = -lm -g -lpcap #Linker

# change these to set the proper directories where each files shoould be
SRCDIR   = src
OBJDIR   = build


SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS) ${LDFLAGS}
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ ${LDFLAGS}
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(TARGET)
	@echo "Executable removed!"
