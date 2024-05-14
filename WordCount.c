#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("用法: %s -c|-w 文件名\n", argv[0]);
        return 1;
    }

    char *param = argv[1];
    char *file_name = argv[2];
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("无法打开文件 %s\n", file_name);
        return 1;
    }

    int char_count = 0;
    int word_count = 0;
    char ch;
    bool in_word = false;

    while ((ch = fgetc(file)) != EOF) {
        char_count++;
        // 检查是否为单词分隔符
        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') {
            if (in_word) {
                word_count++; // 完成一个单词的计数
                in_word = false;
            }
        } else {
            in_word = true;
        }
    }
    // 文件结束时，检查最后一个字符是否为单词的一部分
    if (in_word) {
        word_count++;
    }
    fclose(file);
    if (strcmp(param, "-c") == 0) {
        printf("字符数：%d\n", char_count);
    } else if (strcmp(param, "-w") == 0) {
        printf("单词数：%d\n", word_count);
    } else {
        printf("无效的参数 %s\n", param);
        return 1;
    }
    return 0;
}