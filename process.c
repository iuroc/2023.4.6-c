#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/**
 * ���̿���ϵͳ�������������
 * @author ŷ����
 * @date 2023-04-06
 */

char string[][9] = {"��������", "��������", "ֹͣ����", "ɾ������", "�����", "���н���", "ȫ����ʼ", "�˳�ϵͳ"};
char stateWords[][9] = {"׼������", "��������"};
/**
 * @brief �޸Ľ���״̬��ɾ������
 *
 * @param firstPCB ����ʼ��ַ
 * @param state ����״̬��Ϊ 3 ʱ��ʾɾ��
 */
void changeState(struct PCB *firstPCB, int state)
{
    system("cls");
    printf("������������ƣ�");
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
                // ɾ������
                item->next = temp->next;
                free(temp);
            }
            else
                // �޸�״̬
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
            // �ͷ����� malloc �����Ŀռ�
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
            printf("�������ƣ�%s\t״̬��%s\n", item->name, stateWords[item->state - 1]);
    }
    char *line = getLineString(40);
    printf("%s\n", line);
    free(line);
    system("pause");
}

void addProcess(struct PCB *firstPCB)
{
    system("cls");
    printf("������������ƣ�");
    struct PCB *node = (struct PCB *)malloc(sizeof(struct PCB));
    scanf("%s", node->name);
    node->next = NULL;
    node->state = 1;
    listAppend(firstPCB, node);
}

int showMenu()
{
    system("cls");
    printf("   >>> ��ӭʹ�ñ�ϵͳ <<<\n");
    char *line = getLineString(13);
    printf("��%s��%s��\n", line, line);
    printf("�� 1. %s �� 2. %s ��\n", string[0], string[1]);
    printf("��%s��%s��\n", line, line);
    printf("�� 3. %s �� 4. %s ��\n", string[2], string[3]);
    printf("��%s��%s��\n", line, line);
    printf("�� 5. %s �� 6. %s ��\n", string[4], string[5]);
    printf("��%s��%s��\n", line, line);
    printf("�� 7. %s �� 8. %s ��\n", string[6], string[7]);
    printf("��%s��%s��\n", line, line);
    free(line);
    printf("�����������ţ�");
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
        strcat(str, "��");
    }
    return str;
}

void startProcess(struct PCB *firstPCB, char name[])
{
}
void startOneProcess(struct PCB *firstPCB)
{
    system("cls");
    printf("������������ƣ�");
    char name[20];
    scanf("%s", &name);
    startProcess(firstPCB, name);
}
