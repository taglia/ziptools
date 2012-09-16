# C++ compiler
CXX = g++

# The Qt moc program
MOC = /usr/bin/moc

# Locations of Qt include files and libraries; this is the default
# for Debian
QTLIB = /usr/X11R6/lib
QTINC = /usr/include/qt


########################################
# You shouldn't need to modify any more

LDFLAGS  = -L$(QTLIB) -lqt
CPPFLAGS = -I$(QTINC)

objects = $(filter-out %.moc.o,$(patsubst %.cc,%.o,$(wildcard *.cc))) $(patsubst %.h,%.moc.o,$(wildcard *.h))

all: ziptools

ziptools: $(objects)
	$(CXX) -o ziptools $(LDFLAGS) $(objects)

$(patsubst %.h,%.moc.cc,$(wildcard *.h)) : %.moc.cc : %.h
	$(MOC) $< -o $@

clean:
	rm -f ziptools *.o *.moc* *~ core
