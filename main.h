/*
 * @Author: liguoqiang
 * @Date: 2020-06-11 11:10:41
 * @LastEditors: liguoqiang
 * @LastEditTime: 2020-06-12 13:40:03
 * @Description: 
 */ 

#ifndef __MAIN_H
#define __MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <string.h>
#include <X11/Xlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 
#include <pthread.h>

#define MSGTYPE 30600
#define PACKSIZE 1400

typedef struct
{
    unsigned char srcAddr;
    unsigned char dstAddr;
    unsigned char msgType;
    unsigned char spare1;
    unsigned short msgId;
    unsigned short linkId;
    unsigned int msgLen;
    unsigned char flag;
    unsigned char packNo;
    unsigned short spare2;
}ETH_APP_ID;

typedef struct
{
    ETH_APP_ID netHead;
    unsigned intpackCnt;
    unsigned int packLen;
    unsigned char data[1400];
}CCS_VIDEO_SNDTYPE;

#endif