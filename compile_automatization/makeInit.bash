#!/bin/bash

[[ $# -ne 2 && $# -ne 4 && $# -ne 5 ]] && 
	echo "Usage: ft_function_name return_type [arg_type arg_param] [main vars]" && 

export NAME=$1
export RETURN_TYPE=$2

[[ $# -eq 4 ]] &&
	export ARG=$3 &&
	export VAL=$4

[[ $# -eq 5 ]] &&
	export VAR=$5;

 