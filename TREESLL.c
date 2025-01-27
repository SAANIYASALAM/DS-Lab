#include <stdio.h>
#include <stdlib.h>
		struct TreeNode {
    			int data;
    			struct TreeNode* left;
    			struct TreeNode* right;
		};
		
		struct TreeNode* createNode(int data) {
    				struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    			newNode->data = data;
    			newNode->left = newNode->right = NULL;
    			return newNode;
		}

		struct TreeNode* insertNode(struct TreeNode* root, int data) {
    			if (root == NULL) {
       		 return createNode(data);
    			}
    			if (data < root->data) 
        			root->left = insertNode(root->left, data);
    		 		else if (data > root->data) {
        				root->right = insertNode(root->right, data);
    				}
   	 			return root;
		}
		struct TreeNode* findMin(struct TreeNode* node) {
    			while (node->left != NULL) {
        		node = node->left;
    			}
    			return node;
		}
		struct TreeNode* findMax(struct TreeNode* node)
		{
		    while(node->right!=NULL)
		        node=node->right;
		    return node;
		}
		struct TreeNode* search(struct TreeNode* root,int key)
		{
		    if(root==NULL || root->data==key)
		        return root;
		        else
		        {
		            if(key<root->data)
		                return search(root->left,key);
		            else
		                return search(root->right,key);
		        }
		}
		struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    			if (root == NULL) {
        			return root;
    			}
				if (key < root->data) {
        			root->left = deleteNode(root->left, key);
    			}		 
			else if (key > root->data) {
        			root->right = deleteNode(root->right, key);
    			}
			 else {
        			if (root->left == NULL) {
            				struct TreeNode* temp = root->right;
            				free(root);
            				return temp;
        			}
				 else if (root->right == NULL) {
            				struct TreeNode* temp = root->left;
            				free(root);
            				return temp;
        			}
        			struct TreeNode* temp = findMin(root->right);
        			root->data = temp->data;
        			root->right = deleteNode(root->right, temp->data);}

    			return root;
		}
		void inorderTraversal(struct TreeNode* root) {
    			if (root != NULL) {
        		inorderTraversal(root->left);
        		printf("%d ", root->data);
        		inorderTraversal(root->right);
    			}
		}
		void preorderTraversal(struct TreeNode* root) {
    		if (root != NULL) {
        		printf("%d ", root->data);
        		preorderTraversal(root->left);
        		preorderTraversal(root->right);
    		}
		}
		void postorderTraversal(struct TreeNode* root) {
    			if (root != NULL) {
        			postorderTraversal(root->left);
        			postorderTraversal(root->right);
        			printf("%d ", root->data);
    			}
		}
		int countleaf(struct TreeNode* node)
		{
		    if(node==NULL)
		        return 0;
		    if(node->left==NULL && node->right==NULL)
		        return 1;
		    return countleaf(node->left) + countleaf(node->right);
		}
		int main() {
    			struct TreeNode* root = NULL,*temp=NULL;
    			int choice, data;
    			printf("\nBinary Tree Menu:\n");
    			printf("1. Insert a node\n");
    			printf("2. Delete a node\n");
    			printf("3. Display in-order traversal\n");
    			printf("4. Display pre-order traversal\n");
    			printf("5. Display post-order traversal\n");
    			printf("6. Display Max element \n");
    			printf("7. Search an element \n");
    			printf("8. No of leaf nodes \n");
    			printf("9. Exit\n");
    			do {    
     			printf("Enter your choice: ");
        			scanf("%d", &choice);
        			switch (choice) {
        	    			case 1:
                				printf("Enter the data for the new node: ");
                				scanf("%d", &data);
                				root = insertNode(root, data);
								break;
            				case 2:
                				printf("Enter the data of node to delete: ");
                				scanf("%d", &data);
                				root = deleteNode(root, data);
                				break;
            				case 3:
                				printf("In-order Traversal: ");
                				inorderTraversal(root);
                				printf("\n");
                				break;
            				case 4:
                				printf("Pre-order Traversal: ");
                				preorderTraversal(root);
                				printf("\n");
                				break;
            				case 5:
                				printf("Post-order Traversal: ");
                				postorderTraversal(root);
                				printf("\n");
                				break;
            			
                			case 6:printf("Maximum element :%d ",findMax(root)->data);
                			        
                			        break;
                			case 7:printf("Enter element to be searched : ");
                			        scanf("%d",&data);
                			        temp=search(root,data);
                			        if(temp==NULL)
                			            printf("Element not found");
                			        else
                			            printf("Element is found");
                			         break;
                			 case 8:printf("No of leaf nodes : %d",countleaf(root));
                			        printf("\n");
                			        break;
                		   	 case 9:
                				    printf("Program exited.\n");
                			    	break;
            				default:
                			printf("Invalid choice. Please enter a valid option.\n");
        			}
    			} while (choice != 10);
    			/*while (root != NULL) {
       			 struct TreeNode* temp = root;
        			root = root->right;
        			free(temp);
    			}*/
				return 0;
		}