CC := gcc
CFLAGS := -O2 -Wall -Wextra
LDFLAGS :=

GLIBS := `pkg-config --cflags --libs glib-2.0 gtk+-3.0 libxklavier appindicator3-0.1`

EXECUTABLE := xki

all: $(EXECUTABLE)

resources.c: ui.gresource.xml *.gresource.xml
	glib-compile-resources --target=resources.c --generate-source --c-name xki ui.gresource.xml

$(EXECUTABLE): main.c resources.c
	$(CC) $(CFLAGS) -o $(EXECUTABLE) resources.c main.c $(LDFLAGS) $(GLIBS)

clean:
	rm -f $(EXECUTABLE) resources.c
