#include "stdio.h"
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

// 根据数组创建一个链表
struct ListNode *createList(int *arr, int length) {
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *fakeHead = head;
    for (int i = 0; i < length; ++i) {
        struct ListNode *temp = (struct ListNode *) malloc(sizeof(struct ListNode));
        temp->val = arr[i];
        temp->next = NULL;
        head->next = temp;
        head = head->next;
    }
    return fakeHead->next;
}

// 合并两个链表
struct ListNode *concatList(struct ListNode *head1, struct ListNode *head2) {
    struct ListNode *pre = head1;
    if (head1 == NULL) {
        return head2;
    }
    while (head1->next != NULL) {
        head1 = head1->next;
    }
    head1->next = head2;
    return pre;
}

int main() {
    int n, m, k;
    // 链表A在公共节点前的部分的长度
    scanf("%d", &n);
    // 链表B在公共节点前的部分的长度
    scanf("%d", &m);
    // 公共节点部分长度
    scanf("%d", &k);
    int arrn[n];
    int arrm[m];
    int arrk[k];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arrn[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &arrm[i]);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &arrk[i]);
    }
    // 创建三个链表   
    struct ListNode *headN = createList(arrn, n);
    struct ListNode *headM = createList(arrm, m);
    struct ListNode *headK = createList(arrk, k);
    // 将公共节点之前的部分和公共部分结合  
    struct ListNode *headA = concatList(headN, headK);
    struct ListNode *headB = concatList(headM, headK);
    // 获取链表的公共节点  
    struct ListNode *res = getIntersectionNode(headA, headB);
    while (res != NULL) {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // TODO: 填写获取公共节点的代码
    struct ListNode *headAP=headA,*headBP=headB;
    int na=0,nb=0;
    while (headAP != NULL)
    {
        headAP = headAP->next;
        na++;
    }
    while (headBP != NULL)
    {
        headBP = headBP->next;
        nb++;
    }
    int a[na],b[nb];
    int i =0;
    for (headAP=headA;headAP != NULL;headAP =headAP->next,i++)
    {
        a[i]=headAP->val;
    }
    i=0;
        for (headBP=headB;headBP != NULL;headBP =headBP->next,i++)
    {
        b[i]=headBP->val;
    }
    int j = na-1,k = nb-1;
    for (;j >= 0&&k>=0;j--,k--)
    {
        if (a[j]==b[k])
        {

        }
        else
        {
            break;
        }        
    }
    j=j+1;
    k=k+1;
    for (;j>0;j--)
    {
        headA =headA->next;
    }   
    return headA;
}
