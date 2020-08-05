#include<stdio.h>
#include<stdlib.h>


typedef char ElemType;
//Link表示指向左右孩子，Thread表示前驱后继
typedef enum{Link,Thread} PointerTag;

typedef struct BiThrNode{
    char data;
    struct BiThrNode *left,*right;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode,*BiThrTree;

BiThrTree pre;//全局变量，表示访问前驱

//创建线索二叉树,前序创建
void createBiThrTree(BiThrTree *root){
    char c;
    scanf("%c",&c);
    if('#'==c){
        *root=NULL;
    }else{
        *root=(BiThrTree)malloc(sizeof(BiThrNode));
        (*root)->data=c;
        (*root)->ltag=Link;
        (*root)->rtag=Link;

        createBiThrTree(&(*root)->left);
        createBiThrTree(&(*root)->right);
    }
}
//中序遍历线索化
void InThreading(BiThrTree T){
    if(T){
        InThreading(T->left);

        if(T->left==NULL){
            T->ltag=Thread;
            T->left=pre;
        }
        if(pre->right==NULL){
            pre->rtag=Thread;
            pre->right=T;
        }
        pre=T;

        InThreading(T->right);
    }
}
void InOrderThreading(BiThrTree *p,BiThrTree T){ //p为头指针
    *p=(BiThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag=Link;
    (*p)->rtag=Thread;
    (*p)->right=*p;
    if(!T){
        (*p)->left=*p;
    }else{
        (*p)->left=T;
        pre=*p;
        InThreading(T);
        pre->right=*p;
        pre->rtag=Thread;
        (*p)->right=pre;
    }
}
void visit(ElemType e){
    printf("%c ",e);
}
//利用线索二叉树迭代中序遍历
void InOrderTraverse(BiThrTree T){
    BiThrTree p=T->left;
    while(p!=T){
        while(p->ltag==Link) p=p->left;
        visit(p->data);
        while(p->rtag==Thread && p->right!=T){
            p=p->right;
            visit(p->data);
        }
        p=p->right;
    }
}

int main()
{
    BiThrTree T,p;
    createBiThrTree(&T);
    InOrderThreading(&p,T);
    InOrderTraverse(p);
    return 0;
}