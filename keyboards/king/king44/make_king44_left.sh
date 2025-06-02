#!/bin/sh

#make idank/spankbd:vial:flash -j 16 CONVERT_TO=rp2040_ce
#make king/king44:vial:flash -e OLED=yes -j 20
make king/king44:vial:flash -e SIDE=left -j 20
