# xkb-keyboard-indicator

XKB Keyboard indicator. Indicator in Unity and KDE and regular systray application in other DE/WM.

## Status

Currently only indicator and initial settings dialog are available.

## Installation

    # build
    make

    # copy settings schema
    sudo sudo cp -f data/xki.gschema.xml /usr/share/glib-2.0/schemas
    sudo glib-compile-schemas /usr/share/glib-2.0/schemas

    # run
    ./out/xki

## Usage

### Simple

Use settings dialog to set basic layouts and options.

### Advanced

Set `layouts` and `options` in `/app/xki/` in gsettings (e. g., via `dconf-editor`).

## Requirements

You need GTK+ 3, GLib, LibXklavier and AppIndicator3-0.1.

    sudo apt-get install libgtk-3-dev libglib2.0-dev libxklavier-dev libappindicator3-dev
