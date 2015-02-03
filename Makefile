CC := gcc
CFLAGS := -O2 -Wall -Wextra
LDFLAGS :=

PKGCONFIGLIBS := `pkg-config --cflags --libs glib-2.0 gtk+-3.0 libxklavier appindicator3-0.1`

EXECUTABLE := xki

all: $(EXECUTABLE)

resources.c: xki.gresource.xml *.ui
	glib-compile-resources --target=resources.c --generate-source --c-name xki xki.gresource.xml

$(EXECUTABLE): main.c resources.c
	$(CC) $(CFLAGS) -o $(EXECUTABLE) resources.c main.c $(LDFLAGS) $(PKGCONFIGLIBS)

clean:
	rm -f $(EXECUTABLE) resources.c
