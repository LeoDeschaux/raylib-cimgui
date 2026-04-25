CC = gcc
# CFLAGS = -c -g -O2 -I D:/Programming/C/cimgui -I C:/raylib/raylib/src
CFLAGS = -c -g -O2 -I D:/Programming/C/cimgui -I C:/raylib/raylib/src
AR = ar
ARFLAGS = rcs

# Target library name
LIBRARY = rlcimgui.lib

# Object files
OBJ = imgui_impl_raylib.o rlcimgui.o

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
	$(AR) $(ARFLAGS) librlcimgui.a $^
	ren librlcimgui.a $(LIBRARY)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	del $(OBJ) $(LIBRARY) librlcimgui.a
