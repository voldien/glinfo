#!/bin/bash
#
# SCRIPT: Generate AppImage BuilScript
# AUTHOR: Valdemar Lindberg
# DATE:
# REV: 0.1.B
#
# PLATFORM: Linux
#
# PURPOSE: Handle the whole process of generating an AppImage

# set -n
# Uncomment to check script syntax, without execution.
#
# NOTE: Do not forget to put the comment back in or
#
# the shell script will not execute!
# set -x
# Uncomment to debug this shell script
#

FILEPATH_DIR=`dirname $(readlink -f $0)`

BUILD_DIRECTORY=build_app
BUILD_INSTALL_DIR=AppDir

ICON_INTERNAL_FILENAME=glinfo-icon
ICON_BASE_FILENAME=glinfo-icon.png
ICON_FILEPATH=$FILEPATH_DIR/$ICON_BASE_FILENAME

DESKTOP_FILEPATH=$FILEPATH_DIR/glinfo.desktop
INSTALL_PATH_PREFIX="$BUILD_INSTALL_DIR/usr"

#-DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_PREFIX
BUILD_COMMAND="-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=TRUE -DCMAKE_BUILD_TYPE=Release -DBUILD_WITH_INSTALL=ON"

mkdir -p $BUILD_DIRECTORY && cd $BUILD_DIRECTORY
cmake $BUILD_COMMAND ..
cmake  --build . --parallel $(nproc --all) --target glinfo
cmake --install . --prefix $INSTALL_PATH_PREFIX

# Download the tool required to setup an AppImage
wget -nc https://github.com/linuxdeploy/linuxdeploy/releases/download/1-alpha-20250213-2/linuxdeploy-x86_64.AppImage
chmod +x linuxdeploy-x86_64.AppImage

# Copy and transfer	the icon file
cp $ICON_FILEPATH $BUILD_INSTALL_DIR/glinfo.png

export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:$(pwd)/$BUILD_INSTALL_DIR/lib/"
# Export variable, since the build tool is still in alpha and has its limitations.
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:/usr/lib/x86_64-linux-gnu:$(pwd)/$BUILD_INSTALL_DIR/usr/lib:$(pwd)/$BUILD_INSTALL_DIR/usr/lib/x86_64-linux-gnu"

Version=1.0

./linuxdeploy-x86_64.AppImage --appdir=$BUILD_INSTALL_DIR/ --output appimage --desktop-file=$DESKTOP_FILEPATH --icon-filename $ICON_INTERNAL_FILENAME --icon-file $ICON_FILEPATH
