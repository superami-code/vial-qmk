# v1.0 of the board needs a replacement of the matrix.c in QMK as it require ROWS to be active HIGH
# switching to PNP transistors for the board could resolve this in future versions
SRC += matrix.c
CUSTOM_MATRIX=yes

VIAL_INSECURE=yes
