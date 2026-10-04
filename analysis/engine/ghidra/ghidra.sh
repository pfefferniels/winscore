#!/bin/zsh
# Run engine GhidraScripts against tools/ghidra-project (single writer: never run two at once).
#   ghidra.sh names                     apply names.tsv and globals.tsv
#   ghidra.sh constants                 type read-only constants (run once)
#   ghidra.sh decompile 0xADDR ...      write analysis/engine/decompiled/<addr>_<name>.c
#   ghidra.sh tmp out_dir 0xADDR ...    decompile into another directory (read-only)
H=${0:A:h}; E=${H:h}; R=${E:h:h}
T=$R/tools
run() { JAVA_HOME=/opt/homebrew/opt/openjdk@21 $T/ghidra/support/analyzeHeadless $T/ghidra-project WinScore \
  -process WScore.exe -noanalysis -scriptPath $H "$@" 2>&1 | grep -E '^INFO  .*\.java>|ERROR|Exception' | sed 's/^INFO  //' }
case $1 in
  names) run -postScript ApplyNames.java $E ;;
  constants) run -postScript TypeConstants.java ;;
  decompile) shift; run -readOnly -postScript DecompileEach.java $E/decompiled "$@" ;;
  tmp) shift; d=${1:A}; shift; run -readOnly -postScript DecompileEach.java $d "$@" ;;
  *) echo "usage: ghidra.sh names|constants|decompile ADDR...|tmp DIR ADDR..." ;;
esac
