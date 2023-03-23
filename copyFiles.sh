#!/bin/bash

# Create the bin directory if it does not exist
if [ ! -d bin ]; then
  mkdir bin
fi

# Copy the AF_Math.dll file from AF_Math/bin to the current directory's bin folder
cp ../AF_Math/bin/AF_Math.dll bin/

# Create the include directory if it does not exist
if [ ! -d include ]; then
  mkdir include
fi

# Copy the include folder from AF_Math to the current directory's include folder
cp -R ../AF_Math/include/* include/
