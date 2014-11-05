#!/bin/bash

isprime()
{
	local factors=( $(factor $1) )
	if [[ -z "${factors[2]}" ]]; then
		return 0
	fi
	return 1
}

progname="$0"

usage()
{
	printf "Usage: $progname [-i | -b] <amount>\n"
	printf "           -i Integer array only\n"
	printf "           -b Boolean array only\n"
}

main()
{
	local displaybools=true
	local displayints=true

	if [[ "$1" == "-b" ]]; then
		displayints=false
		shift 1
	fi

	if [[ "$1" == "-i" ]]; then
		displaybools=false
		shift 1
	fi

	if [[ "$#" -lt 1 ]]; then
		usage
		return
	fi

	if $displaybools; then
		printf "static const bool isPrime[] = { "
		for n in $(seq $1); do
			if isprime $n; then
				printf "true, "
			else
				printf "false, "
			fi
		done
		printf "};\n"
	fi

	if $displayints; then
		printf "static const int primes[] = { "
		for n in $(seq $1); do
			if isprime $n; then
				printf "$n, "
			fi
		done
		printf "};\n"
	fi
}

main "$@"
