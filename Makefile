CC=c++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp tevent.cpp tbookings.cpp xml.cpp tblock.cpp tdate.cpp tperson.cpp troom.cpp tsubject.cpp tsubjecttype.cpp ttime.cpp tevents.cpp tteacher.cpp tstudent.cpp ttutor.cpp tlecture.cpp tpractice.cpp association.cpp tbooking.cpp tschedule.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=prog

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXEC)

run:
	./$(EXEC)