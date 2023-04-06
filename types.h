#include <stdio.h>
/** ���̿��ƿ� */
struct PCB
{
    /** �������� */
    char name[20];
    /** ����״̬��1��׼��������2���������� */
    int state;
    struct PCB *next;
};
/**
 * @brief ��ʾ���˵�
 * @return ѡ�����
 */
int showMenu();
/**
 * @brief ����ĩβ����ڵ�
 *
 * @param firstPCB ��������ַ
 * @param node Ҫ����Ľڵ��ַ
 */
void listAppend(struct PCB *firstPCB, struct PCB *node);
/**
 * @brief �˵��¼�����������
 *
 * @param firstPCB ����ʼ��ַ
 */
void addProcess(struct PCB *firstPCB);
/**
 * @brief ��ȡ�������һ���ڵ��ַ
 *
 * @param firstPCB ��������ַ
 * @return ���һ���ڵ��ַ
 */
struct PCB *getLastNode(struct PCB *firstPCB);
/**
 * @brief �˵��¼�����ʾ�����б�
 *
 * @param firstPCB ��������ַ
 * @param onlyRunning �Ƿ�ֻ��ʾ�������еĽ���
 */
void showProcess(struct PCB *firstPCB, int onlyRunning);
/** ��ȡָ�����ȵĺ��� */
char *getLineString(int num);

/**
 * @brief ����ĳ������
 *
 * @param firstPCB ����ʼ��ַ
 * @param name ��������
 */
void startProcess(struct PCB *firstPCB, char name[]);
/**
 * @brief �˵��¼�����������
 *
 * @param firstPCB
 */
void startOneProcess(struct PCB *firstPCB);