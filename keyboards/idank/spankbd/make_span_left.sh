#!/bin/sh

#make idank/spankbd:vial:flash -j 16 CONVERT_TO=rp2040_ce
make idank/spankbd:vial:flash -e OLED=yes -j 20
