#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100  // 最大存储图书数量

// 定义图书馆图书结构体
struct library {
    int accession_no;    // 入藏编号
    char title[50];      // 书名
    char author[30];     // 作者名
    float price;         // 图书价格
    int is_issued;       // 借出标记：0未借出，1已借出
};

struct library lib[MAX_BOOKS];
int book_count = 0;     // 当前已录入图书总数

// 菜单打印函数
void printMenu() {
    printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
    printf("1. Add book information\n");
    printf("2. Display all book information\n");
    printf("3. List all books of given author\n");
    printf("4. List title by accession number\n");
    printf("5. Show total number of books\n");
    printf("6. Sort books by accession number\n");
    printf("7. Exit\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
}

// 1. 添加图书信息
void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library storage is full! Cannot add more books.\n");
        return;
    }
    printf("\n--- Add New Book ---\n");
    printf("Enter accession number: ");
    scanf("%d", &lib[book_count].accession_no);
    getchar(); // 吸收换行符
    printf("Enter book title: ");
    gets(lib[book_count].title);
    printf("Enter author name: ");
    gets(lib[book_count].author);
    printf("Enter book price: ");
    scanf("%f", &lib[book_count].price);
    printf("Is book issued? (0=No,1=Yes): ");
    scanf("%d", &lib[book_count].is_issued);
    book_count++;
    printf("Book added successfully!\n");
}

// 2. 展示所有图书
void displayAllBooks() {
    if (book_count == 0) {
        printf("No books in library yet!\n");
        return;
    }
    printf("\n===== All Books Info =====\n");
    printf("Acc.No\tTitle\t\tAuthor\t\tPrice\tIssued\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%s\t\t%s\t%.2f\t%d\n",
               lib[i].accession_no, lib[i].title, lib[i].author,
               lib[i].price, lib[i].is_issued);
    }
}

// 3. 根据作者查询图书
void listByAuthor() {
    char target_author[30];
    getchar();
    printf("\nEnter author name to search: ");
    gets(target_author);
    int found = 0;
    printf("\nBooks by %s:\n", target_author);
    for (int i = 0; i < book_count; i++) {
        if (strcmp(lib[i].author, target_author) == 0) {
            printf("Acc.No:%d | Title:%s | Price:%.2f | Issued:%d\n",
                   lib[i].accession_no, lib[i].title, lib[i].price, lib[i].is_issued);
            found = 1;
        }
    }
    if (!found) printf("No books found for this author!\n");
}

// 4. 根据入藏编号查书名
void searchTitleByAccNo() {
    int acc;
    printf("\nEnter accession number to search: ");
    scanf("%d", &acc);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (lib[i].accession_no == acc) {
            printf("Book Title: %s\n", lib[i].title);
            found = 1;
            break;
        }
    }
    if (!found) printf("No book found with this accession number!\n");
}

// 5. 统计图书总数
void showTotalCount() {
    printf("\nTotal number of books in library: %d\n", book_count);
}

// 6. 按入藏编号升序排序
void sortByAccNo() {
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = 0; j < book_count - i - 1; j++) {
            if (lib[j].accession_no > lib[j+1].accession_no) {
                struct library temp = lib[j];
                lib[j] = lib[j+1];
                lib[j+1] = temp;
            }
        }
    }
    printf("\nBooks sorted by accession number successfully!\n");
    displayAllBooks();
}

int main() {
    int choice;
    while (1) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayAllBooks(); break;
            case 3: listByAuthor(); break;
            case 4: searchTitleByAccNo(); break;
            case 5: showTotalCount(); break;
            case 6: sortByAccNo(); break;
            case 7: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice! Please enter 1-7.\n");
        }
    }
    return 0;
}