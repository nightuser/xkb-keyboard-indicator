# xki - XKB Keyboard indicator
#
# Copyright (C) 2015 Svyatoslav Gryaznov
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

# - Try to find LibXKlavier
# Once done this will define
#  LIBXKLAVIER_FOUND - System has LibXKlavier
#  LIBXKLAVIER_INCLUDE_DIRS - The LibXKlavier include directories
#  LIBXKLAVIER_LIBRARIES - The libraries needed to use LibXKlavier
#  LIBXKLAVIER_DEFINITIONS - Compiler switches required for using LibXKlavier

find_package(PkgConfig)
pkg_check_modules(PC_LIBXKLAVIER QUIET libxklavier)
# set(LIBXKLAVIER_DEFINITIONS ${PC_LIBXKLAVIER_CFLAGS_OTHER})

find_path(LIBXKLAVIER_INCLUDE_DIR NAMES libxklavier/xklavier.h
          HINTS ${PC_LIBXKLAVIER_INCLUDEDIR} ${PC_LIBXKLAVIER_INCLUDE_DIRS}
          PATH_SUFFIXES libxklavier)

find_library(LIBXKLAVIER_LIBRARY NAMES xklavier
             HINTS ${PC_LIBXKLAVIER_LIBDIR} ${PC_LIBXKLAVIER_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(LibXKlavier  DEFAULT_MSG
                                  LIBXKLAVIER_LIBRARY LIBXKLAVIER_INCLUDE_DIR)

set(LIBXKLAVIER_LIBRARIES ${LIBXKLAVIER_LIBRARY})
set(LIBXKLAVIER_INCLUDE_DIRS ${LIBXKLAVIER_INCLUDE_DIR})

mark_as_advanced(LIBXKLAVIER_INCLUDE_DIR LIBXKLAVIER_LIBRARY)
