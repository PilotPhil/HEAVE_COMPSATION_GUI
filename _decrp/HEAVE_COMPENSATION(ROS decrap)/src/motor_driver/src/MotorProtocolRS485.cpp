#include "MotorProtocolRS485.h"

MotorProtocolRS485::MotorProtocolRS485(byte _id) : id(_id) {}

MotorProtocolRS485::~MotorProtocolRS485(){}

byte MotorProtocolRS485::hexSumCheck(bytes _bytes, int start, int end) {
  auto it1 = _bytes.begin() + start;
  auto it2 = _bytes.begin() + end;

  if (it1 > it2)
    return 0x00;

  auto tem_bytes = bytes(it1, it2);

  byte tem;
  for (int i = 0; i < tem_bytes.size(); i++) {
    tem += tem_bytes[i];
  }

  return tem;
}

bytes MotorProtocolRS485::motoOff() {
  bytes _bytes;
  _bytes.push_back(0x3E);                      // 0 头
  _bytes.push_back(0x80);                      // 1 命令
  _bytes.push_back(id);                        // 2 id
  _bytes.push_back(0x00);                      // 3 数据长度
  _bytes.push_back(hexSumCheck(_bytes, 0, 3)); // 4 帧头校验

  return _bytes;
}

bytes MotorProtocolRS485::motoStop() {
  bytes _bytes;
  _bytes.push_back(0x3E);                      // 0 头
  _bytes.push_back(0x81);                      // 1 命令
  _bytes.push_back(id);                        // 2 id
  _bytes.push_back(0x00);                      // 3 数据长度
  _bytes.push_back(hexSumCheck(_bytes, 0, 3)); // 4 帧头校验

  return _bytes;
}

bytes MotorProtocolRS485::motoRestore() {
  bytes _bytes;
  _bytes.push_back(0x3E);                      // 0 头
  _bytes.push_back(0x88);                      // 1 命令
  _bytes.push_back(id);                        // 2 id
  _bytes.push_back(0x00);                      // 3 数据长度
  _bytes.push_back(hexSumCheck(_bytes, 0, 3)); // 4 帧头校验

  return _bytes;
}

bytes MotorProtocolRS485::speedControlClosedLoop(int speed) {
  bytes _bytes;
  _bytes.push_back(0x3E);                      // 0 头
  _bytes.push_back(0xA2);                      // 1 命令
  _bytes.push_back(id);                        // 2 id
  _bytes.push_back(0x04);                      // 3 数据长度
  _bytes.push_back(hexSumCheck(_bytes, 0, 3)); // 4 帧头校验

  byte HH = 0x00;
  byte H = 0x00;
  byte L = 0x00;
  byte LL = 0x00;

  speed *= 100;

  if (speed >= 0) {
    L = speed >> 8;
    LL = speed & 0xff;
  } else if (speed < 0) {
    HH = speed >> 24;
    H = (speed >> 16) & 0xFF;
    L = (speed >> 8) & 0xFF;
    LL = speed & 0xFF;
  }

  _bytes.push_back(LL); // 5 速度低
  _bytes.push_back(L);  // 6 速度
  _bytes.push_back(H);  // 7 速度
  _bytes.push_back(HH); // 8 速度高

  _bytes.push_back(hexSumCheck(_bytes, 5, 8)); // 9 数据校验
  return _bytes;
}

bytes MotorProtocolRS485::multiLapAngleCloseLoopControl1(int degree) {
  bytes _bytes;
  _bytes.push_back(0x3E);                      // 0 头
  _bytes.push_back(0xA3);                      // 1 命令
  _bytes.push_back(id);                        // 2 id
  _bytes.push_back(0x08);                      // 3 数据长度
  _bytes.push_back(hexSumCheck(_bytes, 0, 3)); // 4 帧头校验

  byte c1, c2, c3, c4, c5, c6, c7, c8;
  c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = 0x00;

  degree *= 100;
  if (degree > 0) {
    c7 = degree >> 8;
    c8 = degree & 0xff;
  } else if (degree < 0) {
    c1 = c2 = c3 = c4 = c5 = c6 = 0xFF;
    c7 = degree >> 8;
    c8 = degree & 0xFF;
  }

  _bytes.push_back(c8); // 5
  _bytes.push_back(c7); // 6
  _bytes.push_back(c6); // 7
  _bytes.push_back(c5); // 8
  _bytes.push_back(c4); // 9
  _bytes.push_back(c3); // 10
  _bytes.push_back(c2); // 11
  _bytes.push_back(c1); // 12

  _bytes.push_back(hexSumCheck(_bytes, 5, 13)); // 13 数据校验
  return _bytes;
}