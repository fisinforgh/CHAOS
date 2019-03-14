CHAOSAPPDIR = ./
TARGET = Chaos
CXX = g++
CFLAGS = -c `root-config --cflags` -I./include/
LFLAGS = `root-config --glibs`
INCLUDEDIR = $(CHAOSAPPDIR)/include
SOURCEDIR = $(CHAOSAPPDIR)/src

GUIOBJ = WMainCHUA.o WMainPAM.o WMainPE.o WMainSELECT.o

HEADERS = $(INCLUDEDIR)/WMainCHUA.h $(INCLUDEDIR)/WMainPAM.h $(INCLUDEDIR)/WMainPE.h $(INCLUDEDIR)/WMainSELECT.h

all : $(TARGET)

$(TARGET) : $(GUIOBJ) Dict.o Chaos.o
	$(CXX) -o $(TARGET) $^ $(LFLAGS)

Chaos.o : Chaos.cxx
	$(CXX) $(CFLAGS) -c $< -o $@

Dict.cxx : $(HEADERS)
	@rootcint -f Dict.cxx -c $^

Dict.o : Dict.cxx
	$(CXX) $(CFLAGS) -c $< -o $@

%.o : $(SOURCEDIR)/%.cxx $(INCLUDEDIR)/%.h
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY : clean

clean :
	rm -f *.o Dict.cxx Dict.h

install :
	sh INSTALL.sh
