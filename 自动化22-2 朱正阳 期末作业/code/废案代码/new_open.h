#include "hand.h"

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 300

int ReadStudents()
{
    // �ļ�����
    char _path[200];
    printf("���������������ļ��� ������·����\n");
    scanf("%s", _path);

    FILE *file;
    file = fopen(_path, "r");
    if (file == NULL)
    {
        printf("�޷����ļ�\n");
        return 1;
    }

    char names[MAX_STUDENTS][MAX_NAME_LENGTH]; // ����һ���ַ����������ڴ洢����
    int num_names = 0;

    fseek(file, 0, SEEK_SET);
    while (!feof(file) && num_names < MAX_STUDENTS)
    {                                         // ѭ����ȡÿһ�У�ֱ���ļ���������������
        fscanf(file, "%s", names[num_names]); // ��ȡһ��
        num_names++;
    }

    fclose(file); // �ر��ļ�
    printf("�ɹ���ȡ�ˣ�%d ��\n", num_names);

    // ���:����һ��������ʵ�ֽ��

    int go = 1; // ѭ����ʼ��
    while (go != -1)
    {
        // ʹ�õ�ǰʱ����Ϊ��������ʼ�������������
        srand(time(NULL));
        // ����һ������������������ȡģ���㣬�Ի�ȡ����Чѧ����Χ�ڵ��������
        int selected_student = rand() % num_names;

        char buffer[200];
        sprintf(buffer, "�鵽��ѧ���ǣ�%s ��ѧ��Ϊ %d", names[selected_student], selected_student + 1);
        int result = MessageBox(NULL, buffer, "�齱�ɹ�", MB_RETRYCANCEL);

        switch (result)
        {
        case IDABORT:
            // �û������"����"��ť���ڴ˴������Ӧ�Ĵ���
            go = -1;
        case IDIGNORE:
            MessageBox(NULL, "�����Ҫ�˳���", "��鼸���� qwq", MB_OK);
        }
    }
    return 0;
}

/*
���ȣ��������������꣺MAX_NAME_LENGTH �� MAX_STUDENTS��ǰ���趨��ÿ�����ֵ���󳤶�Ϊ50���ַ��������趨��ѧ�����������ֵΪ300��

ReadStudents() ��������Ҫ���ܺ���������������У�

����ͼ��һ����Ϊ students.txt ���ļ������ļ�Ӧ�ð���ѧ�������ֺ�ѧ�š�����ļ��޷��򿪣��������ӡ������Ϣ������1��
����һ���ַ������� names�����ڴ洢��ȡ����ѧ�����֡�����Ĵ�СΪ MAX_STUDENTS x MAX_NAME_LENGTH��ȷ���ܹ��洢ÿ��ѧ�������ֺ�ѧ�ţ�����ѧ�������֣�ÿ������ռһ���ַ�����
ʹ�� fseek(file,0,SEEK_SET) ���ļ�ָ�����¶�λ���ļ��Ŀ�ʼλ�á�
ͨ��һ��ѭ�����ļ��ж�ȡÿһ�е����ݣ�����ÿ�е����ݣ�������ѧ�������֣��洢�� names �����С�ѭ����һֱ���У�ֱ���ﵽ�ļ�ĩβ�����Ѷ�ȡ��ѧ�������ﵽ MAX_STUDENTS��
ʹ�� fclose(file) �ر��ļ���
��ӡ�ɹ���ȡ��ѧ��������
ʹ�õ�ǰʱ����Ϊ����������������ӣ���ȷ��ÿ�γ�������ʱ���ܲ�����ͬ���������
����һ�����������ȡģ�Ի�ȡһ������Чѧ����Χ�ڵ����������
��ӡѡ����ѧ�������ֺ�ѧ�ţ������ѧ����ʵ����ǰ�����ɵ������������
*/
