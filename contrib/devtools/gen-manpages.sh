#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

EZ25COIND=${EZ25COIND:-$BINDIR/ez25coind}
EZ25COINCLI=${EZ25COINCLI:-$BINDIR/ez25coin-cli}
EZ25COINTX=${EZ25COINTX:-$BINDIR/ez25coin-tx}
EZ25COINQT=${EZ25COINQT:-$BINDIR/qt/ez25coin-qt}

[ ! -x $EZ25COIND ] && echo "$EZ25COIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
EZCVER=($($EZ25COINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for ez25coind if --version-string is not set,
# but has different outcomes for ez25coin-qt and ez25coin-cli.
echo "[COPYRIGHT]" > footer.h2m
$EZ25COIND --version | sed -n '1!p' >> footer.h2m

for cmd in $EZ25COIND $EZ25COINCLI $EZ25COINTX $EZ25COINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${EZCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${EZCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
