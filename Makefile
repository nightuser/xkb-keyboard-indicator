CC := gcc
CFLAGS := -O2 -Wall -Wextra
LDFLAGS :=

PROJECT := xki

PKGCONFIGLIBS := `pkg-config --cflags --libs glib-2.0 gtk+-3.0 libxklavier appindicator3-0.1`

SRCDIR := src
DATADIR := data
OUTDIR := out
TARGET := $(OUTDIR)/$(PROJECT)
HEADERS := $(SRCDIR)/about.h \
				   $(SRCDIR)/settings.h \
				   $(SRCDIR)/indicator.h \
				   $(SRCDIR)/global.h \
				   $(SRCDIR)/version.h
SOURCES := $(SRCDIR)/about.c \
           $(SRCDIR)/settings.c \
           $(SRCDIR)/indicator.c \
           $(SRCDIR)/main.c
RESOURCES := $(OUTDIR)/resources.c
GRESOURCEFILE := $(DATADIR)/xki.gresource.xml

all: $(TARGET)

$(RESOURCES): $(GRESOURCEFILE) $(DATADIR)/*.ui $(OUTDIR)
	glib-compile-resources --target=$(RESOURCES) --sourcedir=$(DATADIR) --generate-source --c-name $(PROJECT) $(GRESOURCEFILE)

$(TARGET): $(RESOURCES) $(SOURCES) $(HEADERS) $(OUTDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(RESOURCES) $(SOURCES) $(LDFLAGS) $(PKGCONFIGLIBS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

clean:
	rm -rf $(OUTDIR)
