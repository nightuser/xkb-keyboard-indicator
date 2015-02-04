# xkb-keyboard-indicator
XKB Keyboard indicator for Unity.

## Status

Currently only indicator and initial settings dialog are available.

## Installation

    # build
    make

    # copy settings schema
    sudo sudo cp -f xki.gschema.xml /usr/share/glib-2.0/schemas
    sudo glib-compile-schemas /usr/share/glib-2.0/schemas

    #run
    ./xki

## Usage

### Simple

Use settings dialog to set basic layouts and options.

### Advanced

Set layouts and options in `/app/xki/` in gsettings (e. g., via dconf-editor).

## Usage (Deprecated)

Set xorg xkb settings via `xorg.conf` of `setxkbmap`.

Example (English and Russian layouts with Caps-toggle):

    setxkbmap -layout "us,ru"
    setxkbmap -option "grp:caps_toggle,grp_led:scroll"

## Requirements

You need GTK+3.0, GLIB-2.0, libXKlavier and libAppIndicator3.

    sudo apt-get install libgtk-3-dev libglib2.0-dev libxklavier-dev libappindicator3-dev
