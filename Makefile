CC := gcc
CFLAGS := -O2 -Wall -Wextra
LDFLAGS :=

PKGCONFIGLIBS := `pkg-config --cflags --libs glib-2.0 gtk+-3.0 libxklavier appindicator3-0.1`

EXECUTABLE := xki
SOURCES := main.c
RESOURCES := resources.c
GRESOURCEFILE := xki.gresource.xml

all: $(EXECUTABLE)

$(RESOURCES): $(GRESOURCEFILE) *.ui
	glib-compile-resources --target=$(RESOURCES) --generate-source --c-name $(GRESOURCEFILE:.gresource.xml=) $(GRESOURCEFILE)

$(EXECUTABLE): $(RESOURCES) $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(RESOURCES) $(SOURCES) $(LDFLAGS) $(PKGCONFIGLIBS)

clean:
	rm -f $(EXECUTABLE) $(RESOURCES)
