help:
    @just --list

# build nk65
nk65-compile:
    qmk compile -kb novelkeys/nk65/base

# flask nk65
nk65-flash:
    qmk flash -kb novelkeys/nk65/base

# build hhkb
hhkb-compile:
    qmk compile -kb hhkb/ansi

# flask hhkb
hhkb-flash:
    qmk flash -kb hhkb/ansi
