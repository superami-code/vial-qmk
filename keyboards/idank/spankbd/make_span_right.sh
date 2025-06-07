#!/bin/sh

#make idank/spankbd:vial:flash -j 16 CONVERT_TO=rp2040_ce
#make idank/spankbd:vial:flash -e POINTING_DEVICE=vendor -e POINTING_DEVICE_POSITION=right -e OLED=yes -j 20
make idank/spankbd:vial:flash -e POINTING_DEVICE=vendor -e POINTING_DEVICE_POSITION=right -j 20
#make idank/spankbd:vial:flash -j 20
