# Bash installation script
# for Amanda Computing Platform
#
# Copyright (C) 2022, FreeLancer Development Team
# Written by J. Marrero
#

# Subshell this
(

echo "creating distribution directory..."
mkdir -p "dist/amanda-sdk"
cd "dist/amanda-sdk"

# Create the distribution subdirectories
echo "creating distribution subdirectories..."
mkdir -p bin 
mkdir -p conf
mkdir -p docs
mkdir -p docs/examples
mkdir -p lib
mkdir -p mods
mkdir -p sdk
mkdir -p tools

cd ../..

# Copy the license file
echo "copying license files..."
cp -f LICENSE dist/amanda-sdk/LICENSE
cp -f AUTHORS dist/amanda-sdk/AUTHORS

echo "copying SDK includes files..."
cp -ru include dist/amanda-sdk/sdk

echo "[SDK library files are copyied when projects are built]"

echo "done..."
)