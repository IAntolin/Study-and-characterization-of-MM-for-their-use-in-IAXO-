#!/bin/bash

# This script sets up an environment variable and then launches restManager for a range of files.

export NAME=Lab
export PRESSURE=1.2
filename="simFiles_${NAME}/RestG4_Laboratory.root" #filename="simFiles_${NAME}/RestG4_${PRESSURE}_l.root"
# Launch restManager with the constructed filename
if [ -f "$filename" ]; then
        # Launch restManager with the constructed filename. Other filename: Ar_Analysis2.rml
        restManager --c Ar_Analysis2.rml --f "$filename" --e 325675
    else
        echo "File $filename does not exist."
    fi
