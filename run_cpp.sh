#!/bin/bash

# This checks if a C++ file with the specified filename exists.
if [ -z "$1" ]; then
	echo "Usage: $0 <cpp_file>"
	exit 1
fi

# This sets the variable filename to the specified filename.
filename="${1%.*}"

# Compiles the file using g++
g++ "$1" -o "$filename"

# Check if compilation was successful
if [ $? -eq 0 ]; then
	echo "Compilation successful: running $filename..."
	./"$filename"
else
	echo "Compilation failed."
fi
