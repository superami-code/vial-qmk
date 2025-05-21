import HID from 'node-hid';
import os from 'os';
import { getLoads } from './cpu';

const VENDOR_ID  = 0xBB80;
const PRODUCT_ID = 0x0504;
const USAGE_PAGE = 0xFF60;
const USAGE_ID   = 0x61;

const CPU_LOAD   = 1;

const [deviceInfo] = HID.devices().filter(
  ({vendorId, productId, usagePage}) =>
  vendorId === VENDOR_ID
  && productId === PRODUCT_ID
  && usagePage === USAGE_PAGE
);
if (!deviceInfo) {
  console.log(`Could not find Keyboard endpoint`);
  process.exit(1);
}

const keyboard = new HID.HID(deviceInfo?.path || '');
if (!keyboard) {
  console.log(`Could not open connection with keyboard`);
  process.exit(2);
}

keyboard.on(`data`, (data:any) => {
  console.log(`Bytes recevied from keyboard: (${data.length})`, ...data.slice(0,12) );
});

let counter = 0;
setInterval( () => {
  const data = [0,0,0,0,0,0,0,0];
  getLoads().map( ({percent}, i) => {
    data[i >> 1] += Math.round(percent*128);
  });
  counter += 16;
  data[0] = counter & 0xFF;
  keyboard.write(data);
}, 1000)
