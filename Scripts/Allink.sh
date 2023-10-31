# !/bin/bash

# source files and target file
SRC_DIRS=(
    "../Solvers"
    "../Lax"
    "../Scripts"
    "../DataTable"
    "../Wrapper"
    "../Lax-Wendroff"
    "../FirstOrderUpwind"
)
DEST_DIR="../Include"

# clean the target directory
rm -rf $DEST_DIR/*
mkdir -p $DEST_DIR

# use find to create symbolic links
for SRC_DIR in ${SRC_DIRS[@]}; do
    find $SRC_DIR \( -name "*.H" -o -name "*.C" \) -exec ln -s {} $DEST_DIR \;
done
