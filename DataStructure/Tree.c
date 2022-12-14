#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// 트리 노드 구조체
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// 트리 노드 생성
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

// 중위 순회
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // 왼쪽서브트리 순회
		printf("%d", root->data); // 노드 방문
		inorder(root->right); // 오른쪽서브트리 순회
	}
}

// 전위 순회
preorder(TreeNode* root) {
	if (root) {
		printf("%d", root->data); // 노드 방문
		preorder(root->left); // 왼쪽서브트리 순회
		preorder(root->right); // 오른쪽서브트리 순회
	}
}

// 후위 순회
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left); // 왼쪽 서브 트리 순회
		postorder(root->right); // 오른쪽 서브 트리 순회
		printf("%d", root->data); // 노드 방문
	}
}



void main()
{
	// 순회
	printf("중위 순회=");
	inorder(root);
	printf("\n");
	printf("전위 순회=");
	preorder(root);
	printf("\n");
	printf("후위 순회=");
	postorder(root);
	printf("\n");


	// 이진 트리 링크 표현법
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 10; // 첫 번째 노드를 설정한다.
	n1->left = n2;
	n1->right = n3;
	n2->data = 20; // 두 번째 노드를 설정한다.
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30; // 세 번째 노드를 설정한다.
	n3->left = NULL;
	n3->right = NULL;
	free(n1); free(n2); free(n3);



	return 0;
}