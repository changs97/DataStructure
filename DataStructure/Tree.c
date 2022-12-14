#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// Ʈ�� ��� ����ü
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// Ʈ�� ��� ����
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

// ���� ��ȸ
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // ���ʼ���Ʈ�� ��ȸ
		printf("%d", root->data); // ��� �湮
		inorder(root->right); // �����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
preorder(TreeNode* root) {
	if (root) {
		printf("%d", root->data); // ��� �湮
		preorder(root->left); // ���ʼ���Ʈ�� ��ȸ
		preorder(root->right); // �����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left); // ���� ���� Ʈ�� ��ȸ
		postorder(root->right); // ������ ���� Ʈ�� ��ȸ
		printf("%d", root->data); // ��� �湮
	}
}



void main()
{
	// ��ȸ
	printf("���� ��ȸ=");
	inorder(root);
	printf("\n");
	printf("���� ��ȸ=");
	preorder(root);
	printf("\n");
	printf("���� ��ȸ=");
	postorder(root);
	printf("\n");


	// ���� Ʈ�� ��ũ ǥ����
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 10; // ù ��° ��带 �����Ѵ�.
	n1->left = n2;
	n1->right = n3;
	n2->data = 20; // �� ��° ��带 �����Ѵ�.
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30; // �� ��° ��带 �����Ѵ�.
	n3->left = NULL;
	n3->right = NULL;
	free(n1); free(n2); free(n3);



	return 0;
}