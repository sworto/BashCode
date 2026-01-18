#!/bin/bash
PATHNAME=$1
read -ra PERMS <<< "$(ls -l $PATHNAME)"
echo "The following file has the permissions:" ${PERMS[0]} "and belongs to:" ${PERMS[3]} 