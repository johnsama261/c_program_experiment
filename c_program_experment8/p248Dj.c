#include <stdio.h>
#include <stdlib.h>

// 定义队列链表节点
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// 队头、队尾全局指针
struct QueueNode *front = NULL, *rear = NULL;

// 入队：在rear位置添加元素
void enqueue(int val) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("内存分配失败，无法入队！\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    // 队列为空时，头尾都指向新节点
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d 成功入队\n", val);
}

// 出队：从front位置删除元素
void dequeue() {
    if (front == NULL) {
        printf("队列为空，无法出队！\n");
        return;
    }
    struct QueueNode* temp = front;
    int del_val = temp->data;
    front = front->next;
    // 队列删空后重置rear
    if (front == NULL)
        rear = NULL;
    free(temp);
    printf("%d 成功出队\n", del_val);
}

// 查看队首元素
void peekFront() {
    if (front == NULL) {
        printf("队列为空，无队首元素！\n");
        return;
    }
    printf("队首元素：%d\n", front->data);
}

// 遍历打印队列所有元素
void displayQueue() {
    if (front == NULL) {
        printf("队列为空！\n");
        return;
    }
    struct QueueNode* temp = front;
    printf("队列元素(队首→队尾)：");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 菜单界面
void menu() {
    printf("\n===== 链表实现队列操作菜单 =====\n");
    printf("1. 入队(Enqueue)\n");
    printf("2. 出队(Dequeue)\n");
    printf("3. 查看队首元素\n");
    printf("4. 遍历打印队列\n");
    printf("5. 退出程序\n");
    printf("================================\n");
    printf("请输入操作选项：");
}

int main() {
    int choice, num;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("请输入入队整数：");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peekFront();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("程序退出\n");
                return 0;
            default:
                printf("无效选项，请输入1-5！\n");
        }
    }
    return 0;
}