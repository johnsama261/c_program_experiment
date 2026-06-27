#include <stdio.h>
#include <stdlib.h>

// 定义栈的链表节点
struct StackNode {
    int data;
    struct StackNode* next;
};
// 栈顶指针
struct StackNode* top = NULL;

// 入栈：向栈顶添加元素
void push(int val) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("内存分配失败，栈溢出！\n");
        return;
    }
    newNode->data = val;
    newNode->next = top; // 新节点指向原栈顶
    top = newNode;       // 更新栈顶为新节点
    printf("%d 已入栈\n", val);
}

// 出栈：删除并返回栈顶元素
void pop() {
    if (top == NULL) {
        printf("栈为空，无法出栈！\n");
        return;
    }
    struct StackNode* temp = top;
    int del_val = temp->data;
    top = top->next; // 栈顶后移
    free(temp);      // 释放原栈顶节点内存
    printf("%d 已出栈\n", del_val);
}

// 查看栈顶元素
void peek() {
    if (top == NULL) {
        printf("栈为空，无栈顶元素！\n");
        return;
    }
    printf("当前栈顶元素：%d\n", top->data);
}

// 遍历打印栈内所有元素
void displayStack() {
    if (top == NULL) {
        printf("栈为空！\n");
        return;
    }
    struct StackNode* temp = top;
    printf("栈内元素（栈顶→栈底）：");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 菜单界面
void menu() {
    printf("\n===== 链表实现栈操作菜单 =====\n");
    printf("1. 入栈(Push)\n");
    printf("2. 出栈(Pop)\n");
    printf("3. 查看栈顶(Peek)\n");
    printf("4. 遍历打印栈\n");
    printf("5. 退出程序\n");
    printf("==============================\n");
    printf("请输入操作选项：");
}

int main() {
    int choice, num;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("请输入要入栈的整数：");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("程序退出\n");
                return 0;
            default:
                printf("输入无效，请选择1-5的选项！\n");
        }
    }
    return 0;
}