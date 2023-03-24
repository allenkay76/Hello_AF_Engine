#!/bin/bash

# Create the bin directory if it does not exist
if [ ! -d bin ]; then
  mkdir bin
fi

# Copy the AF_Math.dll file from AF_Math/bin to the current directory's bin folder
cp ../AF_Math/bin/AF_Math.dll bin/
cp ../AF_Engine/bin/AF_Engine.dll bin/


# Create the include directory if it does not exist
if [ ! -d include ]; then
  mkdir include
fi

# Copy the include folder from AF_Math to the current directory's include folder
cp -R ../AF_Math/include/* include/
cp -R ../AF_Engine/include/* include/


#copy the assets
# Create the assets directory if it does not exist
if [ ! -d assets ]; then
  mkdir assets
fi

cp -R ../AF_Engine/assets/* assets/

#copy SDL2.dll
cp ../AF_Engine/bin/SDL2.dll bin/