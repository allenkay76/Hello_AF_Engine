#!/bin/bash

# Create the bin directory if it does not exist
if [ ! -d bin ]; then
  mkdir bin
fi

# Create the build directory if it does not exist
if [ ! -d bin/debug_WIN_x64 ]; then
  mkdir bin/debug_WIN_x64
fi

# Copy the AF_Math.dll file from AF_Math/bin to the current directory's bin folder
cp ../AF_Math/bin/AF_Math.dll bin/debug_WIN_x64/
cp ../AF_Engine/bin/AF_Engine.dll bin/debug_WIN_x64/
#cp ../AF_EngineTest/bin/AF_EngineTest.dll bin/


# Create the include directory if it does not exist
if [ ! -d include ]; then
  mkdir include
fi

# Copy the include folder from AF_Math to the current directory's include folder
cp -R ../AF_Math/include/* include/
cp -R ../AF_Engine/include/* include/
#cp -R ../AF_EngineTest/include/* include/


#copy the assets
# Create the assets directory if it does not exist
if [ ! -d bin/debug_WIN_x64/assets ]; then
  mkdir bin/debug_WIN_x64/assets
fi

cp -R ../AF_Engine/assets/* bin/debug_WIN_x64/assets/

#copy SDL2.dll
cp ../AF_Engine/bin/SDL2.dll bin/debug_WIN_x64/