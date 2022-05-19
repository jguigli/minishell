// #include "../../includes/minishell.h"

// t_treenode	*create_node(t_datas *gr_linkl)
// {
// 	t_treenode *tree;

// 	tree = malloc(sizeof(t_treenode));
// 	if (!tree)
// 		return (NULL);
// 	tree->info = gr_linkl;
// 	tree->left = NULL;
// 	tree->right = NULL;
// 	return (tree);
// }

// t_queue	*create_queue()  
// {  
//     t_queue	*newQueue = (t_queue*) malloc(sizeof( t_queue ));  
   
//     newQueue->front = -1;  
//     newQueue->rear = 0;  
//     newQueue->size = 0;  
//     newQueue->arr = (t_treenode**) malloc(100 * sizeof(t_treenode*));  
//     return newQueue;  
// }  

// //Adds a node to queue  
// void enqueue(t_queue *queue, t_treenode *temp){
//     queue->arr[queue->rear++] = temp;  
//     queue->size++;  
// }  
   
// //Deletes a node from queue  
// t_treenode *dequeue(t_queue* queue){  
//     queue->size--;  
//     return queue->arr[++queue->front];  
// } 

// //insertNode() will add new node to the binary tree  
// t_treenode *insertNode(t_datas *list, t_treenode *root) {  
//     //Create a new node  
//     //printf("TEST1\n");
// 	t_treenode *newNode = create_node(list);
// 	//printf("%s\n", newNode->info->data);
//     //Check whether tree is empty  
//     if(root == NULL){ 
//         root = newNode;  
//         return (newNode);  
//     }  
//     else 
// 	{  
//         //Queue will be used to keep track of nodes of tree level-wise  
//         t_queue	*queue = create_queue();  
//         //Add root to the queue  
//         enqueue(queue, root);
//         while(1) 
// 		{  
//             t_treenode *node = dequeue(queue);  
//             //If node has both left and right child, add both the child to queue  
//             if(node->left != NULL && node->right != NULL) {  
//                 enqueue(queue, node->left);  
//                 enqueue(queue, node->right);  
//             }  
//             else {  
//                 //If node has no left child, make newNode as left child  
//                 if(node->left == NULL) {  
//                     node->left = newNode;  
//                     enqueue(queue, node->left);  
//                 }  
//                 //If node has left child but no right child, make newNode as right child  
//                 else {  
//                     node->right = newNode;  
//                     enqueue(queue, node->right);  
//                 }  
//                 break;  
//             }  
//         }  
//     }
// 	return (newNode);
// }

// void inorderTraversal(t_treenode *node) 
// {  
//     //Check whether tree is empty  
//     if(node == NULL){  
//         printf("Tree is empty\n");  
//         return;  
//     }  
//     else {  
            
//         if(node->left != NULL)  
//             inorderTraversal(node->left);  
//         printf("%s\n", node->info->data);  
//         if(node->right != NULL)  
//             inorderTraversal(node->right);  
                
//         }  
// }  

// t_treenode *bst(t_dblist *list)
// {
// 	t_treenode *root;
	
// 	root = NULL;
// 	root = insertNode(list->first, root);
// 	list->first = list->first->next;
// 	insertNode(list->first, root);
// 	//printf("TEST2\n");
// 	//printf("%s\n", root->left->my_list->first->data);
// 	inorderTraversal(root);
// 	//printf("TEST3\n");
// 	return (root);
// }