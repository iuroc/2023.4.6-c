#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/**
 * 进程控制系统（任务管理器）
 * @author 欧阳鹏
 * @date 2023-04-06
 */

char string[][9] = {"创建进程", "启动进程", "停止进程", "删除进程", "活动进程", "所有进程", "全部开始", "退出系统"};
char stateWords[][9] = {"准备就绪", "正在运行"};
/**
 * @brief 修改进程状态或删除进程
 *
 * @param firstPCB 链表开始地址
 * @param state 进程状态，为 3 时表示删除
 */
void changeState(struct PCB *firstPCB, int state)
{
    system("cls");
    printf("请输入进程名称：");
    char name[20];
    scanf("%s", &name);
    struct PCB *temp = firstPCB;
    while (temp->next)
    {
        struct PCB *item = temp;
        temp = temp->next;
        if (strcmp(temp->name, name) == 0)
        {
            if (state == 3)
            {
                // 删除进程
                item->next = temp->next;
                free(temp);
            }
            else
                // 修改状态
                temp->state = state;
            break;
        }
    }
}

void startAll(struct PCB *firstPCB)
{
    struct PCB *temp = firstPCB;
    while (temp->next)
    {
        temp = temp->next;
        temp->state = 2;
    }
}

int main()
{
    struct PCB firstPCB;
    firstPCB.next = NULL;
    while (1)
    {
        int num = showMenu();
        if (num == 8)
        {
            // 释放所有 malloc 创建的空间
            break;
        }
        switch (num)
        {
        case 1:
            addProcess(&firstPCB);
            break;
        case 2:
            changeState(&firstPCB, 2);
            break;
        case 3:
            changeState(&firstPCB, 1);
            break;
        case 4:
            changeState(&firstPCB, 3);
            break;
        case 5:
            showProcess(&firstPCB, 1);
            break;
        case 6:
            showProcess(&firstPCB, 0);
            break;
        case 7:
            startAll(&firstPCB);
            break;
        }
    }
}

void showProcess(struct PCB *firstPCB, int onlyRunning)
{
    system("cls");
    struct PCB *item = firstPCB;
    while (item->next)
    {
        item = item->next;
        if (onlyRunning == 0 || (onlyRunning == 1 && item->state == 2))
            printf("进程名称：%s\t状态：%s\n", item->name, stateWords[item->state - 1]);
    }
    char *line = getLineString(40);
    printf("%s\n", line);
    free(line);
    system("pause");
}

void addProcess(struct PCB *firstPCB)
{
    system("cls");
    printf("请输入进程名称：");
    struct PCB *node = (struct PCB *)malloc(sizeof(struct PCB));
    scanf("%s", node->name);
    node->next = NULL;
    node->state = 1;
    listAppend(firstPCB, node);
}

int showMenu()
{
    system("cls");
    printf("   >>> 欢迎使用本系统 <<<\n");
    char *line = getLineString(13);
    printf("┌%s┬%s┐\n", line, line);
    printf("│ 1. %s │ 2. %s │\n", string[0], string[1]);
    printf("├%s┼%s┤\n", line, line);
    printf("│ 3. %s │ 4. %s │\n", string[2], string[3]);
    printf("├%s┼%s┤\n", line, line);
    printf("│ 5. %s │ 6. %s │\n", string[4], string[5]);
    printf("├%s┼%s┤\n", line, line);
    printf("│ 7. %s │ 8. %s │\n", string[6], string[7]);
    printf("└%s┴%s┘\n", line, line);
    free(line);
    printf("请输入操作序号：");
    int num;
    scanf("%d", &num);
    return num;
}

void listAppend(struct PCB *firstPCB, struct PCB *node)
{
    struct PCB *lastNode = getLastNode(firstPCB);
    lastNode->next = node;
}

struct PCB *getLastNode(struct PCB *firstPCB)
{
    struct PCB *item = firstPCB;
    while (item->next)
        item = item->next;
    return item;
}
char *getLineString(int num)
{
    char *str = malloc(num * 3 + 1);
    strcpy(str, "");
    for (int i = 0; i < num; i++)
    {
        strcat(str, "─");
    }
    return str;
}

void startProcess(struct PCB *firstPCB, char name[])
{
}
void startOneProcess(struct PCB *firstPCB)
{
    system("cls");
    printf("请输入进程名称：");
    char name[20];
    scanf("%s", &name);
    startProcess(firstPCB, name);
}
