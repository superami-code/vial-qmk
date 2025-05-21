#!/bin/sh

curl 127.0.0.1:9916/command \
  -H 'content-type: application/json' \
  -d '{"id":5}'

curl 127.0.0.1:9916/command \
  -H 'content-type: application/json' \
  -d '{"id":6}'

curl 127.0.0.1:9916/command \
  -H 'content-type: application/json' \
  -d '{"id":16,"data":[21,128,128,1,76]}'
