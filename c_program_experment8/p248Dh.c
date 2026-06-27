#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

// 1. 头部插入节点
void insertAtBegin(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// 2. 尾部插入节点
void insertAtEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// 3. 指定位置中间插入（pos从1开始）
void insertAtMiddle(int val, int pos) {
    if (pos == 1) {
        insertAtBegin(val);
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range, insert failed!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// 题目要求的display()：打印所有节点
void display() {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void menu() {
    printf("\n===== Linked List Menu =====\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Middle Position\n");
    printf("4. Display all nodes (display())\n");
    printf("5. Exit\n");
    printf("============================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, num, pos;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at begin: ");
                scanf("%d", &num);
                insertAtBegin(num);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &num);
                insertAtEnd(num);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &num);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insertAtMiddle(num, pos);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Program exit.\n");
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}