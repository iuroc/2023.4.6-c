#include <stdio.h>

char string[][9] = {"创建进程", "启动进程", "停止进程", "删除进程", "活动进程", "所有进程", "全部开始", "退出系统"};
char stateWords[][9] = {"准备就绪", "正在运行"};

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
 * @brief 修改进程状态或删除进程
 *
 * @param firstPCB 链表开始地址
 * @param state 进程状态，为 3 时表示删除
 */
void changeState(struct PCB *firstPCB, int state);
/**
 * @brief 启动所有进程
 *
 * @param firstPCB 链表开始地址
 */
void startAll(struct PCB *firstPCB);