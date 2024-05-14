#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("�÷�: %s -c|-w �ļ���\n", argv[0]);
        return 1;
    }

    char *param = argv[1];
    char *file_name = argv[2];
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("�޷����ļ� %s\n", file_name);
        return 1;
    }

    int char_count = 0;
    int word_count = 0;
    char ch;
    bool in_word = false;

    while ((ch = fgetc(file)) != EOF) {
        char_count++;
        // ����Ƿ�Ϊ���ʷָ���
        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') {
            if (in_word) {
                word_count++; // ���һ�����ʵļ���
                in_word = false;
            }
        } else {
            in_word = true;
        }
    }
    // �ļ�����ʱ��������һ���ַ��Ƿ�Ϊ���ʵ�һ����
    if (in_word) {
        word_count++;
    }
    fclose(file);
    if (strcmp(param, "-c") == 0) {
        printf("�ַ�����%d\n", char_count);
    } else if (strcmp(param, "-w") == 0) {
        printf("��������%d\n", word_count);
    } else {
        printf("��Ч�Ĳ��� %s\n", param);
        return 1;
    }
    return 0;
}