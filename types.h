#include <stdio.h>
/** 进程控制块 */
struct PCB
{
    /** 进程名称 */
    char name[20];
    /** 进程状态，1：准备就绪，2：正在运行 */
    int state;
    struct PCB *next;
};
/**
 * @brief 显示主菜单
 * @return 选项序号
 */
int showMenu();
/**
 * @brief 链表末尾插入节点
 *
 * @param firstPCB 链表起点地址
 * @param node 要插入的节点地址
 */
void listAppend(struct PCB *firstPCB, struct PCB *node);
/**
 * @brief 菜单事件，创建进程
 *
 * @param firstPCB 链表开始地址
 */
void addProcess(struct PCB *firstPCB);
/**
 * @brief 获取链表最后一个节点地址
 *
 * @param firstPCB 链表起点地址
 * @return 最后一个节点地址
 */
struct PCB *getLastNode(struct PCB *firstPCB);
/**
 * @brief 菜单事件，显示进程列表
 *
 * @param firstPCB 链表起点地址
 * @param onlyRunning 是否只显示正在运行的进程
 */
void showProcess(struct PCB *firstPCB, int onlyRunning);
/** 获取指定长度的横线 */
char *getLineString(int num);

/**
 * @brief 启动某个进程
 *
 * @param firstPCB 链表开始地址
 * @param name 进程名称
 */
void startProcess(struct PCB *firstPCB, char name[]);
/**
 * @brief 菜单事件，启动进程
 *
 * @param firstPCB
 */
void startOneProcess(struct PCB *firstPCB);