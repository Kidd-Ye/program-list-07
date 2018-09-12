//
//  main.cpp
//  ListReverse
//
//  Created by kidd on 2018/9/12.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
#define elemType int
typedef struct LNode{
    elemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList CreateList(LinkList &L){
    LNode *s;
    L = (LinkList)malloc(sizeof(LNode)); //创建头结点
    L->next = NULL;
    for (int i = 0; i < 10; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = i+1;
        s->next = L->next;
        L->next = s;
    }
    return L;
}


LinkList Reverse_1(LinkList &L){
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p!=NULL) {
        r=p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}

LinkList Reverse_2(LinkList &L){
    LNode *pre, *p=L->next, *r = p->next;
    p->next = NULL;
    while (r!=NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}

void Print(LinkList L){
    LNode *s = L->next;
    while (s != NULL) {
        printf("%d ",s->data);
        s = s->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    LinkList list;
    CreateList(list);
    Print(list);
    Reverse_1(list);
    Print(list);
    
    Reverse_2(list);
    Print(list);
    return 0;
}
