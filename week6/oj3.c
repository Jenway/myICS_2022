#include<stdlib.h>
#include<stdio.h>

// 结点类
struct ListNode {
    int val;
    struct ListNode *next;
};

// 需要实现的函数
void deleteDuplicates(struct ListNode *head);

int main() {
    int amount;
    struct ListNode *head, *temp;
  
    // 读入数据
    scanf("%d", &amount);
    for (int i = 0; i < amount; i++) {
        struct ListNode *input = (struct ListNode *) malloc(sizeof(struct ListNode));
        scanf("%d", &(input->val));

        if (i == 0) {
            head = input;
            temp = head;
        } else {
            temp->next = input;
            temp = temp->next;
        }

        if (i == amount - 1)
            temp->next = NULL;
    }
  
    // 执行函数
    deleteDuplicates(head);

    // 输出
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

// TODO: 在下方补全函数实现
void deleteDuplicates(struct ListNode *head){

    struct ListNode *count = head;

    for (struct ListNode *pi=head;pi!=NULL;pi =pi->next)
    {
        count = pi;
        for (struct ListNode *pj=pi->next;pj!=NULL;pj=pj->next)
        {
            if (pi->val==pj->val)
            {
                if (pj->next==NULL)
                {
                    count->next = NULL;
                }
                else
                {
                    count->next=pj->next;
                } 
            }
            else
            {
                count = count->next;
            }
            
            
        }
    }
   
}