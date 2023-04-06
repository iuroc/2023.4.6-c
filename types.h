#include <stdio.h>

char string[][9] = {"��������", "��������", "ֹͣ����", "ɾ������", "�����", "���н���", "ȫ����ʼ", "�˳�ϵͳ"};
char stateWords[][9] = {"׼������", "��������"};

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
 * @brief �޸Ľ���״̬��ɾ������
 *
 * @param firstPCB ����ʼ��ַ
 * @param state ����״̬��Ϊ 3 ʱ��ʾɾ��
 */
void changeState(struct PCB *firstPCB, int state);
/**
 * @brief �������н���
 *
 * @param firstPCB ����ʼ��ַ
 */
void startAll(struct PCB *firstPCB);