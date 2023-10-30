# !/bin/bash

# source files and target file
SRC_DIRS=(
    "/home/dafoamuser/workspace/CFD_homework/homework3/Solvers"
    "/home/dafoamuser/workspace/CFD_homework/homework3/Lax"
    "/home/dafoamuser/workspace/CFD_homework/homework3/Scripts"
    "/home/dafoamuser/workspace/CFD_homework/homework3/DataTable"
    "/home/dafoamuser/workspace/CFD_homework/homework3/Wrapper"
    "/home/dafoamuser/workspace/CFD_homework/homework3/Lax-Wendroff"
    "/home/dafoamuser/workspace/CFD_homework/homework3/FirstOrderUpwind"
)
DEST_DIR="/home/dafoamuser/workspace/CFD_homework/homework3/Include"

# clean the target directory
rm -rf $DEST_DIR/*
mkdir -p $DEST_DIR

# use find to create symbolic links
for SRC_DIR in ${SRC_DIRS[@]}; do
    find $SRC_DIR \( -name "*.H" -o -name "*.C" \) -exec ln -s {} $DEST_DIR \;
done
