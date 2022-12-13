#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createList(int a[], int n);

struct ListNode *sortList(struct ListNode *head);

void output(struct ListNode *head);

struct ListNode *insertNode(struct ListNode *head, int n);

struct ListNode *removeNode(struct ListNode *head, int n);

int main() {
    int a[10000];
    int n, ins, rm;
    scanf("%d", &n);
    scanf("%d", &ins);
    scanf("%d", &rm);
    // 第一行三个整数 N,M,G；
    // N 为链表中节点个数，M 为将要插入链表中的元素，G 为要在链表中删除的元素。
    // 之后 N 行为初始化的 N 个元素
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    struct ListNode *list = createList(a, n);
    output(list);
    list = sortList(list);
    output(list);
    list = insertNode(list, ins);
    output(list);
    list = removeNode(list, rm);
    output(list);
    return 0;
}

struct ListNode* createList(int a[],int n){
    // TODO: 填写创建链表的函数
    struct ListNode* head;
    struct ListNode* p;
    
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val =0;
    head->next = NULL;
    for (int i = n-1; i >=0; i--)
    {
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = a[i];
        p->next = head->next;
        head->next = p;
    }
    return head;
}
struct ListNode* sortList(struct ListNode* head){
  // TODO: 填写链表排序的函数
    // ListNode *pl = head,*pr =head;
    
    struct ListNode *p;
    struct ListNode *pr;
    struct ListNode *prr;
    int temp;
    for (struct ListNode* pl = head->next; pl->next != NULL; pl= pl->next )
    {
        for (pr = head->next,p=head; pr->next != NULL;)
        {
            if (pr->val > pr->next->val)
            {
                prr = pr->next;
                // temp =pr->next->val;
                // pr->next->val = pr->val;
                // pr->val =temp;
                p->next =prr;
                pr->next =prr->next;
                prr->next =pr;
            }
            if (pr->next == NULL)
            {
                break;
            }
            
            pr= pr->next;
            p=p->next;
            
        }
    }
    
    return head;
}
void output(struct ListNode* head){
  // TODO: 填写输出每个节点值的函数
    head=head->next;
    while (head != NULL)
    {
        printf("%d\n",(head->val));
        head = head->next;
    }
    // printf("\n");
}
struct ListNode* insertNode(struct ListNode* head,int n){
    // TODO: 填写向有序链表插入值的函数
    struct ListNode* ans = head;
    struct ListNode* temp;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = n;
    for (;head->next->val < n;head =head->next)
    {}
    temp->next = head->next;
    head->next=temp;
    
    return ans;
}
struct ListNode* removeNode(struct ListNode* head,int n){
    // TODO: 填写删除链表中指定值的函数
    struct ListNode* ans =head;
    int flag = 0;//flag ==1 -> no such num;
    struct ListNode* temp =head;
    head = head->next;
    for (;head->next != NULL;head =head->next,temp=temp->next)
    {
        if (head->val==n)
        {
            temp->next =head->next;
        }
        
    }
    return ans;
}
