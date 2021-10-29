

    UOS=$(shell uname)

    ifeq ($(OS),Windows_NT)
        PLATFORM = windows
    else
		ifeq ($(UOS),Linux)
			PLATFORM = linux
		endif
	endif
  ifeq ($(PLATFORM),windows)
    CC = C:/raylib/mingw/bin/g++.exe
    exename ?= LostEngine.exe
    CFLAGS  = -s  -O3 -static -Os -std=c99 -Wall -Iexternal -DPLATFORM_DESKTOP -lopengl32 -lraylib -lgdi32 -lwinmm
  endif
  ifeq ($(PLATFORM),linux)
    CC = g++
    exename ?= LevelTester
    CFLAGS  = -Wall -std=c99 -Wno-missing-braces -s -O3 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
  endif

  all: $(TARGET)
	  $(CC) LostEngine.cpp -o $(exename) $(CFLAGS)
