.PHONY: all clean
CC=g++
CXXFLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline \
 	 -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
	 -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
	 -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
	 -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing \
	 -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE 
SOURCES= kvadr.cpp vvod.cpp vivod.cpp solver.cpp math_operations.cpp unit_test.cpp unit_test_vvod.cpp unit_test_vivod.cpp \
	 help_output.cpp flag_checker.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=quadratka

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $^ -o $@

%.o : %.cpp consts_for_quad.h
	$(CC) -c $(CXXFLAGS) $< -o $@

clean:
	 rm -f *.o quadratka.exe
