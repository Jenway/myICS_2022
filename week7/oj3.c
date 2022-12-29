// mergesort
// Created by yasunaka on 2018/11/06.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

typedef struct {
    char name[11];
    int score;
} Student;

Student students[MAX];  // 全体の配列 
Student tmp[MAX];       // 作業用配列

// マージ
void merge(int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid;
    k = left;
    while (i < mid && j < right) {
        if (students[i].score <= students[j].score) {
            tmp[k++] = students[i++];
        } else {
            tmp[k++] = students[j++];
        }
    }
    while (i < mid) {
        tmp[k++] = students[i++];
    }
    while (j < right) {
        tmp[k++] = students[j++];
    }
    for (i = left; i < right; i++) {
        students[i] = tmp[i];
    }
}

// マージソート
void mergesort(int left, int right) {
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid, right);
        merge(left, mid, right);
    }
}

int main(void) {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }
    mergesort(0, n); // マージソート
    for (i = 0; i < n; i++) {
        printf("%s %d", students[i].name, students[i].score);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}